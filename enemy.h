#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsItem>
#include <QPainter>
#include <QStyleOption>
#include <iostream>
#include "deathstar.h"

static const double Pi = 3.14159265358979323846264338327950288419717;

class Enemy: public QGraphicsItem
{
public:
    Enemy();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);

    QRectF boundingRect() const;
    void setBoundingRect(QRectF);

    inline void setTarget(DeathStar* star)
    {
        target=star;
    }

    void step();
    void control();
    void physics();

protected:
    double life;
    //double armor;

    qreal radius;          // przybli¿ony promieñ obiektu do wstêpnej detekcji kolizji

    qreal angle;           // k¹t pod jakim obrocony jest obiekt wzgledem sceny
    qreal speed;           // predkosc do przodu wzgledem obiektu
    qreal slide;           // predkosc w bok wzgledem obiektu
    qreal rot;             // predkosc obrotowa

    qreal friction;        // wspolczynnik 1-tarcie do przodu
    qreal slidefriction;   // na boki
    qreal rotfriction;     // obrotowy

    qreal acc;             // przyspieszenie
    qreal brake;           // hamowanie
    qreal slideacc;        // przyspieszenie boczne
    qreal rotacc;          // przyspieszenie obrotowe

    DeathStar* target;
    QRectF m_boundingRect;
};

#endif // ENEMY_H
