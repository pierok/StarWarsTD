#ifndef TOWER_H
#define TOWER_H

#include <QGraphicsItem>
#include <QPainter>
#include <QStyleOption>

#include "arena.h"
//#include "enemy.h"
class Enemy;

class Tower: public QGraphicsItem
{
public:
    Tower();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);

    QRectF boundingRect() const;
    void setBoundingRect(QRectF);

    virtual void control()=0;
    void step();
    virtual bool inRange(Enemy *)=0;

    inline void setRadius(int r)
    {
        radius=r;
    }
    inline void setDamage(int d)
    {
        damage=d;
    }
    inline void setCost(int c)
    {
        cost=c;
    }

protected:
    Enemy* enemy;
    double radius;
    double damage;
    double cost;
    QRectF m_boundingRect;

};

#endif // TOWER_H
