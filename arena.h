#ifndef ARENA_H
#define ARENA_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QList>
#include "enemy.h"
#include "area.h"
#include "tower.h"

class Arena: public QGraphicsScene
{
public:
    Arena();
    void step();
private:
    Enemy* enemy;
    Area* area;
    QList<Tower*> towers;


public slots:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // ARENA_H
