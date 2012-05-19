#ifndef ARENA_H
#define ARENA_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QList>
#include <QQueue>
#include <QSet>
#include <QVector>

#include "factory.h"
#include "tower.h"
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
enum Mode {GAME, LEARN};

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

    //static QQueue<Missile*> spawn;

    Deploy* deploy1;
    Deploy* deploy2;

    static Mode mode;
    static int enemySize;
    static Factory factoy;
    static QQueue<Enemy*> spawnEnemy;
    static QQueue<Explosion*> spawnExplosion;
    static QQueue<Missile*> spawnMissile;
    static QQueue<Tower*>spawnTower;

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

    void addTower(int x, int y);
    void nastepnyOsobnik();
    Populacja* nPopulacja;
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

    QSet<Tower*> towers;
    QSet<Enemy*> enemys;
    QSet<Missile*> missiles;
    QList<Explosion*> explosions;

    int amount;
    int time;
    int osobnik;
    int epoka;

public slots:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void wheelEvent( QGraphicsSceneWheelEvent *event);
};

#endif // ARENA_H
