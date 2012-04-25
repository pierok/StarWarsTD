#ifndef MISSILE_H
#define MISSILE_H

#include <QPoint>
#include <QVector2D>
#include <QPainter>
#include <QStyleOption>
#include <QPen>
#include <QColor>
#include "movingobject.h"
#include "arena.h"


class Missile :  public MovingObject
{
public:
    Missile();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);
    int lifetimer;
    bool deactive;
    void reset();
    void control();
    void step();
    QVector2D velocity;

    inline void setTarget(DeathStar* d)
    {
        target=d;
    }

private:
    DeathStar* target;
};


class Prism : public QGraphicsItem
{
public:
    Prism();
    QRectF boundingRect() const;
    void setBoundingRect(QRectF);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);

    int lifetimer;

    inline void setTarget(QPoint p)
    {
        target=p;
    }

    inline void setSource(QPoint s)
    {
        source=s;
    }

    void control()
    {
        if(lifetimer>0)
        {
            lifetimer--;
        }else{
            this->hide();
        }
    }

    void reset();
private:
    QPoint target;
    QPoint source;

};


#endif // MISSILE_H
