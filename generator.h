#ifndef GENERATOR_H
#define GENERATOR_H


#include <QGraphicsItem>
#include <QPainter>
#include <QStyleOption>
#include "lifebar.h"

class Generator: public QGraphicsItem
{
public:
    Generator();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);

    QRectF boundingRect() const;
    void setBoundingRect(QRectF);

    void step();
    inline void hit(double i)
    {
        life-=i;
        lifebar->updateLife(life);
        if(life<=0)
        {
            lifebar->hide();
        }
    }

    inline void setLifeBar(LifeBar *l)
    {
        lifebar=l;
    }

    bool deactive;
    double life;

protected:

    LifeBar* lifebar;
    QRectF m_boundingRect;
};

#endif // GENERATOR_H
