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

Missile* Factory::getMissile()
{
    /*if(!missile.isEmpty())
    {
        Missile *m=missile.dequeue();
        m->reset();
        m->show();
        return m;
    }else
    {*/
        Missile *m=new Missile();
        Arena::spawnMissile.enqueue(m);
        return m;
    //}
}
