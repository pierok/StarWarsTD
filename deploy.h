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
    inline void deployEnemy(int i)
    {
        enemy=i;
    }

    inline void start()
    {
        startDeploy=true;
    }

    inline void stop()
    {
        startDeploy=false;
    }

    inline void deploySize(int i)
    {
        count=i;
    }

    inline void setRate(int rate)
    {
        this->rate=rate;
    }

private:
    int rate;
    int enemy;
    int count;
    int timer;
    bool startDeploy;
    QRectF m_boundingRect;
};

#endif // DEPLOY_H
