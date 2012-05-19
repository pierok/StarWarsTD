#ifndef ALGORYTMGENETYCZNY_H
#define ALGORYTMGENETYCZNY_H
#include "populacja.h"


class AlgorytmGenetyczny
{
public:
    AlgorytmGenetyczny(Populacja *pop);

    void mutacja();
    void mutacja2();
    void krzyzowanie();
    void selekcja();

    void update()
    {
        selekcja();
        krzyzowanie();
        mutacja();
        mutacja2();
        ++pokolenie;
    }

    int pokolenie;

private:
    Populacja* populacja;

};



#endif // ALGORYTMGENETYCZNY_H
