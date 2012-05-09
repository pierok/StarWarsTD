#ifndef POPULACJA_H
#define POPULACJA_H

#include<QVector>
#include"AI/includes/osobnik.h"

class Populacja
{
public:
    Populacja(int s):size(s)
    {
        for(int i=0; i<s; ++i)
        {
            Osobnik* osobnik= new Osobnik();
            osobnik->generujChromosom();
            populacja.push_back(osobnik);
        }
    }

    QVector<Osobnik*> populacja;

private:

    int size;
};


#endif // POPULACJA_H
