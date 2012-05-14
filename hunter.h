#ifndef HUNTER_H
#define HUNTER_H

#include "tower.h"

class Hunter : public Tower
{
public:
    Hunter();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);

    void weaponFire();
    bool inRange(Enemy *);
    void control();
    void reset();

    bool fire;
    int weapon1state;
};

#endif // HUNTER_H
