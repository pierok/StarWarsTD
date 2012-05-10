#ifndef OSOBNIK_H
#define OSOBNIK_H

#include <QList>
#include "AI/includes/gen.h"
class Osobnik
{
public:
    Osobnik()
    {
        amount=800;
        przystosowanie=0;
    }

    void generujChromosom();

    QList<Gen*> chromosom;
    double przystosowanie;
private:
    int amount;
};


#endif // CHROMOSOM_H
