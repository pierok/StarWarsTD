#ifndef OSOBNIK_H
#define OSOBNIK_H

#include <QList>
#include "AI/includes/gen.h"
class Osobnik
{
public:
    Osobnik();
    void addGen(Gen* gen)
    {
        gens.push_back(gen);
    }
private:
    QList<Gen*> gens;
};


#endif // CHROMOSOM_H
