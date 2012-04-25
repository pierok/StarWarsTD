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
    lifetimer = 40;
    velocity=QVector2D(0.0,-1.0);

    angle = 0;
    speed = 0;
    slide = 0;
    rot = 0;

    friction = 0.9975;
    slidefriction = 0.96;
    rotfriction = 0.98;

}


void Missile::reset()
{
    deactive=false;
    lifetimer = 40;
    velocity=QVector2D(0.0,-1.0);


    angle = 0;
    speed = 0;
    slide = 0;
    rot = 0;

    friction = 0.9975;
    slidefriction = 0.96;
    rotfriction = 0.98;

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
            //Arena::destroyExplosion.enqueue(this);
            Arena::factoy.deactivateMissile(this);
            this->hide();
            Explosion* expl = Arena::factoy.getExplosion(30);
            expl->setPos(this->scenePos());

            qreal playerX=target->scenePos().x();
            qreal playerY=target->scenePos().y();

            if((playerX+145-this->scenePos().x())*(playerX+145-this->scenePos().x())
                    +(playerY-this->scenePos().y())*(playerY-this->scenePos().y())<=200*200)
            {
                target->hit(50);
            }
           //Window::kill.enqueue(this);
        }
    }
}


void Missile::step()
{
    rotate(-rot);
    angle-=rot;
    if(angle<0) angle+=360;
    if(angle>360) angle-=360;
    translate(0,-speed);
    translate(-slide,0);
}



Prism::Prism()
{
    // std::cout<<"Prism counstract"<<std::endl;
    lifetimer = 0;
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
