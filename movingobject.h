#ifndef MOVINGOBJECT_H
#define MOVINGOBJECT_H

#include <QGraphicsItem>


class MovingObject : public QGraphicsItem
{
public:
    MovingObject();
    QRectF boundingRect() const;
    virtual void control();
    virtual void physics();
    virtual void step();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);
    virtual bool isExplosive();     // true, je�li obiekt przy trafieniu w inny wybucha
    virtual bool isHittable();      // true, je�li mo�na go trafi�
    virtual bool isPlayer();
    virtual void hit(int damage);

    qreal radius;          // przybli�ony promie� obiektu do wst�pnej detekcji kolizji
    int health;            // punkty �ycia

    qreal angle;           // k�t pod jakim obrocony jest obiekt wzgledem sceny
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
};


#endif // MOVINGOBJECT_H
