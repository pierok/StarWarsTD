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

    inline void deactivateEnemy(Enemy* e)
    {
        enemys.enqueue(e);
    }

    inline void deactivateExplosion(Explosion* e)
    {
        explosions.enqueue(e);
    }

    inline void deactivateMissile(Missile* m)
    {
        missile.enqueue(m);
    }

    Enemy* getEnemy();
    Explosion* getExplosion(int size);
    Missile* getMissile();

private:
    QQueue<Missile*> missile;
    QQueue<Enemy*> enemys;
    QQueue<Explosion*> explosions;
};

#endif // FACTORY_H
