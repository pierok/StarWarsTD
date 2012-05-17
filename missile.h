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
#include "target.h"

enum guns {MISSILE, LASER, PLASMA};


class Missile :  public MovingObject
{
public:
    Missile();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);
    int lifetimer;
    bool deactive;
    virtual void control();
    virtual void reset();
    void setTarget(Target* d);

    inline double getDamage()
    {
        return damage;
    }
    inline int getID()
    {
        return ID;
    }

    bool isEnemy;
protected:
    double damage;
    Target* target;
    int ID;
};


class Plasma : public Missile
{
public:
    Plasma();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);
    void control();
    void reset();

};

class HLaser : public Missile
{
public:
    HLaser();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);
    void control();
    void reset();

};

class Laser : public Missile
{
public:
    Laser();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);
    void control();
    void reset();


};


class Prism : public Missile
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
        if(deactive==false)
        {
            if(lifetimer>0)
            {
                lifetimer--;
            }else{
                deactive=true;
                this->hide();
            }
        }
    }

    void reset();
private:
    QPoint target;
    QPoint source;

};


#endif // MISSILE_H
