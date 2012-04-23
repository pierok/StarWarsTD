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

    QRectF boundingRect() const;
    void setBoundingRect(QRectF);

    void control();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);
private:
    QRectF m_boundingRect;
};

#endif // EXPLOSION_H
