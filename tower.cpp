#include "tower.h"

Tower::Tower()
{
     m_boundingRect=QRectF(0,0,20,20);
     radius=0;
     damage=0;
     cost=0;
}

void Tower::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
     painter->setPen(QPen(Qt::black));
     painter->setBrush(Qt::white);
     painter->drawRect(0,0,20,20);
}

QRectF Tower::boundingRect() const
{
    return m_boundingRect;
}

void Tower::setBoundingRect(QRectF rect)
{
    m_boundingRect=rect;
}



void Tower::physics()
{
    if((speed >= 0.025) || (speed <= -0.025))
    {
        speed = speed * friction;
    }
    else
    {
        speed = 0;
    }
    if((rot >= 0.025) || (rot <= -0.025))
    {
        rot = rot * rotfriction;
    }
    else
    {
        rot = 0;
    }
    if(rot!=0)
    {
        speed += rot*slide*0.01;
        slide -= rot*speed*0.01;
    }
    if((slide >= 0.025) || (slide <= -0.025))
    {
        slide = slide * slidefriction;
    }
    else
    {
        slide = 0;
    }
}

void Tower::step()
{
    rotate(-rot);
    angle-=rot;
    if(angle<0) angle+=360;
    if(angle>360) angle-=360;
    translate(0,-speed);
    translate(-slide,0);
}

