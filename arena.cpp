#include "arena.h"
#include "tower.h"
#include "prismtower.h"
#include "plasmatower.h"
#include "hunter.h"
#include "lifebar.h"
#include <iostream>
#include <QFile>
#include <QTextStream>

QQueue<Enemy*> Arena::spawnEnemy;
QQueue<Explosion*> Arena::spawnExplosion;
QQueue<Missile*> Arena::spawnMissile;
QQueue<Tower*> Arena::spawnTower;
QQueue<Deploy*> Arena::factoryDeploys;

Factory Arena::factoy;
Mode Arena::mode=GAME;
bool Arena::Hide=false;
//int Arena::enemySize=0;

Arena::Arena(QPixmap *p)
{
    gun=A_NONE;
    qp=p;
    amountSize=800;
    amount=amountSize;
    osobnik=0;
    epoka=0;
    time=0;

    wagaStarLife=1;
    wagaGen1Life=1;
    wagaGen2Life=1;
    wagaAmountLife=0;


    LifeBar* l= new LifeBar(1000,250);

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


    init();

    this->addEllipse(deathStar->scenePos().x()-300,deathStar->scenePos().y()-300,600,600,
                     QPen(QColor(240,0,0,100),2),QBrush(QColor(255,0,0,40)));

    this->addItem(gen1);
    this->addItem(gen2);
    this->addItem(lifgen1);
    this->addItem(lifgen2);
    this->addItem(deathStar);
    this->addItem(l);


}



void Arena::init()
{

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


    deploys.push_back(deploy1);
    deploys.push_back(deploy2);

    foreach(Deploy* deploy, deploys)
    {
        //deploy->stop();
        factoryDeploys.enqueue(deploy);
    }


    this->addEllipse(deploy1->scenePos().x()-200,deploy1->scenePos().y()-200,600,600,
                     QPen(QColor(240,0,0,100),2),QBrush(QColor(255,0,0,0)));

    this->addEllipse(deploy2->scenePos().x()-200,deploy2->scenePos().y()-200,600,600,
                     QPen(QColor(240,0,0,100),2),QBrush(QColor(255,0,0,0)));


    //target=gen1;

    deploy1->setTargets(gen1,gen2,deathStar);
    deploy2->setTargets(gen2,gen1,deathStar);

    this->addItem(deploy1);
    this->addItem(deploy2);

}


void Arena::directions()
{

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
}



void Arena::towerOperation()
{
    while(!spawnTower.empty())
    {
        Tower* tower = spawnTower.dequeue();
        this->addItem(tower);
        towers.insert(tower);
        if(Hide)
        {
            tower->hide();
        }

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
}


void Arena::enemyOperation()
{
    while(!spawnEnemy.empty())
    {
        Enemy* en1= spawnEnemy.dequeue();

        //en1->setTarget(target);

        this->addItem(en1);
        enemys.insert(en1);
        if(Hide)
        {
            en1->hide();
        }
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

}

void Arena::explosionsOperation()
{
    while(!spawnExplosion.empty())
    {
        Explosion* exp= spawnExplosion.dequeue();
        this->addItem(exp);
        explosions.push_back(exp);
        if(Hide)
        {
            exp->hide();
        }
    }

    foreach(Explosion *exp, explosions)
    {
        if(exp->deactive==false)
            exp->control();
    }
}

void Arena::missilesOperation()
{

    while(!spawnMissile.empty())
    {
        Missile* misile= spawnMissile.dequeue();
        this->addItem(misile);
        missiles.insert(misile);
        if(Hide)
        {
            misile->hide();
        }
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
}

void Arena::deathStarOperatin()
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
            if(mode==GAME)
            {
                foreach(Enemy *enemy, enemys)
                {
                    enemy->hit(10000);
                }
            }

            foreach(Tower *tower, towers)
            {
                tower->reset();
            }


            foreach(Deploy* deploy, deploys)
            {
                deploy->stop();
            }

            //deploy1->stop();
            //deploy2->stop();
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
                if(gen2->deactive==true)
                {
                    enemy->setTarget(deathStar);
                }else
                    enemy->setTarget(gen2);
            }
            //target=gen2;
        }

        deathStar->heal(1);

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
                if(gen1->deactive==true)
                {
                    enemy->setTarget(deathStar);
                }else
                    enemy->setTarget(gen1);
            }
            //target=deathStar;
        }

        deathStar->heal(1);
    }

    //deploy1->deploy(target);
    //deploy2->deploy(target);

    foreach(Deploy* deploy, deploys)
    {
        deploy->deploy();
    }

}

