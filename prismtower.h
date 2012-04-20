#ifndef PRISMTOWER_H
#define PRISMTOWER_H

#include "tower.h"

class PrismTower : public Tower
{
public:
    PrismTower();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);
};

#endif // PRISMTOWER_H
