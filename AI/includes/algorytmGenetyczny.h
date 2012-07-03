#ifndef ALGORYTMGENETYCZNY_H
#define ALGORYTMGENETYCZNY_H
#include "populacja.h"
#include "selekcja.h"


class AlgorytmGenetyczny
{
public:
   // AlgorytmGenetyczny(Populacja *pop);

    virtual void mutacja()=0;
    virtual void mutacja2()=0;
    virtual void krzyzowanie()=0;

    void update()
    {
        selekcja->selekcja(populacja);
        krzyzowanie();
        //mutacja->mutuj(populacja);
        //mutacja();
        //mutacja2();
        ++pokolenie;
    }


    inline void setSelekcja(Selekcja* s)
    {
        selekcja=s;
    }

    int pokolenie;


protected:
    Populacja* populacja;
    Selekcja* selekcja;
    //Mutacja* mutacja;

};


class AGDef : public AlgorytmGenetyczny
{
public:
    AGDef(Populacja *pop,Selekcja* s);

    void mutacja();
    void mutacja2();
    void krzyzowanie();


};



class AGOf : public AlgorytmGenetyczny
{
public:
    AGOf(PopulacjaOf *pop);

    void mutacja();
    void mutacja2();
    void krzyzowanie();
    void selekcja();

protected:
    PopulacjaOf* populacjaOf;


};



#endif // ALGORYTMGENETYCZNY_H
