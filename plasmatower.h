#ifndef PLASMATOWER_H
#define PLASMATOWER_H


#include "tower.h"

class PlasmaTower : public Tower
{
public:
    PlasmaTower();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);

    void weaponFire();
    bool inRange(Enemy *);
    void control();
    void reset();

    bool fire;
    int weapon1state;
};

#endif // PLASMATOWER_H
