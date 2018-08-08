#ifndef KALMANFILTER_H
#define KALMANFILTER_H

#include <vector>
#include <QString>
#include <QDebug>
#include <QFile>
#include <Eigen/Dense>

class KalmanFilter
{
public:
    KalmanFilter() = default;
    KalmanFilter(QString motion_model, QString sensor_model, double T, double R, double Q);
    ~KalmanFilter() = default;

    void initialiseEstimates(double Q);
    void measurementUpdate();
    void timeUpdate();

    void setMeasPath(QString path);
    void setEstPath(QString path);
    void setCovPath(QString path);

    void writeEstimate(QTextStream &out);
    void writeCovariance(QTextStream &out);

private:
    // States and covmat for time k
    Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> xhat_k;
    Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> phat_k;

    // States and covmat for time k+1    
    Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> x_pred;
    Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> p_pred;

    // Hessians for sensor and motion model
    Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> F;
    Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> H;
    Eigen::Matrix<double, Eigen::Dynamic, 1> Rk;
    Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> Qk;

    unsigned long states; // Initialising vectors with signed int is not appreciated
    unsigned long dim;
    int nmeas;
    int k;
    double Ts;
    double g;
    QString motion_model;
    QString sensor_model;

    QString measurement_path;
    QString estimates_path;
    QString covariance_path;
};

#endif // KALMANFILTER_H
