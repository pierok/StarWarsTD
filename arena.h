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

class Tower;
class Deploy;

class Arena: public QGraphicsScene
{
public:
    Arena();
    void step();
    static QQueue<Missile*> spawn;
    static QQueue<Enemy*> spawnEnemy;

private:
    DeathStar* deathStar;
    Deploy* deploy1;
    Deploy* deploy2;
    QList<Tower*> towers;
    QList<Enemy*> enemys;
    QList<Missile*> missiles;

public slots:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // ARENA_H
