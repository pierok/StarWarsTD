#include "lifebar.h"
#include "math.h"
#include <iostream>

LifeBar::LifeBar(int life,int size):life(life),size(size)
{
    sizeLife=(double)life/size;
}

QRectF LifeBar::boundingRect() const
{
    return QRectF(125,5,250,10);
}

void LifeBar::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setPen(Qt::black);

    painter->setBrush(Qt::red);
    painter->drawRect(125,5,size,10);

    painter->setBrush(Qt::green);
    painter->drawRect(125,5,(life/sizeLife),10);
}

