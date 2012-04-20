#include "prismtower.h"

PrismTower::PrismTower():Tower()
{
}


void PrismTower::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
     painter->setPen(QPen(Qt::black));
     painter->setBrush(Qt::gray);
     painter->drawEllipse(0,0,20,20);
}
