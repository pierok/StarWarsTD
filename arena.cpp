#include "arena.h"
#include "tower.h"
#include "prismtower.h"
#include "plasmatower.h"
#include "hunter.h"
#include "lifebar.h"
#include <iostream>

QQueue<Enemy*> Arena::spawnEnemy;
QQueue<Explosion*> Arena::spawnExplosion;
QQueue<Missile*> Arena::spawnMissile;
QQueue<Tower*> Arena::spawnTower;

Factory Arena::factoy;
Mode Arena::mode=GAME;

Arena::Arena(QPixmap *p)
{
    gun=A_NONE;
    qp=p;
    amount=800;
    osobnik=0;
    epoka=0;
    time=0;

    LifeBar* l= new LifeBar(1000,250);

    //this->addPixmap(*qp);

    //this->setBackgroundBrush(QBrush(QImage(":/data/gw.jpg")));

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

    this->addLine(deploy2->scenePos().x()+100,deploy2->scenePos().y()+100,
                  gen2->scenePos().x(),gen2->scenePos().y(),QPen(Qt::gray,2));

    this->addLine(gen1->scenePos().x(),gen1->scenePos().y(),
                  gen2->scenePos().x(),gen2->scenePos().y(),QPen(Qt::gray,2));

    this->addLine(gen2->scenePos().x(),gen2->scenePos().y(),
                  deathStar->scenePos().x(),deathStar->scenePos().y(),QPen(Qt::gray,2));

    this->addLine(deploy1->scenePos().x()+100,deploy1->scenePos().y()+100,
                  deathStar->scenePos().x(),deathStar->scenePos().y(),QPen(Qt::gray,2));

    this->addLine(deploy2->scenePos().x()+100,deploy2->scenePos().y()+100,
                  deathStar->scenePos().x(),deathStar->scenePos().y(),QPen(Qt::gray,2));

    this->addEllipse(deathStar->scenePos().x()-300,deathStar->scenePos().y()-300,600,600,
                     QPen(QColor(240,0,0,100),2),QBrush(QColor(255,0,0,40)));

    this->addEllipse(deploy1->scenePos().x()-200,deploy1->scenePos().y()-200,600,600,
                     QPen(QColor(240,0,0,100),2),QBrush(QColor(255,0,0,40)));

    this->addEllipse(deploy2->scenePos().x()-200,deploy2->scenePos().y()-200,600,600,
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

void Arena::towerOperation()
{

   // std::cout<<"TOWER START"<<std::endl;
    while(!spawnTower.empty())
    {
        Tower* tower = spawnTower.dequeue();
        this->addItem(tower);
        towers.insert(tower);
    }

    foreach(Tower *tower, towers)
    {
        if(tower->deactive==false)
        {
            foreach(Enemy *enemy, enemys)
            {
                if(enemy->death==false)
                {
                    if(tower->inRange(enemy))
                    {
                        break;
                    }
                }
            }
            tower->control();
        }
    }
    //std::cout<<"TOWER STOP"<<std::endl;
}


void Arena::enemyOperation()
{
   // std::cout<<"ENEMY START"<<std::endl;
    while(!spawnEnemy.empty())
    {
        Enemy* en1= spawnEnemy.dequeue();
        if(gen1->deactive==true)
        {
            en1->setTarget(gen2);
        }else if(gen2->deactive==true)
        {
            en1->setTarget(deathStar);
        }else
        {
            en1->setTarget(gen1);
        }

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

   // std::cout<<"ENEMY STOP"<<std::endl;
}

void Arena::explosionsOperation()
{
    // std::cout<<"EXP START"<<std::endl;
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
   // std::cout<<"EXP STOP"<<std::endl;
}

void Arena::missilesOperation()
{
   // std::cout<<"MISSILE START"<<std::endl;

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
                        factoy.deactivateMissile(misile,misile->getID());

                        Explosion* exp=factoy.getExplosion(20);
                        exp->setPos(misile->scenePos());
                    }
                }
            }
        }
    }
   // std::cout<<"MISSILE STOP"<<std::endl;
    //std::cout<<"missiles size: "<<missiles.size()<<std::endl;
}


void Arena::deathStarOperatin()
{

   //  std::cout<<"STAR GEN1 GEN2 START"<<std::endl;

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


   // std::cout<<"STAR GEN1 GEN2 STOP"<<std::endl;
}

