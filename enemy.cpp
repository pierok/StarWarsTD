#include "enemy.h"
#include <QVector2D>
#include <iostream>
#include <math.h>

Enemy::Enemy()
{
    radius=300;
    angle = 0;
    speed = 0.0;
    slide = 0;
    rot = 0;

    friction = 0.9966;
    slidefriction = 0.9850;
    rotfriction = 0.9750;

    acc = 0.05;
    slideacc = 0.12;
    brake = 0.10;
    rotacc = 0.2;

    life=400;
    armor=100;
    death=false;
    fire=true;
    weapon1state=0;
    direction=QVector2D(0,0);
    m_boundingRect=QRectF(-350/16,-470/16,350/8,470/8);
}

void Enemy::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    QPixmap ship(":/data/SokolMilenium.png");
    painter->drawPixmap(QRect(-350/16,-470/16,350/8,470/8),ship);
    painter->setPen(Qt::white);
}

void Enemy::hit(double damage)
{
    life-=damage;
    if(life<=0)
    {
        death=true;
        this->hide();
        Explosion* expl = Arena::factoy.getExplosion(60);
        expl->setPos(this->scenePos());
    }
}


void Enemy::control()
{
    qreal playerX=target->scenePos().x();
    qreal playerY=target->scenePos().y();

    if((playerX-this->scenePos().x())*(playerX-this->scenePos().x())
            +(playerY-this->scenePos().y())*(playerY-this->scenePos().y())<=radius*radius)
    {
        fire=true;
    }
    else
    {
        fire=false;
    }

    double linex = ( playerX- this->scenePos().x());
    double liney = ( playerY- this->scenePos().y());

    direction.setX(linex);
    direction.setY(liney);

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
    speed = speed + acc;


    if(fire)
    {
        if(weapon1state==0)
        {
            weapon1state=10;
            weaponFire();
        }

        if(weapon1state>0)
        {
            weapon1state--;
        }
    }

}

QRectF Enemy::boundingRect() const
{
    return m_boundingRect;
}

void Enemy::setBoundingRect(QRectF rect)
{
    m_boundingRect=rect;
}

void Enemy::weaponFire()
{
    Missile *missile = Arena::factoy.getMissile();
    // missile->deactive=false;
    //missile->lifetimer=100;
    missile->setTarget(target);
    missile->setPos(this->scenePos());
    missile->rotate(this->angle);// - 0.5 + 1.0*rand()/RAND_MAX);
    missile->speed = -1;
    missile->slide = this->slide - 0.08;

}



bool Enemy::isCollide(int mX, int mY)
{

    int rad=40;
    if((mX-this->scenePos().x())*(mX-this->scenePos().x())
            +(mY-this->scenePos().y())*(mY-this->scenePos().y())<=rad*rad)
    {

        return true;
    }
    return false;
}


Xwing::Xwing()
{
    radius=1000;
    angle = 0;
    speed = 0.5;
    slide = 0;
    rot = 0;

    friction = 0.9966;
    slidefriction = 0.9850;
    rotfriction = 0.9750;

    acc = 0.18;
    slideacc = 0.12;
    brake = 0.10;
    rotacc = 0.2;

    life=150;
    armor=100;
    death=false;
    fire=true;
    weapon1state=0;
    m_boundingRect=QRectF(-410/16,-326/16,410/8,326/8);
}



void Xwing::weaponFire()
{
  /* Missile *missile = Arena::factoy.getMissile();
    // missile->deactive=false;
    //missile->lifetimer=100;
    missile->setPos(this->scenePos());
    missile->rotate(this->angle);// - 0.5 + 1.0*rand()/RAND_MAX);
    missile->speed = this->speed+18;
    missile->slide = this->slide - 0.08;*/

    Missile *missile = Arena::factoy.getMissile(1);
    // missile->deactive=false;
    //missile->lifetimer=100;
    missile->setTarget(target);
    missile->setPos(this->scenePos());
    missile->rotate(this->angle);// - 0.5 + 1.0*rand()/RAND_MAX);
    missile->speed = this->speed+7;
    missile->slide = this->slide - 0.08;
}

void Xwing::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    QPixmap ship(":/data/X-Wing.png");
    painter->drawPixmap(QRect(-410/16,-326/16,410/8,326/8),ship);
}





