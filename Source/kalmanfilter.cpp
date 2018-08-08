#include "kalmanfilter.h"
#include <QDebug>
#include <QFile>

KalmanFilter::KalmanFilter(QString motion_m, QString sensor_m, double T, double R, double Q)
{
    qDebug() << "EKF constructor";
    dim = 2;
    Ts = T;
    g = 9.82;

    motion_model = motion_m;
    sensor_model = sensor_m;

    if(motion_model == "CV"){
        qDebug() << "Constant Velocity";
        // Constant velocity model in 2 dimensions
        states = 2*dim;
        // Set F to a states x states array
        Eigen::MatrixXd model(states,states);

        model << 1, 0, Ts, 0,
                0, 1, 0, Ts,
                0, 0, 1, 0,
                0, 0, 0, 1;

        F = model;

    }else if(motion_model == "CA"){
        // Constant acceleration model in 2 dimensions
        states = 3*dim;
        // Set F to a states x states array
        qDebug() << "Constant Acceleration";
        // Set F to a states x states array
        Eigen::MatrixXd model(states,states);

        model << 1, 0, T, 0, T*T/2, 0,
                0, 1, 0, T, 0, T*T/2,
                0, 0, 0, 0, 1, 0,
                0, 0, 0, 0, 0, 1,
                0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0;

        F = model;
    }

    if(sensor_model == "accel"){
        // Set H
        nmeas = 2;
        Eigen::MatrixXd sens(nmeas, states);

        if(motion_model == "CA"){
            sens << 0, 0, 0, 0, g, 0,
                    0, 0, 0, 0, 0, g; // Measures a_x and a_y, converting to m/s^2
        }

        H = sens;
        Eigen::Vector2d meas_noise;
        meas_noise << R, R;
        Rk = meas_noise;
    }

    // Initialize
    initialiseEstimates(Q);

    k = 0;
}

void KalmanFilter::initialiseEstimates(double Q){
//    std::vector<double> state_vector(states);
//    std::vector<std::vector<double>> cov_mat(states, std::vector<double>(states));
    Eigen::MatrixXd state_vector(states, 1);
    Eigen::MatrixXd cov_mat(states,states);

    if(motion_model == "CV"){
        if(dim == 2){
            state_vector << 0, 0, 0, 0;
            cov_mat << 1, 0, 0, 0,
                       0, 1, 0, 0,
                       0, 0, 1, 0,
                       0, 0, 0, 1;
        }else{
            state_vector << 0, 0, 0, 0, 0, 0;
            cov_mat << 1, 0, 0, 0, 0, 0,
                       0, 1, 0, 0, 0, 0,
                       0, 0, 1, 0, 0, 0,
                       0, 0, 0, 1, 0, 0,
                       0, 0, 0, 0, 1, 0,
                       0, 0, 0, 0, 0, 1;
        }
    }else if(motion_model == "CA"){
        if(dim == 2){
            state_vector << 0, 0, 0, 0, 0, 0;
            cov_mat << 1, 0, 0, 0, 0, 0,
                       0, 1, 0, 0, 0, 0,
                       0, 0, 1, 0, 0, 0,
                       0, 0, 0, 1, 0, 0,
                       0, 0, 0, 0, 10, 0,
                       0, 0, 0, 0, 0, 10;
        }else{
            state_vector << 0, 0, 0, 0, 0, 0, 0, 0, 0;
            cov_mat << 1, 0, 0, 0, 0, 0, 0, 0, 0,
                       0, 1, 0, 0, 0, 0, 0, 0, 0,
                       0, 0, 1, 0, 0, 0, 0, 0, 0,
                       0, 0, 0, 1, 0, 0, 0, 0, 0,
                       0, 0, 0, 0, 1, 0, 0, 0, 0,
                       0, 0, 0, 0, 0, 1, 0, 0, 0,
                       0, 0, 0, 0, 0, 0, 10, 0, 0,
                       0, 0, 0, 0, 0, 0, 0, 10, 0,
                       0, 0, 0, 0, 0, 0, 0, 0, 10;
        }
    }

    xhat_k = state_vector;
    x_pred = state_vector;
    phat_k = cov_mat;
    p_pred = cov_mat;
    Qk = cov_mat;

    for(unsigned int i = 0; i < states; i++){
        for(unsigned int j = 0; j < states; j++){
            if(i == j){
                Qk(i,j) = Q;
            }
        }
    }
}

// Börja felsök här
void KalmanFilter::measurementUpdate(){
    // Linear Kalman Filter
    if((motion_model == "CV" || motion_model == "CA") && sensor_model == "accel"){
        // Open measurement file
        QFile meas_file(measurement_path);
        // Open file to save estimates in
        QFile est_file(estimates_path);
        // Open file to save estimates in
        QFile cov_file(covariance_path);

        // If it failed to open
        if (!meas_file.open(QIODevice::ReadOnly | QIODevice::Text))
            return;

        if(k == 0){
            if(!est_file.open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Truncate))
                return;
        }else{
            if(!est_file.open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Append))
                return;
        }

        if(k == 0){
            if(!cov_file.open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Truncate))
                return;
        }else{
            if(!cov_file.open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Append))
                return;
        }

        QTextStream in(&meas_file);
        QTextStream est_out(&est_file);
        QTextStream cov_out(&cov_file);

        while(!in.atEnd()){
            // Read one line at a time
            QString line = in.readLine();
            qDebug() << "Read from file: " << line;

            QStringList measurements = line.split(" ");

            // Create vector with measurements
//            std::vector<double> meas(dim);
            Eigen::MatrixXd meas(1,dim);

            if(dim == 2){
                double a_x = measurements.at(0).toDouble();
                double a_y = measurements.at(1).toDouble();

                meas << a_x, a_y;
            }else{
                double a_x = measurements.at(0).toDouble();
                double a_y = measurements.at(1).toDouble();
                double a_z = measurements.at(2).toDouble();

                meas << a_x, a_y, a_z;
            }

            // Calculate Sk
            Eigen::MatrixXd Sk(nmeas, nmeas);
            Sk = Rk + H*p_pred*H.transpose();
            // Kalman gain
            Eigen::MatrixXd Kk(states, nmeas);
            Kk = p_pred*H.transpose()*Sk.inverse();
            // Error
            Eigen::MatrixXd eps_k(1, dim);
            eps_k = meas - H*x_pred;
            // Update
            xhat_k = x_pred + Kk*eps_k;
            phat_k = p_pred - p_pred*H.transpose()*Sk.inverse()*H*p_pred;

            k++;

            // Write estimates and covariance matrix to files
            writeEstimate(est_out);
            writeCovariance(cov_out);
        }
    }
}

void KalmanFilter::timeUpdate(){

}

void KalmanFilter::setCovPath(QString path){
    covariance_path = path;
}

void KalmanFilter::setMeasPath(QString path){
    measurement_path = path;
}

void KalmanFilter::setEstPath(QString path){
    estimates_path = path;
}

void KalmanFilter::writeEstimate(QTextStream &out){
    QString data;
    for(unsigned int i = 0; i < states; i++){
        double x = xhat_k(i,0);
        data += QString::number(x) + " ";
    }

    out << data << endl;
}
void KalmanFilter::writeCovariance(QTextStream &out){
    for(unsigned int j = 0; j < states; j++){
        QString data;
        for(unsigned int i = 0; i < states; i++){
            double x = xhat_k(i,j);
            data += QString::number(x) + " ";
        }

        out << data << endl;
    }
}
