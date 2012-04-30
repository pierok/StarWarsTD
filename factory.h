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

    void deactivateMissile(Missile* m, int type=0);

    Enemy* getEnemy();
    Explosion* getExplosion(int size);
    Missile* getMissile(int type=0);

private:
    QQueue<Missile*> missile;
    QQueue<Missile*> lasers;
    QQueue<Missile*> plasma;
    QQueue<Enemy*> enemys;
    QQueue<Explosion*> explosions;
};

#endif // FACTORY_H
