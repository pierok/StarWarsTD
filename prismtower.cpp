#include "prismtower.h"
#include "missile.h"
#include "arena.h"
#include "explosion.h"
#include <iostream>
#include <math.h>

PrismTower::PrismTower()
{
    radius=1;
    cost=30;
    weapon1state=0;
    fire=false;
    enemy=NULL;
    deactive=false;
}

void PrismTower::reset()
{
    weapon1state=0;
    fire=false;
    enemy=NULL;
    deactive=false;
}

void PrismTower::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    QPixmap ship(":/data/PrismTower.png");
    painter->drawPixmap(QRect(-50,-50,100,100),ship);
}

bool PrismTower::inRange(Enemy *enemy)
{

    qreal enemyX=enemy->scenePos().x();
    qreal enemyY=enemy->scenePos().y();


    if((enemyX-this->scenePos().x())*(enemyX-this->scenePos().x())
            +(enemyY-this->scenePos().y())*(enemyY-this->scenePos().y())<=radius*radius){

        this->enemy=enemy;
        fire=true;
        return true;
    }

    return false;

}

void PrismTower::control()
{
    if(fire)
    {
        if(weapon1state==0)
        {
            weapon1state=90;
            weaponFire();
        }

        if(weapon1state>0)
        {
            weapon1state--;
        }
    }
    prism->control();
}

void PrismTower::weaponFire()
{
    if(enemy!=NULL)
    {
        if(enemy->death==false)
        {
            prism->setTarget(QPoint(enemy->scenePos().x(),enemy->scenePos().y()));
            prism->lifetimer=5;
            prism->show();
            enemy->hit(40);
            enemy=NULL;
        }
    }
}

