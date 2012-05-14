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
    bool deactive;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);

    QRectF boundingRect() const;
    void setBoundingRect(QRectF);

    virtual void control()=0;
    virtual void reset()=0;

    void physics();
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

    inline int getCost()
    {
        return cost;
    }

protected:
    Enemy* enemy;
    double radius;
    double damage;
    double cost;
    QRectF m_boundingRect;

    qreal angle;
    qreal speed;
    qreal slide;
    qreal rot;

    qreal friction;
    qreal slidefriction;
    qreal rotfriction;

    qreal acc;
    qreal brake;
    qreal slideacc;
    qreal rotacc;


};

#endif // TOWER_H
