#ifndef CHROMOSOM_H
#define CHROMOSOM_H

#include <QList>
#include "AI/includes/gen.h"
class Chromosom
{
public:
    Chromosom();
    void addGen(Gen* gen)
    {
        gens.push_back(gen);
    }
private:
    QList<Gen*> gens;
};


#endif // CHROMOSOM_H
