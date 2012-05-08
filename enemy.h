#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsItem>
#include <QPainter>
#include <QStyleOption>
#include <QVector2D>
#include <iostream>
#include "deathstar.h"
#include "movingobject.h"
#include "arena.h"
#include "explosion.h"
#include "target.h"

static const double Pi = 3.14159265358979323846264338327950288419717;

//class Arena;

class Enemy: public MovingObject
{
public:
    Enemy();
    ~Enemy()
    {
        target=NULL;
    }

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);

    QRectF boundingRect() const;
    void setBoundingRect(QRectF);

    void hit(double damage);

    inline double getLife()
    {
        return life;
    }

    inline void setTarget(Target* star)
    {
        target=star;
    }
    void control();
    bool death;


    virtual void weaponFire();
    virtual bool isCollide(int x, int y);
    bool inRange();
    bool fire;
    int weapon1state;
    QVector2D direction;


protected:
    double life;
    double armor;

    Target* target;
    QRectF m_boundingRect;
};




class Xwing : public Enemy
{
public:
    Xwing();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);

    void weaponFire();

};

#endif // ENEMY_H
