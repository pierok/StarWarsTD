#ifndef GENERATOR_H
#define GENERATOR_H


#include <QGraphicsItem>
#include <QPainter>
#include <QStyleOption>
#include "target.h"
#include "lifebar.h"

class Generator: public Target
{
public:
    Generator();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);

    QRectF boundingRect() const;
    void setBoundingRect(QRectF);

    void step();
    void hit(double i);

    inline void setLifeBar(LifeBar *l)
    {
        lifebar=l;
    }

    inline void showLifeBar()
    {
        lifebar->updateLife(life);
        lifebar->show();
    }



    double life;

protected:

    LifeBar* lifebar;
    QRectF m_boundingRect;
};

#endif // GENERATOR_H
