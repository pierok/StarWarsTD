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
    m_boundingRect=QRectF(-350/2,-470/2,350,470);
}

void Enemy::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    QPixmap ship(":/data/SokolMilenium.png");
    painter->drawPixmap(QRect(-350/2,-470/2,350,470),ship);
    painter->setPen(QPen(Qt::white));
    painter->drawRect(-350/2,-470/2,350,470);
}

/*
void Enemy::step()
{
    QVector2D kierunek( target->scenePos().x()-this->scenePos().x(),target->scenePos().y()-this->scenePos().y());
    kierunek.normalize();

    std::cout<<"xx "<<kierunek.x()*2<<" yy "<<kierunek.y()*2<<std::endl;
    translate(kierunek.x()*5,kierunek.y()*5);
}
*/
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

void Enemy::physics()
{
    if((speed >= 0.025) || (speed <= -0.025))
    {
        speed = speed * friction;
    }
    else
    {
        speed = 0;
    }
    if((rot >= 0.025) || (rot <= -0.025))
    {
        rot = rot * rotfriction;
    }
    else
    {
        rot = 0;
    }
    if(rot!=0)
    {
        speed += rot*slide*0.01;
        slide -= rot*speed*0.01;
    }
    if((slide >= 0.025) || (slide <= -0.025))
    {
        slide = slide * slidefriction;
    }
    else
    {
        slide = 0;
    }
}

void Enemy::step()
{
    rotate(-rot);
    angle-=rot;
    if(angle<0) angle+=360;
    if(angle>360) angle-=360;
    translate(0,-speed);
    translate(-slide,0);
}

QRectF Enemy::boundingRect() const
{
    return m_boundingRect;
}

void Enemy::setBoundingRect(QRectF rect)
{
    m_boundingRect=rect;
}




