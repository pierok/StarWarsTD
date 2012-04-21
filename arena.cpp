#include "arena.h"
#include "tower.h"
#include "prismtower.h"
#include <iostream>

Arena::Arena()
{
    this->addPixmap(QPixmap(":/data/gw.jpg"));

    enemy= new Enemy();
    enemy->setPos(1000,1000);

    this->addItem(enemy);
}

void Arena::step()
{
    enemy->step();
    foreach(Tower *tower, towers)
    {
        tower->step();
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