void Arena::step()
{

    //std::cout<<"STEP START"<<std::endl;

    if(deathStar->deactive==false||Arena::mode==GAME)
    {
        deathStarOperatin();
        enemyOperation();
        towerOperation();
        explosionsOperation();
        missilesOperation();
    }

    if(Arena::mode==GAME)
    {
        if(deathStar->deactive==true)
        {
            foreach(QGraphicsItem* item ,items())
            {
                item->hide();

            }
            std::cout<<"koniec gry"<<std::endl;

        }
    }else if(Arena::mode==LEARN)
    {
        std::cout<<"LEARN MODE START"<<std::endl;
        ++time;
        if(deathStar->deactive==true||(deploy1->count==0&&deploy2->count==0))
        {
            std::cout<<"============LEARN MODE START2============="<<std::endl;
            deploy1->stop();
            deploy2->stop();
            foreach(Enemy* enemy, enemys)
            {
                enemy->hit(10000);
                enemy->setTarget(gen1);
            }

            foreach(Tower* tower, towers)
            {
                tower->deactive=true;
                factoy.deactivateTower(tower,tower->ID);
                tower->hide();
            }

            deathStar->life=1000;
            deathStar->show();
            deathStar->showLifeBar();
            deathStar->deactive=false;
            gen1->life=250;
            gen1->show();
            gen1->showLifeBar();
            gen1->deactive=false;
            gen2->life=250;
            gen2->show();
            gen2->showLifeBar();
            gen2->deactive=false;
            amount=800;
            info->setNum(amount);
            nPopulacja->populacja[osobnik]->przystosowanie=deathStar->life+gen1->life+gen2->life;


            ++osobnik;
            std::cout<<"==========TEST============== "<<osobnik<<std::endl;
            if(osobnik<nPopulacja->populacja.size())
            {
                infoOs->setNum(osobnik);
                nastepnyOsobnik();
                std::cout<<"osobniek: "<<osobnik<<std::endl;

            }else
            {
                //ag->update();

                osobnik=0;
                ++epoka;
                nastepnyOsobnik();
                infoPokolenie->setNum(epoka);
                infoOs->setNum(osobnik);
                std::cout<<"epoka: "<<epoka<<std::endl;
            }

            std::cout<<"==========TEST2============== "<<osobnik<<std::endl;
            deploy1->setRate(80);
            deploy1->timer=0;
            deploy1->deploySize(10);
            deploy1->start();

            deploy2->setRate(15);
            deploy2->timer=0;
            deploy2->deploySize(10);
            deploy2->start();
            //std::cout<<"tower size: "<<towers.size()<<std::endl;

              std::cout<<"============LEARN MODE STOP============="<<std::endl;
        }
        std::cout<<"LEARN MODE STOP"<<std::endl;
    }
    std::cout<<"items size: "<<items().size()<<std::endl;


   // std::cout<<"STEP STOP"<<std::endl;
}

void Arena::wheelEvent( QGraphicsSceneWheelEvent *event )
{
    event->accept();
}

void Arena::nastepnyOsobnik()
{

    std::cout<<"==============================NASTEPNY OSOBNIK START"<<std::endl;

    Osobnik* os=nPopulacja->populacja[osobnik];

    foreach(Gen* gen, os->chromosom)
    {
        if(gen->getTowerType()==1)
        {
            setGun(A_PRISM);
            addTower(gen->getTowerX(),gen->getTowerY());
        }else if(gen->getTowerType()==2)
        {
            setGun(A_PLASMA);
            addTower(gen->getTowerX(),gen->getTowerY());
        }else if(gen->getTowerType()==3)
        {
            setGun(A_HUNTER);
            addTower(gen->getTowerX(),gen->getTowerY());
        }
    }


    std::cout<<"==============================NASTEPNY OSOBNIK STOP"<<std::endl;
}

void Arena::addTower(int X, int Y)
{
    std::cout<<"ADD TOWER START"<<std::endl;
    if(amount>0)
    {
        int x=X;
        int y=Y;
        if(x>50&&x<2600&&y>50&&y<2600)
        {

            if((deathStar->scenePos().x()-x)*(deathStar->scenePos().x()-x)
                    +(deathStar->scenePos().y()-y)*(deathStar->scenePos().y()-y)<=300*300)
            {
                std::cout<<" brak dostepu 1"<<std::endl;
            }else if((deploy1->scenePos().x()-x)*(deploy1->scenePos().x()-x)
                     +(deploy1->scenePos().y()-y)*(deploy1->scenePos().y()-y)<=300*300)
            {
                std::cout<<" brak dostepu 2"<<std::endl;
            }else if((deploy2->scenePos().x()-x)*(deploy2->scenePos().x()-x)
                     +(deploy2->scenePos().y()-y)*(deploy2->scenePos().y()-y)<=300*300)
            {
                std::cout<<" brak dostepu 3"<<std::endl;
            }
            else
            {
                if(gun==A_PRISM)
                {
                    PrismTower* prism1= new PrismTower();

                    prism1->setPos(x,y);

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
                    Tower* plasma= factoy.getTower(1);// new PlasmaTower();
                    plasma->setPos(x,y);
                    plasma->setRadius(500);
                    plasma->setBoundingRect(QRectF(-150,-150,300,300));
                    //this->addItem(plasma);
                    //towers.insert(plasma);

                    amount-=plasma->getCost();
                    info->setNum(amount);
                }else if(gun==A_HUNTER)
                {
                    Tower* hunter=  factoy.getTower(2);
                    hunter->setPos(x,y);
                    hunter->setRadius(300);
                    hunter->setBoundingRect(QRectF(-150,-150,300,300));
                    //this->addItem(hunter);
                    //towers.insert(hunter);

                    amount-=hunter->getCost();
                    info->setNum(amount);
                }
            }
        }
    }else
    {
        std::cout<<"Brak kredytow1"<<std::endl;
        *info=QString("Brak kredytow");
    }

    std::cout<<"ADD TOWER STOP"<<std::endl;
}

void Arena::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    int x=event->scenePos().x();
    int y=event->scenePos().y();

    addTower(x,y);
    event->accept();
}
