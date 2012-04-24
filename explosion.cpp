#include "explosion.h"
#include <math.h>

Explosion::Explosion()
{
    size = 50;
    lifemax = 50;
    lifetimer = lifemax;
    deactive = false;
}

Explosion::Explosion(int size)
{
    this->size = size;
    lifemax = size;
    lifetimer = lifemax;
    deactive = false;
}



void Explosion::setSize(int size)
{
    this->size = size;
    lifemax = size;
    lifetimer = lifemax;
    deactive=false;
}


void Explosion::control()
{
    if(lifetimer>0)
    {
        lifetimer--;
    }else
    {
        deactive=true;
        Arena::destroyExplosion.enqueue(this);
        Arena::factoy.deactivateExplosion(this);
        //Window::kill.enqueue(this);
    }
}

QRectF Explosion::boundingRect() const
{
    return QRectF(-10,-10,20,20);
}

void Explosion::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setPen(Qt::NoPen);
    qreal currentsize = size*(lifemax-lifetimer)/(lifemax); // bie¿¹ca wielkoœæ kuli ognia
    QRadialGradient *grad = new QRadialGradient(0,0,currentsize);
    int vanish = (255*lifetimer)/lifemax; // zanik barw i kana³u alfa, od 255 do 0
    if(vanish>255)
    {
        vanish=255;
    }else if(vanish<0)
    {
        vanish=0;
    }
    grad->setColorAt(0,QColor(255,vanish,0,vanish));
    grad->setColorAt(1,QColor(0,0,0,0));
    QBrush brush(*grad);
    painter->setBrush(brush);
    painter->drawEllipse(-currentsize,-currentsize,currentsize*2,currentsize*2);
}
