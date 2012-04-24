#include "lifebar.h"

LifeBar::LifeBar(int life):life(life)
{
}


QRectF LifeBar::boundingRect() const
{
    return QRectF(125,5,250,10);
}

void LifeBar::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setPen(Qt::black);

    painter->setBrush(Qt::red);
    painter->drawRect(125,5,250,10);

    painter->setBrush(Qt::green);
    painter->drawRect(125,5,life,10);
}
