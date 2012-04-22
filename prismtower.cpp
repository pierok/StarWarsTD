#include "prismtower.h"

PrismTower::PrismTower():Tower()
{
    radius=500;
}

void PrismTower::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
   /*  painter->setPen(Qt::NoPen);
     QRadialGradient *grad = new QRadialGradient(0,0,radius);
     grad->setColorAt(0,QColor(0,0,0,0));
     grad->setColorAt(1,QColor(80,30,255,150));
     QBrush brush(*grad);
     painter->setBrush(brush);
     painter->drawEllipse(-radius/2,-radius/2,radius,radius);*/

     QPixmap ship(":/data/PrismTower.png");
     painter->drawPixmap(QRect(-50,-50,100,100),ship);
}
