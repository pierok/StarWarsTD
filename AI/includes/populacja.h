#ifndef POPULACJA_H
#define POPULACJA_H

#include<QVector>
#include<QTime>
#include"AI/includes/osobnik.h"

class Populacja
{
public:
    Populacja(int s, int p):size(s)
    {
        //amount=800;
        osobnikSize=100;
        proporcja=size/p;
        qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));

        for(int i=0;i<proporcja;++i)
        {
            wynikSelekcji.push_back(new Osobnik);
        }

        generujPopujacje();

    }


    Populacja(int s, int o, int p):size(s),osobnikSize(o)
    {
        //amount=800;

        proporcja=size/p;
        qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
        generujPopujacje();
    }




    inline int rozmiar()
    {
        return size;
    }

    void generujPopujacje()
    {
        for(int i=0; i<size; ++i)
        {
            Osobnik* osobnik= new Osobnik();
            for(int i=0; i<osobnikSize; ++i)
            {
                int type=qrand()%3+1;

                int x=qrand()%2680;
                int y=qrand()%2680;

                Gen* gen= new Gen();
                gen->resetGen();
                gen->setTowerType(type);
                gen->setTowerX(x);
                gen->setTowerY(y);
                osobnik->chromosom.push_back(gen);
            }

            //amount=800;
            osobnik->rozmiar=osobnik->chromosom.size();
            populacja.push_back(osobnik);
        }
    }

    QVector<Osobnik*> populacja;
    QVector<Osobnik*> wynikSelekcji;

    int proporcja;



private:
    int amount;
    int size;
    int osobnikSize;
};


class PopulacjaOf
{
public:
    PopulacjaOf(int s):size(s)
    {

        qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
        generujPopujacje();
    }


    QVector<OsobnikOf*> populacja;

    inline int rozmiar()
    {
        return size;
    }


    void generujPopujacje()
    {
        for(int i=0; i<size; ++i)
        {
            OsobnikOf* osobnik= new OsobnikOf();
            for(int i=0; i<2; ++i)
            {
                int type=qrand()%2;

                int x=qrand()%2680;
                int y=qrand()%2680;

                int target=qrand()%3;

                GenOf* gen= new GenOf();
                gen->resetGen();
                gen->setEnemyType(type);
                gen->setDeployX(x);
                gen->setDeployY(y);
                gen->setTarget(target);
                osobnik->chromosom.push_back(gen);
            }

            //amount=800;
            osobnik->rozmiar=osobnik->chromosom.size();
            populacja.push_back(osobnik);
        }
    }




private:
    int size;
};

#endif // POPULACJA_H
