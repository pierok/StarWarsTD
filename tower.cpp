#include "tower.h"

Tower::Tower()
{
     m_boundingRect=QRectF(0,0,20,20);
     radius=0;
     damage=0;
     cost=0;
}

void Tower::step()
{
   // this->rotate(-0.5);
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
