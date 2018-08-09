#ifndef PAINTER_H
#define PAINTER_H

#include <QPainter>
#include <QPaintEvent>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QFileSystemWatcher>
#include <QWidget>

class Painter
{
public:
    Painter();

public:
    void paint(QPainter *painter, QPaintEvent *event, int elapsed,
               double scale, QPoint translation, bool draw_position);
    bool drawPositions(QPainter *painter, double scale);
    void setOrigin(QSize origin);
    void setEstPath(QString path);
    void setCovPath(QString path);
    int getImageScale();
    void setStates(unsigned long states);

public slots:
    void resetZoom();
    void resetTranslation();
    void translateMap(QPoint pos);

private:
    QBrush background;
    QBrush circleBrush;
    QFont textFont;
    QPen circlePen;
    QPen textPen;
    QGraphicsEffect *graphics;
    int origin_x;
    int origin_y;
    int image_scale;
    QString est_path;
    QString cov_path;
    unsigned long nstates;
    QPoint image_translation;

};
#endif // PAINTER_H
