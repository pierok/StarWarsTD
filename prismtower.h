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

    inline void addPrism(Prism* p)
    {
        prism=p;
        prism->setSource(QPoint(this->scenePos().x(),this->scenePos().y()));
        prism->setTarget(QPoint(this->scenePos().x(),this->scenePos().y()));
    }


    void weaponFire();
    bool inRange(Enemy *);
    void control();
    bool fire;
    int weapon1state;

private:
    Prism* prism;

};

#endif // PRISMTOWER_H
