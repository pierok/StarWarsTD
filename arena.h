#ifndef ARENA_H
#define ARENA_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QList>
#include <QQueue>
#include <QVector>

#include "factory.h"
#include "tower.h"
#include "deathstar.h"
#include "deploy.h"
//#include "explosion.h"
//#include "enemy.h"
//#include "missile.h"

class Tower;
class Deploy;
class Enemy;
class Factory;
class Explosion;
class Missile;

class Arena: public QGraphicsScene
{
public:
    Arena();
    void step();
    //static QQueue<Missile*> spawn;

    static Factory factoy;

    static QQueue<Enemy*> spawnEnemy;
    static QQueue<Explosion*> spawnExplosion;
    static QQueue<Explosion*> destroyExplosion;
    static QQueue<Missile*> spawnMissile;
    static QQueue<Missile*> destroyMissile;

private:
    DeathStar* deathStar;
    Deploy* deploy1;
    Deploy* deploy2;
    QList<Tower*> towers;
    QList<Enemy*> enemys;
    QList<Missile*> missiles;
    QVector<Explosion*> explosions;

public slots:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // ARENA_H
