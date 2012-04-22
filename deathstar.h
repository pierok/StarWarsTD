#ifndef DEATHSTAR_H
#define DEATHSTAR_H

#include <QGraphicsItem>
#include <QPainter>
#include <QStyleOption>

class DeathStar: public QGraphicsItem
{
public:
    DeathStar();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);

    QRectF boundingRect() const;
    void setBoundingRect(QRectF);

    void step();

protected:
    double life;
    QRectF m_boundingRect;
};

#endif // DEATHSTAR_H
