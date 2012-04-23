#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsItem>
#include <QPainter>
#include <QStyleOption>
#include <iostream>
#include "deathstar.h"
#include "movingobject.h"

static const double Pi = 3.14159265358979323846264338327950288419717;

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

    inline void hit(double damage)
    {
        life-=damage;
        if(life<=0)
        {
            death=true;
            this->hide();
        }
    }

    inline double getLife()
    {
        return life;
    }

    inline void setTarget(DeathStar* star)
    {
        target=star;
    }
    void control();
    bool death;

protected:
    double life;
    double armor;

    DeathStar* target;

    QRectF m_boundingRect;
};

#endif // ENEMY_H
