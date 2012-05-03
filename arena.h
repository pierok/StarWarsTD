#ifndef ARENA_H
#define ARENA_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QList>
#include <QQueue>
#include <QSet>
#include <QVector>

#include "factory.h"
#include "tower.h"
#include "deathstar.h"
#include "generator.h"
#include "deploy.h"

class Tower;
class Deploy;
class Enemy;
class Factory;
class Explosion;
class Missile;

enum GUNS {A_NONE, A_PRISM, A_PLASMA};

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
    static QQueue<Missile*> spawnMissile;

    inline void setGun(GUNS g)
    {
        gun=g;
    }

    inline void setInfo(QString* s)
    {
        info=s;
    }

private:
    GUNS gun;
    QPixmap* qp;
    DeathStar* deathStar;
    Generator* gen1;
    Generator* gen2;

    QString* info;

    QSet<Tower*> towers;
    QSet<Enemy*> enemys;
    QSet<Missile*> missiles;
    QList<Explosion*> explosions;

    int amount;
    int time;


public slots:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void wheelEvent( QGraphicsSceneWheelEvent *event);
};

#endif // ARENA_H
