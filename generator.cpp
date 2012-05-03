#include "generator.h"


Generator::Generator()
{
    m_boundingRect=QRectF(-240/4,-180/4,480/4,360/4);
    life=1000;
    deactive=false;
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
    //lifebar->updateLife(lifebar->life-1);
}

QRectF Generator::boundingRect() const
{
    return m_boundingRect;
}

void Generator::setBoundingRect(QRectF rect)
{
    m_boundingRect=rect;
}
