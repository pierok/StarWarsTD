#ifndef DEPLOY_H
#define DEPLOY_H

#include <QGraphicsItem>
#include <QPainter>
#include <QStyleOption>
#include "enemy.h"
#include "arena.h"


class Deploy: public QGraphicsItem
{
public:
    Deploy();
    void deploy();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);

    QRectF boundingRect() const;
    void setBoundingRect(QRectF);

private:
    int count;
    int timer;
    QRectF m_boundingRect;
};

#endif // DEPLOY_H
