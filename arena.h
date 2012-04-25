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

class Tower;
class Deploy;
class Enemy;
class Factory;
class Explosion;
class Missile;

class Arena: public QGraphicsScene
{
public:
    Arena(QPixmap *p);
    void step();

    //static QQueue<Missile*> spawn;

    Deploy* deploy1;
    Deploy* deploy2;

    static Factory factoy;
    static QQueue<Enemy*> spawnEnemy;
    static QQueue<Explosion*> spawnExplosion;
    static QQueue<Explosion*> destroyExplosion;
    static QQueue<Missile*> spawnMissile;
    static QQueue<Missile*> destroyMissile;

private:
    QPixmap* qp;
    DeathStar* deathStar;

    QList<Tower*> towers;
    QList<Enemy*> enemys;
    QList<Missile*> missiles;
    QVector<Explosion*> explosions;

    int time;


public slots:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void wheelEvent( QGraphicsSceneWheelEvent *event);
};

#endif // ARENA_H
