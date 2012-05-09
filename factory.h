#ifndef FACTORY_H
#define FACTORY_H

#include <QQueue>
#include "enemy.h"
#include "exception"
#include "missile.h"
#include "arena.h"

class Arena;
class Enemy;
class Explosion;
class Missile;


class Factory
{
public:
    Factory();

    void deactivateEnemy(Enemy* e, int type=0);

    inline void deactivateExplosion(Explosion* e)
    {
        explosions.enqueue(e);
    }

    void deactivateMissile(Missile* m, int type=0);

    Enemy* getEnemy(int type=0);
    Explosion* getExplosion(int size);
    Missile* getMissile(int type=0);

private:
    QQueue<Missile*> missile;
    QQueue<Missile*> lasers;
    QQueue<Missile*> plasma;
    QQueue<Enemy*> enemys;
    QQueue<Enemy*> xwings;
    QQueue<Explosion*> explosions;
};

#endif // FACTORY_H
