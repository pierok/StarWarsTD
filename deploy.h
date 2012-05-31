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
    void deploy(Target* target);
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

    inline void setTargets(Target* t1, Target* t2, Target* t3)
    {
        target1=t1;
        target2=t2;
        target3=t3;
    }

    int timer;
    int count;
private:
    Target* target1;
    Target* target2;
    Target* target3;
    int rate;
    int enemy;
    bool startDeploy;
    QRectF m_boundingRect;
};

#endif // DEPLOY_H
