#include "arena.h"
#include "tower.h"
#include "prismtower.h"
#include <iostream>

Arena::Arena()
{
    this->addPixmap(QPixmap(":/data/gw.jpg"));
    this->addItem(new Tower());

    Tower* tower1=new Tower();
    tower1->setPos(100,100);

    PrismTower* prism1= new PrismTower();
    prism1->setPos(200,100);



    enemy= new Enemy();
    enemy->setPos(1000,1000);

    this->addItem(tower1);
    this->addItem(prism1);
    this->addItem(enemy);
}

void Arena::update()
{

    enemy->step();
    foreach(QGraphicsItem *item, items())
    {
        item->update();
    }
}
