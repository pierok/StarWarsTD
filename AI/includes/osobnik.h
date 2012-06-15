#ifndef OSOBNIK_H
#define OSOBNIK_H

#include <QList>
#include "AI/includes/gen.h"
class Osobnik
{
public:
    Osobnik()
    {
        rozmiar=0;
        przystosowanie=0;
    }

    QList<Gen*> chromosom;
    double przystosowanie;
    int rozmiar;
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
