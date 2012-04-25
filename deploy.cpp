#include "deploy.h"

Deploy::Deploy()
{
    m_boundingRect=QRectF(0,0,200,200);
    timer=0;
    count=20;
}

void Deploy::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setPen(QPen(Qt::black));
    painter->setBrush(Qt::black);
    painter->drawEllipse(0,0,200,200);
}

QRectF Deploy::boundingRect() const
{
    return m_boundingRect;
}

void Deploy::setBoundingRect(QRectF rect)
{
    m_boundingRect=rect;
}

void Deploy::deploy()
{
    if(count>0)
    {
        if(timer==0)
        {

            Enemy* tmp;
            if(enemy==0)
            {
                timer=80;
                tmp= new Enemy();
            }else if(enemy==1)
            {
                timer=30;
                tmp= new Xwing();
            }
            tmp->setPos(this->scenePos());
            tmp->translate(100,100);
            Arena::spawnEnemy.enqueue(tmp);
            count--;
        }

        if(timer>0)
        {
            timer--;
        }
    }
}
