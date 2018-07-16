#ifndef PAINTER_H
#define PAINTER_H

#include <QPainter>
#include <QPaintEvent>

class Painter
{
public:
    Painter();

public:
    void paint(QPainter *painter, QPaintEvent *event, int elapsed, int origin_x, int origin_y, double scale, QPoint translation);

private:
    QBrush background;
    QBrush circleBrush;
    QFont textFont;
    QPen circlePen;
    QPen textPen;
};
#endif // PAINTER_H
