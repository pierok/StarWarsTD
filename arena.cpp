#include "arena.h"
#include "tower.h"
#include "prismtower.h"
#include "lifebar.h"
#include <iostream>

//QQueue<Missile*> Arena::spawn;
QQueue<Enemy*> Arena::spawnEnemy;
QQueue<Explosion*> Arena::spawnExplosion;
QQueue<Explosion*> Arena::destroyExplosion;


QQueue<Missile*> Arena::spawnMissile;
QQueue<Missile*> Arena::destroyMissile;

Factory Arena::factoy;

Arena::Arena()
{
    QPixmap qp(":/data/gw.jpg");
    this->addPixmap(qp);


    LifeBar* l= new LifeBar(250);

    deathStar= new DeathStar();
    deathStar->setPos(qp.size().width()/2,qp.size().height()/2);
    deathStar->setLifeBar(l);

    l->setPos(deathStar->scenePos());
    l->translate(-250,170);
    l->updateLife(250);
    deploy1=new Deploy();
    deploy1->deployEnemy(0);
    deploy1->setPos(60,60);

    deploy2=new Deploy();

    deploy2->deployEnemy(1);
    deploy2->setPos(qp.size().width()-500,60);

    this->addItem(deploy1);
    this->addItem(deploy2);
    this->addItem(deathStar);
    this->addItem(l);
}

void Arena::step()
{
    deathStar->step();
    deploy1->deploy();
    deploy2->deploy();

    while(!spawnEnemy.empty())
    {
        Enemy* en1= spawnEnemy.dequeue();
        en1->setTarget(deathStar);
        this->addItem(en1);
        enemys.push_back(en1);
    }

    foreach(Tower *tower, towers)
    {

        foreach(Enemy *enemy, enemys)
        {
            if(enemy->death==false)
            {
                if(tower->inRange(enemy))
                {
                   // break;
                }
            }
            //break;
        }
        tower->control();
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
        missiles.push_back(misile);
    }

    foreach(Missile *misile, missiles)
    {
        if(misile->deactive==false)
        {
            misile->control();
        }
    }
}

void Arena::wheelEvent( QGraphicsSceneWheelEvent *event )
{
    float scale = 1.0 + event->delta()*0.001;
   // this->
    std::cout<<"Arena event wheel"<<std::endl;
    event->accept();
}

void Arena::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    std::cout<<"x "<<event->scenePos().x()<<" y "<<event->scenePos().y()<<std::endl;
    PrismTower* prism1= new PrismTower();
    prism1->setPos(event->scenePos().x(),event->scenePos().y());

    prism1->setRadius(300);
    prism1->setBoundingRect(QRectF(-150,-150,300,300));

    Prism* missile=new Prism();
    prism1->addPrism(missile);

    towers.push_back(prism1);
    this->addItem(prism1);
    this->addItem(missile);
    event->accept();
}
