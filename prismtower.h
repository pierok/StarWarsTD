#ifndef PRISMTOWER_H
#define PRISMTOWER_H


#include <QVector2D>
#include <QPoint>
#include "tower.h"

class PrismTower : public Tower
{
public:
    PrismTower();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);
    int weapon1state;
    void weaponFire();
    void inRange(Enemy *);
    bool fire;
    void control();
};

#endif // PRISMTOWER_H
