#ifndef TOWER_H
#define TOWER_H

#include <QGraphicsItem>
#include <QPainter>
#include <QStyleOption>

class Tower: public QGraphicsItem
{
public:
    Tower();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);

    QRectF boundingRect() const;
    void setBoundingRect(QRectF);

protected:
    double radius;
    double damage;
    double cost;
    QRectF m_boundingRect;

};

#endif // TOWER_H
