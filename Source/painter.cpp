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
    // 5 pixels = 1 meter
    image_scale = 10;
    nstates = 2;
}

void Painter::setOrigin(QSize origin){
    origin_x = origin.width()/2;
    origin_y = origin.height()/2;
}

void Painter::setPath(QString output_path){
    path = output_path;
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
    float small_circle = 1;
    double drawing_scale = scale*image_scale;

    // Open file
    QFile file(path);
    qDebug() << path;

    // If it failed to open
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return false;

    QTextStream in(&file);
    // Read from file, one line at a time
    while(!in.atEnd()){
        QString line = in.readLine();
        qDebug() << "Read from file: " << line;

        // Numbers are separated by spaces, split them up
        QStringList numbers = line.split(" ");

        if(numbers.size() != nstates+nstates*nstates){
            qDebug() << "What was read from the file is in incorrect format!";
            continue;
        }
        float x = numbers.at(0).toFloat();
        float y = numbers.at(1).toFloat();
        qDebug() << "x: " << x << "y: " << y;
        float P11 = numbers.at(2).toFloat();
        float P12 = numbers.at(3).toFloat();
        float P21 = numbers.at(4).toFloat();
        float P22 = numbers.at(5).toFloat();

        painter->setBrush(Qt::red);
        // Draw circle for position
        QRect pos = QRect(drawing_scale*(x-small_circle/2), -drawing_scale*(y+small_circle/2)
                          , drawing_scale*small_circle, drawing_scale*small_circle);
        qDebug() << "pos.x; " << pos.x() << "pos.y: " << pos.y() << "pos width: " << pos.width() << "pos height: " << pos.height();
        painter->drawEllipse(pos);

        // Draw circle for uncertainty
        QRect P = QRect(drawing_scale*(x-2*qSqrt(P11)/2), -drawing_scale*(y+2*qSqrt(P22)/2)
                        , 2*drawing_scale*qSqrt(P11), 2*drawing_scale*qSqrt(P22));
        qDebug() << "P.x; " << P.x() << "P.y: " << P.y() << "P width: " << P.width() << "P height: " << P.height();

        painter->setBrush(QColor(0,0,255, 0));
        painter->drawEllipse(P);
    }

    // Draw scale
    int offset = 10;
    painter->translate(image_translation.x(), image_translation.y());
    painter->save();
    // Draw line representing 5 meters
    QLine real_scale = QLine(-origin_x+offset, origin_y-offset,
                             -origin_x+10*(drawing_scale)+offset,origin_y-offset);
    qDebug() << "p1: " << real_scale.p1() << "p2: " << real_scale.p2();
    painter->drawLine(real_scale);
    painter->drawText(QPoint(-origin_x+2*offset, origin_y-offset*1.5), "1 m");
    qDebug() << "Return true";
    return true;
}
