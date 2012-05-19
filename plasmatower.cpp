#include "plasmatower.h"
#include "missile.h"
#include <math.h>

PlasmaTower::PlasmaTower()
{
    radius=1;
    weapon1state=0;
    fire=false;

    angle = 0;
    speed = 0;
    slide = 0;
    rot = 0;

    friction = 0.9925;
    slidefriction = 0.9850;
    rotfriction = 1.0;//0.9750;

    acc = 0.07;
    slideacc = 0.12;
    brake = 0.10;
    rotacc = 0.9;
    enemy=NULL;
    cost=10;
    deactive=false;
    ID=1;
}

void PlasmaTower::reset()
{
    weapon1state=0;
    fire=false;
    enemy=NULL;
    deactive=false;
    ID=1;
}

void PlasmaTower::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                        QWidget *widget)
{
    QPixmap tower(":/data/plazmaTower.png");
    painter->drawPixmap(QRect(-30,-40,60,80),tower);
}

void PlasmaTower::weaponFire()
{
    Missile *missile = Arena::factoy.getMissile(2);
    missile->setPos(this->scenePos());
    missile->rotate(this->angle);// - 0.5 + 1.0*rand()/RAND_MAX);
    missile->speed = this->speed+15;
}

bool PlasmaTower::inRange(Enemy *e)
{
    if(e!=NULL)
    {
        qreal enemyX=e->scenePos().x();
        qreal enemyY=e->scenePos().y();

        if((enemyX-this->scenePos().x())*(enemyX-this->scenePos().x())
                +(enemyY-this->scenePos().y())*(enemyY-this->scenePos().y())<=radius*radius){

            this->enemy=e;
            fire=true;
            return true;
        }
    }
    return false;
}

void PlasmaTower::control()
{
    if(enemy!=NULL)
    {
        qreal playerX=enemy->scenePos().x();
        qreal playerY=enemy->scenePos().y();

        if((playerX-this->scenePos().x())*(playerX-this->scenePos().x())
                +(playerY-this->scenePos().y())*(playerY-this->scenePos().y())<=radius*radius)
        {
            fire=true;
        }
        else
        {
            fire=false;
        }

        enemy->direction.normalize();
        enemy->direction*=60;

        enemy->direction*=(((enemy->speed/*enemy->speed*/)/(this->speed+15)));

        playerX+=enemy->direction.x();
        playerY+=enemy->direction.y();

        double linex = ( playerX- this->scenePos().x());
        double liney = ( playerY- this->scenePos().y());

        double arc = atan2(linex,-liney);
        arc = arc * 180.0 / M_PI;
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

        physics();
        step();

        if(fire)
        {
            if(weapon1state==0)
            {
                weapon1state=4;
                weaponFire();
            }

            if(weapon1state>0)
            {
                weapon1state--;
            }
        }
    }
}
