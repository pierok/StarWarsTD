#include "deathstar.h"

DeathStar::DeathStar()
{
    m_boundingRect=QRectF(-145,-145,290,290);
    life=1000;
    deactive=false;
}

void DeathStar::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    QPixmap ship(":/data/DeathStartar.png");
    painter->drawPixmap(QRect(-145,-145,290,290),ship);
    //painter->setPen(Qt::white);
    //painter->drawEllipse(-145,-145,290,290);
}

void DeathStar::step()
{
    this->rotate(0.2);
    //lifebar->updateLife(lifebar->life-1);
}

QRectF DeathStar::boundingRect() const
{
    return m_boundingRect;
}

void DeathStar::setBoundingRect(QRectF rect)
{
    m_boundingRect=rect;
}




