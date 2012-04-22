#include "arena.h"
#include "tower.h"
#include "prismtower.h"
#include <iostream>

Arena::Arena()
{
    QPixmap qp(":/data/gw.jpg");//=new QPixmap(":/data/gw.jpg");
    this->addPixmap(qp);

    deathStar= new DeathStar();
    deathStar->setPos(qp.size().width()/2,qp.size().height()/2);

    this->addItem(deathStar);

    Enemy* en1= new Enemy();
    en1->setPos(10,10);

    en1->setTarget(deathStar);
    enemys.push_back(en1);
    this->addItem(en1);

}

void Arena::step()
{
    deathStar->step();
    foreach(Tower *tower, towers)
    {
        tower->step();
    }
    foreach(Enemy *enemy, enemys)
    {
        enemy->control();
        enemy->physics();
        enemy->step();
    }
}

void Arena::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    std::cout<<"x "<<event->scenePos().x()<<" y "<<event->scenePos().y()<<std::endl;
    PrismTower* prism1= new PrismTower();
    prism1->setPos(event->scenePos().x(),event->scenePos().y());

    prism1->setRadius(600);
    prism1->setBoundingRect(QRectF(-300,-300,600,600));

    towers.push_back(prism1);
    this->addItem(prism1);
    event->accept();

}


