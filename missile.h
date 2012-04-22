#ifndef MISSILE_H
#define MISSILE_H

#include "movingobject.h"

class Missile : public MovingObject
{
public:
    Missile();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);
    int lifetimer;
};


class Prism : public Missile
{
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);
    int lifetimer;
};


#endif // MISSILE_H
