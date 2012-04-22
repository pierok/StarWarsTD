#ifndef EXPLOSION_H
#define EXPLOSION_H

#include <QGraphicsItem>
#include <QPainter>
#include <QStyleOption>
#include <QPen>
#include <QColor>

class Explosion : public QGraphicsItem
{
public:
    Explosion();
    Explosion(int size);

    int size;
    int lifetimer;
    int lifemax;

    void control();
    void physics();
    void step();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);
};

#endif // EXPLOSION_H
