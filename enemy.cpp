#include "enemy.h"
#include <QVector2D>
#include <iostream>
#include <math.h>

Enemy::Enemy()
{
    angle = 0;
    speed = 0.5;
    slide = 0;
    rot = 0;

    friction = 0.9925;
    slidefriction = 0.9850;
    rotfriction = 0.9750;

    acc = 0.07;
    slideacc = 0.12;
    brake = 0.10;
    rotacc = 0.4;

    life=200;
    armor=100;
    m_boundingRect=QRectF(-350/16,-470/16,350/8,470/8);
}

void Enemy::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    QPixmap ship(":/data/SokolMilenium.png");
    painter->drawPixmap(QRect(-350/16,-470/16,350/8,470/8),ship);
   // painter->setPen(QPen(Qt::white));
   // painter->drawRect(-350/16,-470/16,350/8,470/8);
}

void Enemy::control()
{
    qreal playerX=target->scenePos().x();
    qreal playerY=target->scenePos().y();

    double linex = ( playerX- this->scenePos().x());
    double liney = ( playerY- this->scenePos().y());

    double arc = atan2(linex,-liney);
    arc = arc * 180.0 / Pi;
    if(arc<0) arc+=360;
    double diff = angle - arc;
    if(diff<-180) diff+=360;
    if(diff>180) diff-=360;

    if(diff>-1 && diff<1)
    {
        rot*=0.920;
    }
    else if(diff>1 && rot>0 && rot/diff>0.185)
    {
        rot = rot - rotacc;
    }
    else if(diff<-1 && rot<0 && rot/diff>0.185)
    {
        rot = rot + rotacc;
    }
    else if(diff>0)
    {
        rot = rot + rotacc;
    }
    else
    {
        rot = rot - rotacc;
    }
    speed = speed + 0.05;
}

QRectF Enemy::boundingRect() const
{
    return m_boundingRect;
}

void Enemy::setBoundingRect(QRectF rect)
{
    m_boundingRect=rect;
}




