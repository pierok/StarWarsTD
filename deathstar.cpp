#include "deathstar.h"

DeathStar::DeathStar()
{
    m_boundingRect=QRectF(-145,-145,290,290);
    life=1000;
    deactive=false;
    radius=200;
    ship=QPixmap(":/data/DeathStartar.png");
}

void DeathStar::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{

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

void DeathStar::hit(double i)
{
    life-=i;
    lifebar->updateLife(life);
    if(life<=0)
    {
        lifebar->hide();
    }
}

void DeathStar::heal(double i)
{

    if(life<1000)
    {
        life+=i;
        lifebar->updateLife(life);
    }
}


