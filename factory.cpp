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
        std::cout<<"new exp"<<std::endl;
        Explosion *exp=new Explosion(size);
        exp->setSize(size);
        //Arena::spawnExplosion(exp);
        return exp;
    }
}

Missile* Factory::getMissile()
{
    return NULL;
}
