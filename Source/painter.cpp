#include <QApplication>
#include <QFileSystemWatcher>
#include <QDebug>
#include <QtMath>

#include "painter.h"

Painter::Painter()
{
    QLinearGradient gradient(QPointF(50, -20), QPointF(80, 20));
    gradient.setColorAt(0.0, Qt::gray);
    gradient.setColorAt(1.0, QColor(0xa6, 0xce, 0x39));

    background = QBrush(Qt::white);
    circleBrush = QBrush(gradient);
    circlePen = QPen(Qt::black);
    circlePen.setWidth(1);
    textPen = QPen(Qt::black);
    textFont.setPixelSize(50);
    // 10 pixels = 1 meter
    image_scale = 100;
    nstates = 2;
}

void Painter::setOrigin(QSize origin){
    origin_x = origin.width()/2;
    origin_y = origin.height()/2;
}

void Painter::setEstPath(QString path){
    est_path = path;
}

void Painter::setCovPath(QString path){
    cov_path = path;
}

void Painter::setStates(unsigned long states){
    nstates = states;
}

int Painter::getImageScale(){
    return image_scale;
}

void Painter::paint(QPainter *painter, QPaintEvent *event, int elapsed, double scale, QPoint translation, bool draw_position)
{
    // image_scale is how many pixels equal 1 meter and scale is the zoom
    //    double drawing_scale = scale*image_scale;

    painter->fillRect(event->rect(), background);
    painter->translate(origin_x - translation.x(), origin_y - translation.y());
    image_translation = translation;

    // If draw_position is true, read positions from the file
    if(draw_position){
        qDebug() << "Read from file";
        bool drawing_succeded = drawPositions(painter, scale);
        if(!drawing_succeded){
            qDebug() << "Something went wrong, could not open file";
        }
        // Don't know why this has to be here, but it does.
        painter->restore();
    }
}

bool Painter::drawPositions(QPainter *painter, double scale)
{
    float small_circle = 10;
    double drawing_scale = scale*image_scale;

    // Open files
    QFile est_file(est_path);
    QFile cov_file(cov_path);

    // If it failed to open
    if (!est_file.open(QIODevice::ReadOnly | QIODevice::Text))
        return false;

    if (!cov_file.open(QIODevice::ReadOnly | QIODevice::Text))
        return false;

    QTextStream est_in(&est_file);
    QTextStream cov_in(&cov_file);

    // Read from file, one line at a time
    QString est_line;

    int line_counter = 0;
    while(est_in.readLineInto(&est_line)){

        qDebug() << "Estimates read from file: " << est_line;

        // Numbers are separated by spaces, split them up
        QStringList estimates = est_line.split(" ");

        double x = estimates.at(0).toDouble();
        double y = estimates.at(1).toDouble();
        double Pxx, Pxy, Pyx, Pyy = 0;

        QString cov_line;
        for(unsigned long i = 0; i < nstates; i++){
            if(cov_in.readLineInto(&cov_line)){
                QStringList covariance = cov_line.split(" ");
                qDebug() << "Covariance read from file: " << est_line;
                if(i == 0){
                    Pxx = covariance.at(i).toDouble();
                    Pxy = covariance.at(i+1).toDouble();
                }else if(i == 1){
                    Pyx = covariance.at(i-1).toDouble();
                    Pyy = covariance.at(i).toDouble();
                }
            }
        }

        painter->setBrush(Qt::red);
        // Draw circle for position
        QRect pos = QRect(drawing_scale*x-small_circle/2, -(drawing_scale*y+small_circle/2)
                          , small_circle, small_circle);
        qDebug() << "pos.x; " << pos.x() << "pos.y: " << pos.y() << "pos width: " << pos.width() << "pos height: " << pos.height();
        painter->drawEllipse(pos);

        // Draw circle for uncertainty
        double xp = drawing_scale*(x-2*qSqrt(Pxx)/2);
        double yp = -drawing_scale*(y+2*qSqrt(Pyy)/2);
        double x_scale = 2*drawing_scale*qSqrt(Pxx);
        double y_scale = 2*drawing_scale*qSqrt(Pyy);
        QRect P = QRect(xp, yp, x_scale, y_scale);
        qDebug() << "P.x; " << P.x() << "P.y: " << P.y() << "P width: " << P.width() << "P height: " << P.height();

        painter->setBrush(QColor(0,0,255, 0));
        painter->drawEllipse(P);
        painter->drawText(drawing_scale*x-small_circle/2+20, -(drawing_scale*y+small_circle/2), QString::number(line_counter));
        line_counter++;
    }

    // Draw scale
    int offset = 10;
    painter->translate(image_translation.x(), image_translation.y());
    painter->save();
    // Draw line representing 1 meters
    QLine real_scale = QLine(-origin_x+offset, origin_y-offset,
                             -origin_x+1*(drawing_scale)+offset,origin_y-offset);
    qDebug() << "p1: " << real_scale.p1() << "p2: " << real_scale.p2();
    painter->drawLine(real_scale);
    painter->drawText(QPoint(-origin_x+2*offset, origin_y-offset*1.5), "1 m");
    qDebug() << "Return true";
    return true;
}
