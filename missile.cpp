#include "missile.h"

#include <QGraphicsScene>
#include <QPainter>
#include <QStyleOption>
#include <QPen>
#include <QColor>

Missile::Missile()
{
    angle = 0;
    speed = 0;
    slide = 0;
    rot = 0;

    friction = 0.9975;
    slidefriction = 0.96;
    rotfriction = 0.98;

    lifetimer = 100;
}

void Missile::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    QPen pen(QColor(255,50,0), 1.0, Qt::SolidLine, Qt::RoundCap);
    painter->setPen(pen);
    painter->drawLine(0, 10, 0, 0);
    QPen pen1(QColor(255,225,175), 0);
    painter->setPen(pen1);
    painter->drawLine(0, 8, 0, 0);
}

QRectF Missile::boundingRect() const
{
    return QRectF(-1,0,1,10);
}
