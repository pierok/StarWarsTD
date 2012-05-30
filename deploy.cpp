#include "deploy.h"

Deploy::Deploy()
{
    m_boundingRect=QRectF(0,0,200,200);
    timer=0;
    count=20;
    startDeploy=false;
    rate=80;
}

void Deploy::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setPen(QPen(Qt::NoPen));
    painter->setBrush(QColor(0,0,0,120));
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

void Deploy::deploy(Target* target)
{
    if(startDeploy){
        if(count>0)
        {
            if(timer==0)
            {
                Enemy* tmp=NULL;
                if(enemy==0)
                {
                    timer=rate;
                    tmp= Arena::factoy.getEnemy();
                }else if(enemy==1)
                {
                    timer=rate;
                    tmp= Arena::factoy.getEnemy(1);
                }
                tmp->setPos(this->scenePos());
                tmp->translate(100,100);
                tmp->setTarget(target);
                //Arena::spawnEnemy.enqueue(tmp);
                count--;
            }

            if(timer>0)
            {
                timer--;
            }
        }
    }
}
