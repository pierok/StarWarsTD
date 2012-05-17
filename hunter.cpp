#include "hunter.h"
#include "missile.h"
#include <math.h>

Hunter::Hunter()
{
    m_boundingRect=QRectF(-140/4,-115/4,280/4, 230/4);
    radius=1;
    weapon1state=0;
    fire=false;

    angle = 0;
    speed = 4;
    slide = 0;
    rot = 0;

    friction = 0.9925;
    slidefriction = 0.9850;
    rotfriction = 1.0;//0.9750;

    acc = 0.17;
    slideacc = 0.12;
    brake = 0.10;
    rotacc = 0.9;
    enemy=NULL;
    cost=20;
    deactive=false;
    ID=2;
}

void Hunter::reset()
{
    radius=1;
    weapon1state=0;
    fire=false;

    angle = 0;
    speed = 4;
    slide = 0;
    rot = 0;

    friction = 0.9925;
    slidefriction = 0.9850;
    rotfriction = 1.0;//0.9750;

    acc = 0.17;
    slideacc = 0.12;
    brake = 0.10;
    rotacc = 0.9;
    enemy=NULL;
    cost=20;
    deactive=false;
    ID=2;
}

void Hunter::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                        QWidget *widget)
{
    QPixmap tower(":/data/TIE_fighter.png");
    painter->drawPixmap(QRect(-140/4,-115/4,280/4, 230/4),tower);

    painter->setPen(Qt::white);
    painter->drawEllipse(-140/4,-115/4,280/4, 230/4);
}

void Hunter::weaponFire()
{
    Missile *missile = Arena::factoy.getMissile(3);

    missile->setPos(this->scenePos());

    missile->rotate(this->angle);
    missile->speed = this->speed+20;
}

bool Hunter::inRange(Enemy *e)
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

void Hunter::control()
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

        //enemy->direction.normalize();
        //enemy->direction*=60;

        //enemy->direction*=(((enemy->speed/*enemy->speed*/)/(this->speed+20)));

       // playerX+=enemy->direction.x();
       // playerY+=enemy->direction.y();

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

        speed = speed + acc;

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
