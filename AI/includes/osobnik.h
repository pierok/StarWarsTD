#ifndef OSOBNIK_H
#define OSOBNIK_H

#include <QList>
#include "AI/includes/gen.h"
#include <iostream>
class Osobnik
{
public:
    Osobnik()
    {
        rozmiar=0;
        przystosowanie=0;
        pos=0;
        index=0;
    }


    void addGen(int type, int x, int y)
    {
        test_chromosom[0]=test_chromosom[0]|type;
        test_chromosom[0]=test_chromosom[0]<<12;

        test_chromosom[0]=test_chromosom[0]|x;
        test_chromosom[0]=test_chromosom[0]<<12;

        test_chromosom[0]=test_chromosom[0]|y;


        pos=26;
        test_chromosom[0]=test_chromosom[0]<<(32-pos);



    }



   /* Osobnik& operator=(Osobnik const &os)
    {

        this->przystosowanie=os.przystosowanie;
        this->rozmiar=os.rozmiar;


        for(int i=0; i<rozmiar; ++i)
        {
            if(this->chromosom.size()<i)
            {

                Gen* g1= new Gen();
                g1->setGenom(os.chromosom[i]->getGenom());
                this->chromosom.push_back(g1);
            }else
            {
                this->chromosom[i]->setGenom(os.chromosom[i]->getGenom());
            }
        }

        return *this;
    }*/


    void kopiujOsobnika(Osobnik *os)
    {

        this->przystosowanie=os->przystosowanie;
        this->rozmiar=os->rozmiar;

        for(int i=0; i<rozmiar; ++i)
        {
            if(this->chromosom.size()<rozmiar)
            {

                Gen* g1= new Gen();
                g1->setGenom(os->chromosom[i]->getGenom());
                this->chromosom.push_back(g1);
            }else
            {
                this->chromosom[i]->setGenom(os->chromosom[i]->getGenom());
            }
        }
    }


    QList<Gen*> chromosom;
    QList<int> test_chromosom;
    double przystosowanie;
    int rozmiar;

private:
    int pos;
    int index;

};

class OsobnikOf
{
public:
    OsobnikOf()
    {
        rozmiar=0;
        przystosowanie=0;
    }

    QList<GenOf*> chromosom;
    double przystosowanie;
    int rozmiar;
};



#endif // CHROMOSOM_H
