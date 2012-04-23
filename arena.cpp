#include "arena.h"
#include "tower.h"
#include "prismtower.h"
#include <iostream>

QQueue<Missile*> Arena::spawn;
QQueue<Enemy*> Arena::spawnEnemy;
QQueue<Explosion*> Arena::spawnExplosion;

Arena::Arena()
{
    QPixmap qp(":/data/gw.jpg");//=new QPixmap(":/data/gw.jpg");
    this->addPixmap(qp);

    deathStar= new DeathStar();
    deathStar->setPos(qp.size().width()/2,qp.size().height()/2);

    deploy1=new Deploy();

    deploy1->setPos(60,60);

    deploy2=new Deploy();

    deploy2->setPos(qp.size().width()-500,60);

    this->addItem(deploy1);
    this->addItem(deploy2);
    this->addItem(deathStar);
}

void Arena::step()
{
    deathStar->step();
    deploy1->deploy();
    deploy2->deploy();

    foreach(Enemy *enemy, enemys)
    {
        if(enemy->death==false)
        {
            enemy->control();
            enemy->physics();
            enemy->step();
        }
    }

    foreach(Missile *m, missiles)
    {
        m->control();
        m->physics();
        m->step();
    }

    foreach(Tower *tower, towers)
    {

        foreach(Enemy *enemy, enemys)
        {
            if(enemy->death==false)
            {
                tower->inRange(enemy);
            }else
                continue;
            //break;
        }
        tower->control();
    }

    while(!spawnEnemy.empty())
    {
        Enemy* en1= spawnEnemy.dequeue();
        en1->setTarget(deathStar);
        this->addItem(en1);
        enemys.push_back(en1);
    }

    while(!spawnExplosion.empty())
    {
        Explosion* exp= spawnExplosion.dequeue();
        this->addItem(exp);
        explosions.push_back(exp);
    }

    while(!spawn.empty())
    {
        Missile* tmp=spawn.dequeue();
        this->addItem(tmp);
        missiles.push_back(tmp);
    }


    foreach(Explosion *exp, explosions)
    {
        exp->control();
    }
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
