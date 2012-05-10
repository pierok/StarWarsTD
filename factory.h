#ifndef FACTORY_H
#define FACTORY_H

#include <QQueue>
#include "enemy.h"
#include "exception"
#include "missile.h"
#include "arena.h"
#include "tower.h"

class Arena;
class Enemy;
class Explosion;
class Missile;
class Tower;


class Factory
{
public:
    Factory();

    void deactivateEnemy(Enemy* e, int type=0);
    void deactivateTower(Tower* e, int type=0);

    inline void deactivateExplosion(Explosion* e)
    {
        explosions.enqueue(e);
    }

    void deactivateMissile(Missile* m, int type=0);

    Enemy* getEnemy(int type=0);
    Explosion* getExplosion(int size);
    Missile* getMissile(int type=0);
    Tower* getTower(int type=0);

private:
    QQueue<Missile*> missile;
    QQueue<Missile*> lasers;
    QQueue<Missile*> plasma;
    QQueue<Enemy*> enemys;
    QQueue<Enemy*> xwings;
    QQueue<Explosion*> explosions;
    QQueue<Tower*> prismTowers;
    QQueue<Tower*> plasmaTowers;
};

#endif // FACTORY_H
