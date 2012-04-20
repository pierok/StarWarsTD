#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsItem>
#include <QPainter>
#include <QStyleOption>
#include <iostream>

class Enemy: public QGraphicsItem
{
public:
    Enemy();
    Enemy(int l, int s, int a);


    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);

    QRectF boundingRect() const;
    void setBoundingRect(QRectF);

    void step()
    {
        this->rotate(0.2);
    }

protected:
    double life;
    double speed;
    double armor;
    QRectF m_boundingRect;
};

#endif // ENEMY_H
