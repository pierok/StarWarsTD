#include "missile.h"

#include <QGraphicsScene>
#include <QPainter>
#include <QStyleOption>
#include <QPen>
#include <QColor>

#include <iostream>

Missile::Missile()
{
    deactive=false;
    lifetimer = 30;

    angle = 0;
    speed = 0;
    slide = 0;
    rot = 0;

    friction = 0.9975;
    slidefriction = 0.96;
    rotfriction = 0.98;
    isEnemy=true;
    ID=0;
}

void Missile::reset()
{
    deactive=false;
    lifetimer = 30;

    angle = 0;
    speed = 0;
    slide = 0;
    rot = 0;

    friction = 0.9975;
    slidefriction = 0.96;
    rotfriction = 0.98;
    isEnemy=true;
    ID=0;
}

void Missile::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setPen(Qt::NoPen);
    painter->setBrush(QColor(255,lifetimer*3,0));
    painter->drawEllipse(0,0,8,8);
}

QRectF Missile::boundingRect() const
{
    return QRectF(0,0,8,8);
}

void Missile::control()
{
    if(deactive==false)
    {
        if(lifetimer>0)
        {
            //this->setPos(this->scenePos().x()+velocity.toPoint().x()*2,this->scenePos().y()+velocity.toPoint().y()*2);
            lifetimer--;
        }else
        {
            //std::cout<<"desctive"<<std::endl;
            deactive=true;
            Arena::factoy.deactivateMissile(this);
            this->hide();
            if(Arena::mode==GAME)
            {
                Explosion* expl = Arena::factoy.getExplosion(30);
                expl->setPos(this->scenePos());
            }
            qreal playerX=target->scenePos().x();
            qreal playerY=target->scenePos().y();

            if((playerX-this->scenePos().x())*(playerX-this->scenePos().x())
                    +(playerY-this->scenePos().y())*(playerY-this->scenePos().y())<=200*200)
            {
                target->hit(8);
            }
            //Window::kill.enqueue(this);
        }
    }
}

void Missile::setTarget(Target* d)
{
    target=d;
}

//========================================Plasma========================================

Plasma::Plasma()
{
    deactive=false;
    lifetimer = 40;

    angle = 0;
    speed = 0;
    slide = 0;
    rot = 0;

    friction = 0.9975;
    slidefriction = 0.96;
    rotfriction = 0.98;
    isEnemy=false;
    damage=4;
    ID=2;
}

void Plasma::reset()
{
    deactive=false;
    lifetimer = 40;

    angle = 0;
    speed = 0;
    slide = 0;
    rot = 0;

    friction = 0.9975;
    slidefriction = 0.96;
    rotfriction = 0.98;
    isEnemy=false;
    damage=4;
    ID=2;
}

void Plasma::control()
{
    if(deactive==false)
    {
        if(lifetimer>0)
        {
            //this->setPos(this->scenePos().x()+velocity.toPoint().x()*2,this->scenePos().y()+velocity.toPoint().y()*2);
            lifetimer--;
        }else
        {
            //std::cout<<"desctive"<<std::endl;
            deactive=true;
            //Arena::destroyExplosion.enqueue(this);
            Arena::factoy.deactivateMissile(this,2);
            this->hide();
        }
    }
}

void Plasma::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setPen(Qt::NoPen);
    painter->setBrush(Qt::yellow);
    painter->drawEllipse(-4,-4,8,8);
}

//========================================HLaser=======================================
HLaser::HLaser()
{
    deactive=false;
    lifetimer = 35;

    angle = 0;
    speed = 0;
    slide = 0;
    rot = 0;

    friction = 0.9975;
    slidefriction = 0.96;
    rotfriction = 0.98;
    isEnemy=false;
    damage=2;
    ID=3;
}


void HLaser::reset()
{
    deactive=false;
    lifetimer = 35;

    angle = 0;
    speed = 0;
    slide = 0;
    rot = 0;

    friction = 0.9975;
    slidefriction = 0.96;
    rotfriction = 0.98;
    isEnemy=false;
    damage=2;
    ID=3;
}

void HLaser::control()
{
    if(deactive==false)
    {
        if(lifetimer>0)
        {
            //this->setPos(this->scenePos().x()+velocity.toPoint().x()*2,this->scenePos().y()+velocity.toPoint().y()*2);
            lifetimer--;
        }else
        {
            //std::cout<<"desctive"<<std::endl;
            deactive=true;
            //Arena::destroyExplosion.enqueue(this);
            Arena::factoy.deactivateMissile(this,3);
            this->hide();
        }
    }
}

void HLaser::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setPen(Qt::NoPen);
    painter->setBrush(Qt::red);
    painter->drawRect(-2,0,4,14);
    painter->setBrush(Qt::yellow);
    painter->drawRect(-1,0,2,3);
}


//========================================Laser========================================

Laser::Laser()
{
    deactive=false;
    lifetimer = 70;

    angle = 0;
    speed = 0;
    slide = 0;
    rot = 0;

    friction = 0.9975;
    slidefriction = 0.96;
    rotfriction = 0.98;
    isEnemy=true;
    ID=1;
}

void Laser::reset()
{
    deactive=false;
    lifetimer = 70;

    angle = 0;
    speed = 0;
    slide = 0;
    rot = 0;

    friction = 0.9975;
    slidefriction = 0.96;
    rotfriction = 0.98;
    isEnemy=true;
    ID=1;
}

void Laser::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setPen(Qt::NoPen);
    painter->setBrush(Qt::green);
    painter->drawRect(-2,0,4,10);
}

void Laser::control()
{
    if(deactive==false)
    {
        if(lifetimer>0)
        {
            //this->setPos(this->scenePos().x()+velocity.toPoint().x()*2,this->scenePos().y()+velocity.toPoint().y()*2);
            lifetimer--;
            qreal playerX=target->scenePos().x();
            qreal playerY=target->scenePos().y();

            if((playerX-this->scenePos().x())*(playerX-this->scenePos().x())
                    +(playerY-this->scenePos().y())*(playerY-this->scenePos().y())<=120*120)
            {
                target->hit(0.5);
                deactive=true;
                Arena::factoy.deactivateMissile(this,1);
                if(Arena::mode==GAME)
                {
                    Explosion* expl = Arena::factoy.getExplosion(30);
                    expl->setPos(this->scenePos());
                }
                this->hide();
            }
        }else
        {
            //std::cout<<"desctive"<<std::endl;
            deactive=true;
            //Arena::destroyExplosion.enqueue(this);
            Arena::factoy.deactivateMissile(this,1);
            this->hide();
            //Window::kill.enqueue(this);
        }
    }
}

//========================================Prism========================================
Prism::Prism()
{
    // std::cout<<"Prism counstract"<<std::endl;
    lifetimer = 0;
    ID=4;
}


void Prism::reset()
{
    lifetimer = 0;
    ID=4;
}

void Prism::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    QLinearGradient linearGrad(source.x(), source.y(), target.x(), target.y());
    linearGrad.setColorAt(0, Qt::red);
    linearGrad.setColorAt(0.5, Qt::blue);
    linearGrad.setColorAt(1, Qt::green);

    QBrush brush(linearGrad);
    QPen pen(brush, 3.5, Qt::SolidLine, Qt::RoundCap);
    painter->setPen(pen);
    painter->drawLine(source.x(), source.y(), target.x(), target.y());
}

QRectF Prism::boundingRect() const
{
    return QRectF(source.x(), source.y(), 1, 1000);
}
