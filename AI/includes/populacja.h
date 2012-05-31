#ifndef POPULACJA_H
#define POPULACJA_H

#include<QVector>
#include<QTime>
#include"AI/includes/osobnik.h"

class Populacja
{
public:
    Populacja(int s):size(s)
    {
        amount=800;
        generujPopujacje();
        qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    }

    QVector<Osobnik*> populacja;

    inline int rozmiar()
    {
        return size;
    }

    void generujPopujacje()
    {
        for(int i=0; i<size; ++i)
        {
            Osobnik* osobnik= new Osobnik();
            for(int i=0; i<100; ++i)
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


private:
    int amount;
    int size;
};


#endif // POPULACJA_H
