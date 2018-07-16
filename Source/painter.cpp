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
}

void Painter::paint(QPainter *painter, QPaintEvent *event, int elapsed, int origin_x, int origin_y, double scale, QPoint translation)
{
    painter->fillRect(event->rect(), background);
    // Translate paintbrush
    painter->translate(origin_x - translation.x(), origin_y - translation.y());
    painter->save();
    painter->setBrush(circleBrush);
    painter->setPen(circlePen);
    painter->rotate(elapsed * 0.030);

    qreal r = elapsed / 1000.0;
    int n = 30;
    for (int i = 0; i < n; ++i) {
        painter->rotate(30);
        qreal factor = (i + r) / n;
        qreal radius = 0 + 120.0 * factor;
        qreal circleRadius = 1 + factor * 20;
        painter->drawEllipse(QRectF(scale*radius, -scale*circleRadius,
                                    scale*circleRadius * 2, scale*circleRadius * 2));
    }
    painter->restore();
    painter->setPen(textPen);
    painter->setFont(textFont);
//    painter->drawText(QRect(-scale*origin_x/2, -scale*origin_y/2, origin_x, origin_y), Qt::AlignCenter, QStringLiteral("Qt"));
    painter->drawRect(QRect(-scale*origin_x/2, -scale*origin_y/2, scale*origin_x, scale*origin_y));
}
