#ifndef DEATHSTAR_H
#define DEATHSTAR_H

#include <QGraphicsItem>
#include <QPainter>
#include <QStyleOption>
#include "target.h"
#include "lifebar.h"


class DeathStar: public Target
{
public:
    DeathStar();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);

    QRectF boundingRect() const;
    void setBoundingRect(QRectF);

    void step();
    void hit(double i);
    void heal(double i);

    inline void setLifeBar(LifeBar *l)
    {
        lifebar=l;
    }

    inline void showLifeBar()
    {
        lifebar->updateLife(life);
        lifebar->show();
    }

    inline LifeBar* getLifeBar()
    {
        return lifebar;
    }

    bool deactive;
    double life;

protected:

    LifeBar* lifebar;
    QRectF m_boundingRect;
};

#endif // DEATHSTAR_H
