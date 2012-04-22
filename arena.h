#ifndef ARENA_H
#define ARENA_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QList>
#include "enemy.h"
#include "tower.h"
#include "deathstar.h"

class Arena: public QGraphicsScene
{
public:
    Arena();
    void step();
private:
    DeathStar* deathStar;
    QList<Tower*> towers;
    QList<Enemy*> enemys;


public slots:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // ARENA_H
