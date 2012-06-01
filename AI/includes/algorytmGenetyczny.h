#ifndef ALGORYTMGENETYCZNY_H
#define ALGORYTMGENETYCZNY_H
#include "populacja.h"


class AlgorytmGenetyczny
{
public:
   // AlgorytmGenetyczny(Populacja *pop);

    virtual void mutacja()=0;
    virtual void mutacja2()=0;
    virtual void krzyzowanie()=0;
    virtual void selekcja()=0;

    void update()
    {
        selekcja();
        krzyzowanie();
        mutacja();
        mutacja2();
        ++pokolenie;
    }

    int pokolenie;

protected:
    Populacja* populacja;

};


class AGDef : public AlgorytmGenetyczny
{
public:
    AGDef(Populacja *pop);

    void mutacja();
    void mutacja2();
    void krzyzowanie();
    void selekcja();

};


#endif // ALGORYTMGENETYCZNY_H
