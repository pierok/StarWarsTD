#include "factory.h"
#include "prismtower.h"
#include "plasmatower.h"
#include "hunter.h"

Factory::Factory()
{
}

void Factory::deactivateEnemy(Enemy* e, int type)
{
    if(type==0)
    {
        enemys.enqueue(e);
    }else if(type==1)
    {
        xwings.enqueue(e);
    }
}

Enemy* Factory::getEnemy(int type)
{
    if(type==0)
    {
        if(!enemys.isEmpty())
        {
            Enemy* e=enemys.dequeue();
            e->reset();
            e->show();
            e->resetTransform();
            e->death=false;
            return e;
        }else
        {
            Enemy* e=new Enemy();
            Arena::spawnEnemy.enqueue(e);
            return e;
        }
    }else if( type==1)
    {
        if(!xwings.isEmpty())
        {
            Enemy* e=xwings.dequeue();
            e->reset();
            e->show();
            e->resetTransform();
            e->death=false;
            return e;
        }else
        {
            Enemy* xwing=new Xwing();
            Arena::spawnEnemy.enqueue(xwing);
            return xwing;
        }
    }
    return NULL;
}


void Factory::deactivateTower(Tower* t, int type)
{
    if(type==0)
    {
        t->hide();
        //std::cout<<"Deactive prism"<<std::endl;
        prismTowers.enqueue(t);
    }else if(type==1)
    {
        t->hide();
        //std::cout<<"Deactive plasma"<<std::endl;
        plasmaTowers.enqueue(t);
    }else if(type==2)
    {
        t->hide();
        //std::cout<<"Deactive HUnter"<<std::endl;
        hunterTowers.enqueue(t);
    }
}

Tower* Factory::getTower(int type)
{
    if(type==0)
    {
        if(!prismTowers.isEmpty())
        {
            Tower* e=prismTowers.dequeue();
            e->reset();
            e->show();
            e->resetTransform();
            return e;
        }else
        {
            PrismTower* e=new PrismTower();

            Prism* missile=new Prism();
            e->addPrism(missile);

            Arena::spawnMissile.enqueue(missile);
            Arena::spawnTower.enqueue(e);
            return e;
        }
    }else if( type==1)
    {
        if(!plasmaTowers.isEmpty())
        {
            //std::cout<<"get Plasma"<<std::endl;
            Tower* e=plasmaTowers.dequeue();
            e->reset();
            e->show();
            e->resetTransform();
            return e;
        }else
        {
            //std::cout<<"new Plasma"<<std::endl;
            Tower* e=new PlasmaTower();
            Arena::spawnTower.enqueue(e);
            return e;
        }
    }else if( type==2)
    {
        if(!hunterTowers.isEmpty())
        {
            //std::cout<<"get Hunter"<<std::endl;
            Tower* e=hunterTowers.dequeue();
            e->reset();
            e->show();
            e->resetTransform();
            return e;
        }else
        {
            //std::cout<<"new Hunter"<<std::endl;
            Tower* e=new Hunter();
            Arena::spawnTower.enqueue(e);
            return e;
        }
    }

    return NULL;
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
    }else if(type==2)
    {
        plasma.enqueue(m);
    }else if(type==3)
    {
        hlaser.enqueue(m);
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
        if(!lasers.isEmpty())
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
    }else if(type==2)
    {
        if(!plasma.isEmpty())
        {
            Missile *m=plasma.dequeue();
            m->reset();
            m->show();
            m->resetTransform();
            return m;
        }else
        {
            Missile *m=new Plasma();
            Arena::spawnMissile.enqueue(m);
            return m;
        }
    }else if(type==3)
    {
        if(!hlaser.isEmpty())
        {
            Missile *m=hlaser.dequeue();
            m->reset();
            m->show();
            m->resetTransform();
            return m;
        }else
        {
            Missile *m=new HLaser();
            Arena::spawnMissile.enqueue(m);
            return m;
        }
    }
    return NULL;
}
