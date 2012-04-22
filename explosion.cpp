#include "explosion.h"
#include <math.h>

Explosion::Explosion()
{
    size = 50;
    lifemax = 50;
    lifetimer = lifemax;
}

Explosion::Explosion(int size)
{
    this->size = size;
    lifemax = size;
    lifetimer = lifemax;
}

void Explosion::control()
{
    lifetimer--;
    if(!lifetimer)
    {
        //Window::kill.enqueue(this);
    }
}

void Explosion::physics()
{
    ;
}

void Explosion::step()
{
    ;
}

void Explosion::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setPen(Qt::NoPen);
    qreal currentsize = size*(lifemax-lifetimer)/(lifemax); // bie¿¹ca wielkoœæ kuli ognia
    QRadialGradient *grad = new QRadialGradient(0,0,currentsize);
    int vanish = (255*lifetimer)/lifemax; // zanik barw i kana³u alfa, od 255 do 0
    grad->setColorAt(0,QColor(255,vanish,0,vanish));
    grad->setColorAt(1,QColor(0,0,0,0));
    QBrush brush(*grad);
    painter->setBrush(brush);
    painter->drawEllipse(-currentsize,-currentsize,currentsize*2,currentsize*2);

    if(size>25)
    {
        // pomocnicza zmienna wplywajaca na rozmiar fali uderzeniowej zaleznie od jej wieku:
        qreal wave = 2*(lifemax-lifetimer)-7*sqrt(lifemax-lifetimer);
        qreal alfa1, alfa2; // wartosci przezroczystosci fali uderzeniowej w kluczowych punktach

        if ((lifetimer) > 30)
        {
            alfa1=150;
            alfa2 = 30;
        }
        // fala zanika tylko gdy jej lifetimer siê koñczy:
        else
        {
            alfa1 = 5*lifetimer;
            alfa2 = lifetimer;
        }
        painter->setPen(Qt::NoPen);
        QRadialGradient radialGrad(QPointF(0,0), wave, QPointF(0,0));
        radialGrad.setColorAt(0.0, QColor(0,0,0,0));
        radialGrad.setColorAt(0.7, QColor(180,180,180,0));
        radialGrad.setColorAt(0.9, QColor(180,180,180,alfa1));
        radialGrad.setColorAt(1, QColor(180,180,180,alfa2));
        painter->setBrush(radialGrad);
        painter->drawEllipse(-wave,-wave, 2*wave, 2*wave);
    }
}
