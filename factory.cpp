#include "factory.h"

Factory::Factory()
{
}

Enemy* Factory::getEnemy()
{
    if(!enemys.isEmpty())
    {
        return enemys.dequeue();
    }else
    {
        return new Enemy;
    }
}

Explosion* Factory::getExplosion(int size)
{
    if(!explosions.isEmpty())
    {
        Explosion *exp=explosions.dequeue();
        exp->setSize(size);
        return exp;
    }else
    {
        Explosion *exp=new Explosion(size);
        exp->setSize(size);
        Arena::spawnExplosion.enqueue(exp);
        return exp;
    }
}

void Factory::deactivateMissile(Missile*m, int type)
{
    if(type==0)
    {
        missile.enqueue(m);
    }else if(type==1)
    {
        lasers.enqueue(m);
    }
}

Missile* Factory::getMissile(int type)
{
    if(type==0)
    {
        if(!missile.isEmpty())
        {
            Missile *m=missile.dequeue();
            m->reset();
            m->show();
            m->resetTransform();
            return m;
        }else
        {
            Missile *m=new Missile();
            Arena::spawnMissile.enqueue(m);
            return m;
        }
    }else if(type==1)
    {
        if(!missile.isEmpty())
        {
            Missile *m=lasers.dequeue();
            m->reset();
            m->show();
            m->resetTransform();
            return m;
        }else
        {
            Missile *m=new Laser();
            Arena::spawnMissile.enqueue(m);
            return m;
        }

    }
    return NULL;
}
