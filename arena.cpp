#include "arena.h"
#include "tower.h"
#include "prismtower.h"
#include "plasmatower.h"
#include "lifebar.h"
#include <iostream>

QQueue<Enemy*> Arena::spawnEnemy;
QQueue<Explosion*> Arena::spawnExplosion;
QQueue<Missile*> Arena::spawnMissile;

Factory Arena::factoy;

Arena::Arena(QPixmap *p)
{
    gun=A_NONE;
    qp=p;
    amount=800;

    LifeBar* l= new LifeBar(1000,250);

    this->addPixmap(*qp);

    deathStar= new DeathStar();
    deathStar->setPos(qp->size().width()/2,qp->size().height()/2);
    deathStar->setLifeBar(l);
    deathStar->deactive=false;

    l->setPos(deathStar->scenePos());
    l->translate(-250,170);


    gen1=new Generator();
    gen2=new Generator();

    LifeBar* lifgen1=new LifeBar(250,100);
    LifeBar* lifgen2=new LifeBar(250,100);

    gen1->setLifeBar(lifgen1);
    gen2->setLifeBar(lifgen2);

    gen1->setPos(600,1300);

    gen2->setPos(qp->size().width()-500,qp->size().height()-200);

    lifgen1->setPos(gen1->scenePos());
    lifgen1->translate(-180,100);

    lifgen2->setPos(gen2->scenePos());
    lifgen2->translate(-180,100);

    deploy1=new Deploy();
    deploy1->deployEnemy(0);
    deploy1->setPos(60,60);
    deploy1->setRate(80);
    deploy1->deploySize(20);

    deploy2=new Deploy();

    deploy2->deployEnemy(1);
    deploy2->setPos(qp->size().width()-500,60);
    deploy2->setRate(20);
    deploy2->deploySize(20);


    this->addLine(deploy1->scenePos().x()+100,deploy1->scenePos().y()+100,
                  gen1->scenePos().x(),gen1->scenePos().y(),QPen(Qt::gray,2));

    this->addLine(deploy2->scenePos().x()+100,deploy2->scenePos().y()+100,
                  gen1->scenePos().x(),gen1->scenePos().y(),QPen(Qt::gray,2));

    this->addLine(gen1->scenePos().x(),gen1->scenePos().y(),
                  gen2->scenePos().x(),gen2->scenePos().y(),QPen(Qt::gray,2));

    this->addLine(gen2->scenePos().x(),gen2->scenePos().y(),
                  deathStar->scenePos().x(),deathStar->scenePos().y(),QPen(Qt::gray,2));

    this->addEllipse(deathStar->scenePos().x()-300,deathStar->scenePos().y()-300,600,600,
                     QPen(QColor(240,0,0,100),2),QBrush(QColor(255,0,0,40)));


    this->addItem(deploy1);
    this->addItem(deploy2);
    this->addItem(gen1);
    this->addItem(gen2);
    this->addItem(lifgen1);
    this->addItem(lifgen2);
    this->addItem(deathStar);
    this->addItem(l);
}

void Arena::step()
{
    if(deathStar->deactive==false)
    {
        deathStar->step();
        if(deathStar->life<=0)
        {
            Explosion* exp=factoy.getExplosion(1000);
            exp->setPos(deathStar->scenePos());
            deathStar->hide();
            deathStar->deactive=true;
            foreach(Enemy *enemy, enemys)
            {
                enemy->hit(10000);
            }

            foreach(Tower *tower, towers)
            {
                tower->reset();
            }

            deploy1->stop();
            deploy2->stop();
        }
    }

    if(gen1->deactive==false)
    {
        gen1->step();
        if(gen1->life<=0)
        {
            Explosion* exp=factoy.getExplosion(300);
            exp->setPos(gen1->scenePos());
            gen1->hide();
            gen1->deactive=true;

            foreach(Enemy *enemy, enemys)
            {
                enemy->setTarget(gen2);
            }
        }
    }

    if(gen2->deactive==false)
    {
        gen2->step();
        if(gen2->life<=0)
        {
            Explosion* exp=factoy.getExplosion(300);
            exp->setPos(gen2->scenePos());
            gen2->hide();
            gen2->deactive=true;

            foreach(Enemy *enemy, enemys)
            {
                enemy->setTarget(deathStar);
            }
        }
    }

    deploy1->deploy();
    deploy2->deploy();

    while(!spawnEnemy.empty())
    {
        Enemy* en1= spawnEnemy.dequeue();
        en1->setTarget(gen1);//(deathStar);
        this->addItem(en1);
        enemys.insert(en1);
    }

    foreach(Enemy *enemy, enemys)
    {
        if(enemy->death==false)
        {
            enemy->control();
            enemy->physics();
            enemy->step();
        }
    }

    foreach(Tower *tower, towers)
    {
        foreach(Enemy *enemy, enemys)
        {
            if(enemy->death==false)
            {
                if(tower->inRange(enemy))
                {
                    //break;
                }
            }
        }
        tower->control();
    }


    while(!spawnExplosion.empty())
    {
        Explosion* exp= spawnExplosion.dequeue();
        this->addItem(exp);
        explosions.push_back(exp);
    }

    foreach(Explosion *exp, explosions)
    {
        if(exp->deactive==false)
            exp->control();
    }

    while(!spawnMissile.empty())
    {
        Missile* misile= spawnMissile.dequeue();
        this->addItem(misile);
        missiles.insert(misile);
    }

    foreach(Missile *misile, missiles)
    {
        if(misile->deactive==false)
        {
            misile->control();
            misile->physics();
            misile->step();
            if(!misile->isEnemy)
            {
                foreach(Enemy* enemy, enemys)
                {
                    if(enemy->death==false&&enemy->isCollide(misile->scenePos().x(),misile->scenePos().y()))
                    {
                        enemy->hit(misile->getDamage());
                        misile->deactive=true;
                        misile->hide();
                        factoy.deactivateMissile(misile,2);

                        Explosion* exp=factoy.getExplosion(20);
                        exp->setPos(misile->scenePos());
                    }
                }
            }
        }
    }
}

void Arena::wheelEvent( QGraphicsSceneWheelEvent *event )
{
    event->accept();
}

void Arena::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(amount>0)
    {

        int x=event->scenePos().x();
        int y=event->scenePos().y();

        if((deathStar->scenePos().x()-x)*(deathStar->scenePos().x()-x)
                +(deathStar->scenePos().y()-y)*(deathStar->scenePos().y()-y)<=300*300)
        {
            std::cout<<" brak dostepu"<<std::endl;
        }else
        {
            if(gun==A_PRISM)
            {
                PrismTower* prism1= new PrismTower();

                prism1->setPos(event->scenePos().x(),event->scenePos().y());

                prism1->setRadius(300);
                prism1->setBoundingRect(QRectF(-150,-150,300,300));

                Prism* missile=new Prism();
                prism1->addPrism(missile);

                towers.insert(prism1);
                this->addItem(prism1);
                this->addItem(missile);

                amount-=prism1->getCost();
                info->setNum(amount);
            }else if(gun==A_PLASMA)
            {
                PlasmaTower* plasma= new PlasmaTower();
                plasma->setPos(event->scenePos().x(),event->scenePos().y());
                plasma->setRadius(700);
                plasma->setBoundingRect(QRectF(-150,-150,300,300));
                this->addItem(plasma);
                towers.insert(plasma);

                amount-=plasma->getCost();
                info->setNum(amount);
            }
        }
    }else
    {
        std::cout<<"Brak kredytow1"<<std::endl;
        *info=QString("Brak kredytow");
    }
    event->accept();
}
