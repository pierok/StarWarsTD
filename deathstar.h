#ifndef DEATHSTAR_H
#define DEATHSTAR_H

#include <QGraphicsItem>
#include <QPainter>
#include <QStyleOption>
#include "lifebar.h"

class DeathStar: public QGraphicsItem
{
public:
    DeathStar();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);

    QRectF boundingRect() const;
    void setBoundingRect(QRectF);

    void step();

    inline void setLifeBar(LifeBar *l)
    {
        lifebar=l;
    }

protected:
    double life;
    LifeBar* lifebar;
    QRectF m_boundingRect;
};

#endif // DEATHSTAR_H
