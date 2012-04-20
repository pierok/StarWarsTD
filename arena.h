#ifndef ARENA_H
#define ARENA_H

#include <QGraphicsScene>
#include "enemy.h"

class Arena: public QGraphicsScene
{
public:
    Arena();
    void update();
private:
    Enemy* enemy;
};

#endif // ARENA_H
