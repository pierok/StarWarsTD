#include "generator.h"


Generator::Generator()
{
    m_boundingRect=QRectF(-240/4,-180/4,480/4,360/4);
    life=250;
    deactive=false;
    radius=160;
}

void Generator::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    QPixmap ship(":/data/generator.png");
    painter->drawPixmap(QRect(-240/4,-180/4,480/4,360/4),ship);
    //painter->setPen(Qt::white);
    //painter->drawEllipse(-145,-145,290,290);
}

void Generator::step()
{
    this->rotate(0.08);
}

QRectF Generator::boundingRect() const
{
    return m_boundingRect;
}

void Generator::setBoundingRect(QRectF rect)
{
    m_boundingRect=rect;
}

void Generator::hit(double i)
{
    life-=i;
    lifebar->updateLife(life);
    if(life<=0)
    {
        lifebar->hide();
    }
}

