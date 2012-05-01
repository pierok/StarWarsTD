#include "arena.h"
#include "tower.h"
#include "prismtower.h"
#include "plasmatower.h"
#include "lifebar.h"
#include <iostream>

QQueue<Enemy*> Arena::spawnEnemy;
QQueue<Explosion*> Arena::spawnExplosion;
QQueue<Missile*> Arena::spawnMissile;

Factory Arena::factoy;

Arena::Arena(QPixmap *p)
{
    gun=A_NONE;
    qp=p;
    LifeBar* l= new LifeBar(1000);

    this->addPixmap(*qp);

    deathStar= new DeathStar();
    deathStar->setPos(qp->size().width()/2,qp->size().height()/2);
    deathStar->setLifeBar(l);
    deathStar->deactive=false;

    l->setPos(deathStar->scenePos());
    l->translate(-250,170);
    deploy1=new Deploy();
    deploy1->deployEnemy(0);
    deploy1->setPos(60,60);
    deploy1->setRate(80);
    deploy1->deploySize(1);

    deploy2=new Deploy();

    deploy2->deployEnemy(1);
    deploy2->setPos(qp->size().width()-500,60);
    deploy2->setRate(20);
    deploy2->deploySize(0);

    this->addItem(deploy1);
    this->addItem(deploy2);
    this->addItem(deathStar);
    this->addItem(l);
}

void Arena::step()
{
    if(deathStar->deactive==false)
    {
        deathStar->step();
        if(deathStar->life<=0)
        {
            Explosion* exp=factoy.getExplosion(1000);
            exp->setPos(deathStar->scenePos());
            deathStar->hide();
            deathStar->deactive=true;
            foreach(Enemy *enemy, enemys)
            {
                enemy->hit(10000);
            }
        }
    }

    deploy1->deploy();
    deploy2->deploy();

    while(!spawnEnemy.empty())
    {
        Enemy* en1= spawnEnemy.dequeue();
        en1->setTarget(deathStar);
        this->addItem(en1);
        enemys.insert(en1);
    }

    foreach(Enemy *enemy, enemys)
    {
        if(enemy->death==false)
        {
            enemy->control();
            enemy->physics();
            enemy->step();
        }
    }

    foreach(Tower *tower, towers)
    {
        foreach(Enemy *enemy, enemys)
        {
            if(enemy->death==false)
            {
                if(tower->inRange(enemy))
                {
                    //break;
                }
            }
        }
        tower->control();
    }


    while(!spawnExplosion.empty())
    {
        Explosion* exp= spawnExplosion.dequeue();
        this->addItem(exp);
        explosions.push_back(exp);
    }

    foreach(Explosion *exp, explosions)
    {
        if(exp->deactive==false)
            exp->control();
    }

    while(!spawnMissile.empty())
    {
        Missile* misile= spawnMissile.dequeue();
        this->addItem(misile);
        missiles.insert(misile);

    }

    foreach(Missile *misile, missiles)
    {
        if(misile->deactive==false)
        {
            misile->control();
            misile->physics();
            misile->step();
            if(!misile->isEnemy)
            {
                foreach(Enemy* enemy, enemys)
                {
                    if(enemy->death==false&&enemy->isCollide(misile->scenePos().x(),misile->scenePos().y()))
                    {
                        enemy->hit(misile->getDamage());
                        misile->deactive=true;
                        misile->hide();
                        factoy.deactivateMissile(misile,2);

                        Explosion* exp=factoy.getExplosion(20);
                        exp->setPos(misile->scenePos());
                    }
                }
            }
        }
    }
}

void Arena::wheelEvent( QGraphicsSceneWheelEvent *event )
{
    //float scale = 1.0 + event->delta()*0.001;
    event->accept();
}

void Arena::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(gun==A_PRISM)
    {
        PrismTower* prism1= new PrismTower();

        prism1->setPos(event->scenePos().x(),event->scenePos().y());

        prism1->setRadius(300);
        prism1->setBoundingRect(QRectF(-150,-150,300,300));

        Prism* missile=new Prism();
        prism1->addPrism(missile);

        towers.insert(prism1);
        this->addItem(prism1);
        this->addItem(missile);
    }else if(gun==A_PLASMA)
    {
        PlasmaTower* plasma= new PlasmaTower();
        plasma->setPos(event->scenePos().x(),event->scenePos().y());
        plasma->setRadius(800);
        plasma->setBoundingRect(QRectF(-150,-150,300,300));
        this->addItem(plasma);
        towers.insert(plasma);
    }
    event->accept();
}
