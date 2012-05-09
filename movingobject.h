#ifndef MOVINGOBJECT_H
#define MOVINGOBJECT_H

#include <QGraphicsItem>


class MovingObject : public QGraphicsItem
{
public:
    MovingObject();
    QRectF boundingRect() const;
    virtual void control()=0;
    virtual void physics();
    virtual void step();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);

    float radius;


    float angle;
    float speed;
    float slide;
    float rot;

    float friction;
    float slidefriction;
    float rotfriction;

    float acc;
    float brake;
    float slideacc;
    float rotacc;
};


#endif // MOVINGOBJECT_H
