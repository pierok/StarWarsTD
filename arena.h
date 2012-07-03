#ifndef ARENA_H
#define ARENA_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QList>
#include <QQueue>
#include <QSet>
#include <QVector>

#include "factory.h"
//#include "tower.h"
#include "deathstar.h"
#include "generator.h"
#include "deploy.h"
#include "AI/includes/algorytmGenetyczny.h"

class Tower;
class Deploy;
class Enemy;
class Factory;
class Explosion;
class Missile;

enum GUNS {A_NONE, A_PRISM, A_PLASMA, A_HUNTER};
enum Mode {GAME, LEARN, LEARN2, M_STOP};

class Arena: public QGraphicsScene
{
public:

    Arena(QPixmap *p);
    void step();
    void towerOperation();
    void enemyOperation();
    void missilesOperation();
    void explosionsOperation();
    void deathStarOperatin();
    void hideElements();
    void showElements();
    void init();
    void directions();

    Deploy* deploy1;
    Deploy* deploy2;

    QVector<Deploy*> deploys;

    static Mode mode;
    static bool Hide;
    //static int enemySize;
    static Factory factoy;
    static QQueue<Enemy*> spawnEnemy;
    static QQueue<Explosion*> spawnExplosion;
    static QQueue<Missile*> spawnMissile;
    static QQueue<Tower*>spawnTower;
    static QQueue<Deploy*>factoryDeploys;

    inline void setGun(GUNS g)
    {
        gun=g;
    }

    inline void setInfo(QString* s)
    {
        info=s;
    }

    inline void setInfoOs(QString* s)
    {
        infoOs=s;
    }

    inline void setInfoPokolenie(QString* s)
    {
        infoPokolenie=s;
    }

    inline void setInfoOs2(QString* s)
    {
        infoOs2=s;
    }

    inline void setInfoPokolenie2(QString* s)
    {
        infoPokolenie2=s;
    }


    inline void setAmount(int i)
    {
         amountSize=i;
         amount=amountSize;
    }


    inline int getAmount()
    {
         return amountSize;
    }

    inline int getEpoka()
    {
        return epoka;
    }


    void addTower(int x, int y);
    void addDeploy(int X, int Y, int type, int target);
    void nastepnyOsobnik();
    void nastepnyOsobnikOf();
    Populacja* nPopulacja;
    PopulacjaOf* nPopulacjaOf;
    AlgorytmGenetyczny* ag;


private:
    GUNS gun;
    QPixmap* qp;
    DeathStar* deathStar;
    Generator* gen1;
    Generator* gen2;

    QString* info;
    QString* infoOs;
    QString* infoPokolenie;
    QString* infoOs2;
    QString* infoPokolenie2;

    QSet<Tower*> towers;
    QSet<Enemy*> enemys;
    QSet<Missile*> missiles;
    QList<Explosion*> explosions;

    //Target* target;

    int amount;
    int amountSize;
    int time;
    int osobnik;
    int epoka;

    int wagaStarLife;
    int wagaGen1Life;
    int wagaGen2Life;
    int wagaAmountLife;


public slots:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void wheelEvent( QGraphicsSceneWheelEvent *event);
};

#endif // ARENA_H
