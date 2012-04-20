#include "arena.h"
#include "tower.h"
Arena::Arena()
{
    this->addItem(new Tower());
}

void Arena::update()
{
    /*foreach(QGraphicsItem *item, items())
    {
        item->update();
    }*/
}