void Arena::step()
{
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
            /*foreach(QGraphicsItem* item ,items())
            {
                item->hide();

            }*/
            std::cout<<"koniec gry"<<std::endl;

        }
    }else if(Arena::mode==LEARN)
    {
        ++time;

        int enemyDeathSize=0;
        foreach(Enemy* enemy, enemys)
        {
            if(enemy->death==true)
            {
                ++enemyDeathSize;

            }
        }

        if(deathStar->deactive==true||enemyDeathSize==enemys.size())//||(deploy1->count==0&&deploy2->count==0))
        {
            nPopulacja->populacja[osobnik]->przystosowanie=wagaStarLife*deathStar->life+wagaGen1Life*gen1->life
                                                            +wagaGen2Life*gen2->life+wagaAmountLife*(1000/amountSize);

            if(enemyDeathSize==enemys.size())
            {
                std::cout<<"write to file"<<std::endl;
                QFile file("out.txt");
                if (!file.open(QIODevice::Append| QIODevice::Text))
                    return;

                QTextStream out(&file);
                out << "osobnik "<<nPopulacja->populacja[osobnik]->przystosowanie<<" "<<amountSize<<"\n" ;
                foreach(Gen* gen, nPopulacja->populacja[osobnik]->chromosom)
                {
                    out<<gen->getGenom()<<"\n";
                }
                out << "endOsobnik\n";

                file.close();
            }

            foreach(Deploy* deploy, deploys)
            {
                deploy->stop();
            }

            foreach(Enemy* enemy, enemys)
            {
                enemy->hit(10000);
                //enemy->setTarget(gen1);
            }

            foreach(Tower* tower, towers)
            {
                tower->deactive=true;
                factoy.deactivateTower(tower,tower->ID);
                tower->hide();
            }


            deathStar->life=1000;
            deathStar->getLifeBar()->life=1000;
            deathStar->deactive=false;
            gen1->life=250;
            gen1->getLifeBar()->life=250;
            gen1->deactive=false;
            gen2->life=250;
            gen2->getLifeBar()->life=250;
            gen2->deactive=false;


            if(!Hide)
            {
                deathStar->show();
                deathStar->showLifeBar();
                gen1->show();
                gen1->showLifeBar();
                gen2->show();
                gen2->showLifeBar();
            }




            amount=amountSize;
            info->setNum(amount);

            ++osobnik;
            if(osobnik<nPopulacja->populacja.size())
            {
                std::cout<<"osobniek: "<<osobnik-1<<" size: "<<nPopulacja->populacja[osobnik-1]->chromosom.size()<<"przystosowanei "<<nPopulacja->populacja[osobnik-1]->przystosowanie<<std::endl;
                infoOs->setNum(osobnik);
                nastepnyOsobnik();
            }else
            {
                ag->update();

                osobnik=0;
                ++epoka;
                nastepnyOsobnik();
                infoPokolenie->setNum(ag->pokolenie);
                infoOs->setNum(osobnik);
            }

            //enemySize=0;
            //target=gen1;
            deploy1->setRate(70);
            deploy1->timer=0;
            deploy1->deploySize(20);
            deploy1->start();

            deploy2->setRate(15);
            deploy2->timer=0;
            deploy2->deploySize(30);
            deploy2->start();

        }
    }else if(mode==LEARN2)
    {

        int enemyDeathSize=0;
        foreach(Enemy* enemy, enemys)
        {
            if(enemy->death==true)
            {
                ++enemyDeathSize;

            }
        }

        if(deathStar->deactive==true||enemyDeathSize==enemys.size())
        {

            nPopulacjaOf->populacja[osobnik]->przystosowanie=-deathStar->life-gen1->life-gen2->life;


            if(deathStar->deactive==true)
            {
                std::cout<<"write to file 2"<<std::endl;
                QFile file("out2.txt");
                if (!file.open(QIODevice::Append| QIODevice::Text))
                    return;

                QTextStream out(&file);
                out << "osobnik "<<nPopulacjaOf->populacja[osobnik]->przystosowanie<<"\n" ;
                foreach(GenOf* gen, nPopulacjaOf->populacja[osobnik]->chromosom)
                {
                    out<<gen->getGenom()<<"\n";
                }
                out << "endOsobnik\n";

                file.close();
            }

            foreach(Enemy* enemy, enemys)
            {
                enemy->hit(10000);
                //enemy->setTarget(gen1);
            }



            foreach(Deploy* deploy, deploys)
            {
                deploy->stop();
                factoryDeploys.enqueue(deploy);
            }

            deathStar->life=1000;
            deathStar->getLifeBar()->life=1000;
            if(!Hide)
            {

            }
            deathStar->deactive=false;
            gen1->life=250;
            gen1->getLifeBar()->life=250;

            gen1->deactive=false;
            gen2->life=250;
            gen2->getLifeBar()->life=250;

            gen2->deactive=false;


            if(!Hide)
            {
                deathStar->show();
                deathStar->showLifeBar();
                gen1->show();
                gen1->showLifeBar();
                gen2->show();
                gen2->showLifeBar();
            }


            ++osobnik;
            // enemySize=0;

            if(osobnik<nPopulacjaOf->populacja.size())
            {
                infoOs2->setNum(osobnik);
                nastepnyOsobnikOf();
            }else
            {
                ag->update();

                osobnik=0;
                ++epoka;
                nastepnyOsobnikOf();
                infoPokolenie2->setNum(ag->pokolenie);
                infoOs2->setNum(osobnik);
            }

            foreach(Deploy* deploy, deploys)
            {
                deploy->timer=0;
                deploy->start();
            }
        }
    }
}

