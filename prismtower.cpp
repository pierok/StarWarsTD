#include "prismtower.h"
#include "missile.h"
#include "arena.h"
#include <iostream>
#include <math.h>

PrismTower::PrismTower():Tower()
{
    radius=500;
    weapon1state=0;
    fire=false;
}

void PrismTower::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    /*painter->setPen(Qt::NoPen);
     QRadialGradient *grad = new QRadialGradient(0,0,radius);
     grad->setColorAt(0,QColor(0,0,0,0));
     grad->setColorAt(1,QColor(80,30,255,150));
     QBrush brush(*grad);
     painter->setBrush(brush);
     painter->drawEllipse(-radius/2,-radius/2,radius,radius);*/

    QPixmap ship(":/data/PrismTower.png");
    painter->drawPixmap(QRect(-50,-50,100,100),ship);
}


void PrismTower::inRange(Enemy *enemy)
{


    qreal enemyX=enemy->scenePos().x();
    qreal enemyY=enemy->scenePos().y();


    if((enemyX-this->scenePos().x())*(enemyX-this->scenePos().x())
            +(enemyY-this->scenePos().y())*(enemyY-this->scenePos().y())<=radius*radius){

        this->enemy=enemy;
        fire=true;
    }

}


void PrismTower::control()
{
    if(fire)
    {
        if(weapon1state==0)
        {
            weapon1state=20;
            weaponFire();
        }

        if(weapon1state>0)
        {
            weapon1state--;
        }
    }
}

void PrismTower::weaponFire()
{
    Missile *pr = new Missile();
    pr->setPos(this->scenePos());
  //  pr->rotate(this->angle - 0.5 + 1.0*rand()/RAND_MAX);


    pr->translate(0,0);

    pr->speed = 18.0;
    pr->slide = -0.08;

    Arena::spawn.enqueue(pr);
}




