#include "missile.h"

#include <QGraphicsScene>
#include <QPainter>
#include <QStyleOption>
#include <QPen>
#include <QColor>

#include <iostream>

Missile::Missile()
{
    deactive=false;
    lifetimer = 30;
}


void Missile::reset()
{
    deactive=false;
    lifetimer = 30;
}


void Missile::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setPen(Qt::NoPen);
    painter->setBrush(Qt::red);
    painter->drawEllipse(0,0,5,5);
}

QRectF Missile::boundingRect() const
{
    return QRectF(-1,0,1,10);
}

void Missile::control()
{
    if(lifetimer>0)
    {
        translate(0,1);
        lifetimer--;
    }else
    {
        std::cout<<"desctive"<<std::endl;
        deactive=true;
        //Arena::destroyExplosion.enqueue(this);
        Arena::factoy.deactivateMissile(this);
        //Window::kill.enqueue(this);
    }
}

Prism::Prism()
{
   // std::cout<<"Prism counstract"<<std::endl;
    lifetimer = 0;
}

void Prism::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    QLinearGradient linearGrad(source.x(), source.y(), target.x(), target.y());
    linearGrad.setColorAt(0, Qt::red);
    linearGrad.setColorAt(0.5, Qt::blue);
    linearGrad.setColorAt(1, Qt::green);

    QBrush brush(linearGrad);
    QPen pen(brush, 3.5, Qt::SolidLine, Qt::RoundCap);
    painter->setPen(pen);
    painter->drawLine(source.x(), source.y(), target.x(), target.y());
}

QRectF Prism::boundingRect() const
{
    return QRectF(source.x(), source.y(), 1, 1000);
}