void Arena::wheelEvent( QGraphicsSceneWheelEvent *event )
{
    event->accept();
}

void Arena::nastepnyOsobnik()
{

    Osobnik* os=nPopulacja->populacja[osobnik];
    std::cout<<"osobnik size: "<<nPopulacja->populacja[osobnik]->chromosom.size()<<std::endl;

    int i=0;
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
        i++;
    }
}


void Arena::nastepnyOsobnikOf()
{

    OsobnikOf* os=nPopulacjaOf->populacja[osobnik];
    std::cout<<"osobnik size: "<<nPopulacjaOf->populacja[osobnik]->chromosom.size()<<std::endl;

    foreach(GenOf* gen, os->chromosom)
    {
        addDeploy(gen->getDeployX(),gen->getDeployY(),gen->getEnemyType(),gen->getTarget());
    }
}




void Arena::addDeploy(int X, int Y, int type, int target)
{
    Deploy* deploy;//=new Deploy();

    if(factoryDeploys.isEmpty())
    {
        deploy=new Deploy();
        deploys.push_back(deploy);
        this->addItem(deploy);
    }else
    {
        deploy=factoryDeploys.dequeue();
    }


    if(type==0)
    {

        deploy->deployEnemy(type);
        deploy->setPos(X,Y);
        deploy->setRate(70);
        deploy->deploySize(20);

    }else if(type==1)
    {

        deploy->deployEnemy(type);
        deploy->setPos(X,Y);
        deploy->setRate(15);
        deploy->deploySize(30);
    }

    if(target==0)
    {
        deploy->setTargets(gen1,gen2,deathStar);
    }else if(target==1)
    {
        deploy->setTargets(gen2,gen1,deathStar);
    }else if(target==2)
    {
        deploy->setTargets(deathStar,deathStar,deathStar);
    }

}


void Arena::addTower(int X, int Y)
{
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
            }
            else
            {
                if(!deploys.isEmpty())
                {
                    if((deploy1->scenePos().x()-x+100)*(deploy1->scenePos().x()-x+100)
                            +(deploy1->scenePos().y()-y+100)*(deploy1->scenePos().y()-y+100)<=300*300)
                    {
                        std::cout<<" brak dostepu 2"<<std::endl;
                        return ;
                    }else if((deploy2->scenePos().x()-x+100)*(deploy2->scenePos().x()-x+100)
                             +(deploy2->scenePos().y()-y+100)*(deploy2->scenePos().y()-y+100)<=300*300)
                    {
                        std::cout<<" brak dostepu 3"<<std::endl;
                        return ;
                    }
                }


                if(gun==A_PRISM)
                {
                    Tower* prism1= factoy.getTower();

                    prism1->setPos(x,y);

                    prism1->setRadius(300);
                    prism1->setBoundingRect(QRectF(-150,-150,300,300));

                    prism1->reset();

                    amount-=prism1->getCost();
                    info->setNum(amount);
                }else if(gun==A_PLASMA)
                {
                    Tower* plasma= factoy.getTower(1);// new PlasmaTower();
                    plasma->setPos(x,y);
                    plasma->setRadius(500);
                    plasma->setBoundingRect(QRectF(-150,-150,300,300));

                    amount-=plasma->getCost();
                    info->setNum(amount);
                }else if(gun==A_HUNTER)
                {
                    Tower* hunter=  factoy.getTower(2);
                    hunter->reset();
                    hunter->resetTransform();
                    hunter->setPos(x,y);
                    hunter->setRadius(300);
                    hunter->setBoundingRect(QRectF(-150,-150,300,300));

                    amount-=hunter->getCost();
                    info->setNum(amount);
                }
            }
        }/*else
        {
            //std::cout<<"poza zasiegiem: X: "<<x<<" Y: "<<y <<std::endl;
        }*/

    }else
    {
        *info=QString("Brak kredytow");
    }
}

void Arena::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    int x=event->scenePos().x();
    int y=event->scenePos().y();

    addTower(x,y);
    event->accept();
}


void Arena::hideElements()
{
    Hide=true;

    foreach(QGraphicsItem * element, items())
    {
        element->hide();
    }
}

void Arena::showElements()
{

    Hide=false;
    foreach(QGraphicsItem * element, items())
    {
        element->show();
    }
}
