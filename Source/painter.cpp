#include <QApplication>
#include <QFileSystemWatcher>
#include <QDebug>

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
    image_scale = 5;
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
    painter->save();
    painter->setBrush(circleBrush);
    painter->setPen(circlePen);

    // If draw_position is true, read positions from the file
    if(draw_position){

        qDebug() << "Read from file";
        bool drawing_succeded = drawPositions(painter, scale);
        if(!drawing_succeded){
            qDebug() << "Something went wrong, could not open file";
        }
    }


    // Rotating circles
    //    painter->rotate(elapsed * 0.030);

    //    qreal r = elapsed / 1000.0;
    //    int n = 30;
    //    for (int i = 0; i < n; ++i) {
    //        painter->rotate(30);
    //        qreal factor = (i + r) / n;
    //        qreal radius = 0 + 120.0 * factor;
    //        qreal circleRadius = 1 + factor * 20;
    //        painter->drawEllipse(QRectF(scale*radius, -scale*circleRadius,
    //                                    scale*circleRadius * 2, scale*circleRadius * 2));
    //    }

    //    painter->restore();
    //    painter->setPen(textPen);
    //    painter->setFont(textFont);
    //    double x = -drawing_scale*origin_x/2;
    //    double y = -drawing_scale*origin_y/2;
    //    double width = drawing_scale*origin_x;
    //    double height = drawing_scale*origin_y;
    //    qDebug() << "x: " << x;
    //    qDebug() << "y: " << y;
    //    qDebug() << "Widht: " << width;
    //    qDebug() << "Height: " << height;
    //    painter->drawRect(QRect(x, y, width, height));
}

bool Painter::drawPositions(QPainter *painter, double scale)
{
    float small_circle = 5;
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
        QRect P = QRect(drawing_scale*(x-P11/2), -drawing_scale*(y+P22/2)
                        , drawing_scale*P11, drawing_scale*P22);
        qDebug() << "P.x; " << P.x() << "P.y: " << P.y() << "P width: " << P.width() << "P height: " << P.height();
        painter->setBrush(QColor(0,0,255, 0));
        painter->drawEllipse(P);
    }

//    // Draw scale
//    int offset = 10;
//    painter->translate(image_translation.x(), image_translation.y());
//    painter->save();
//    painter->drawEllipse(QRect(0,0,10,10));
//    QLine real_scale = QLine(-(origin_x/2+offset), origin_y/2+offset,
//                             -(origin_x/2+offset+10*image_scale),origin_y/2+offset);
//    qDebug() << "p1: " << real_scale.p1() << "p2: " << real_scale.p2();
//    painter->drawLine(real_scale);

    return true;
}
