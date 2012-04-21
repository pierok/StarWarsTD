#ifndef AREA_H
#define AREA_H


#include <QGraphicsItem>
#include <QPainter>
#include <QStyleOption>

class Area: public QGraphicsItem
{
public:
    Area(int w, int h);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);

    QRectF boundingRect() const;
    void setBoundingRect(QRectF);

private:
    int width;
    int height;
    QRectF m_boundingRect;

};

#endif // AREA_H
