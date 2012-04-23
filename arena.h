#ifndef ARENA_H
#define ARENA_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QList>
#include <QQueue>
#include "enemy.h"
#include "tower.h"
#include "deathstar.h"
#include "missile.h"
#include "deploy.h"
#include "explosion.h"

class Tower;
class Deploy;


class Arena: public QGraphicsScene
{
public:
    Arena();
    void step();
    static QQueue<Missile*> spawn;
    static QQueue<Enemy*> spawnEnemy;
    static QQueue<Explosion*> spawnExplosion;

private:
    DeathStar* deathStar;
    Deploy* deploy1;
    Deploy* deploy2;
    QList<Tower*> towers;
    QList<Enemy*> enemys;
    QQueue<Enemy*> deathEnemy;
    QList<Missile*> missiles;

public slots:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // ARENA_H
