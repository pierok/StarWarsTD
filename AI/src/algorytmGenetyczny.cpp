#include "AI/includes/algorytmGenetyczny.h"
#include <iostream>

AlgorytmGenetyczny::AlgorytmGenetyczny(Populacja *pop)
{
    populacja=pop;
    pokolenie=0;
}

void AlgorytmGenetyczny::mutacja()
{
    for(int i=0; i<populacja->rozmiar();++i)
    {
        int m=qrand()%100+1;

        if(m<10)
        {
            int iloscM=qrand()%10+1;

            int popSize = popSize = populacja->populacja[i]->chromosom.size();;
            int pos1=0;
            int pos2=0;

            for(int j=0; j<iloscM; ++j)
            {
                pos1=qrand()%popSize;
                pos2=qrand()%popSize;

                Gen* g1=populacja->populacja[i]->chromosom[pos1];
                populacja->populacja[i]->chromosom[pos1]=populacja->populacja[i]->chromosom[pos2];
                populacja->populacja[i]->chromosom[pos2]=g1;
            }
        }
    }
}

void AlgorytmGenetyczny::krzyzowanie()
{
    int rozmiar=populacja->rozmiar();
    int nextCh=rozmiar/2;
    int nextCh2=rozmiar/2+1;

    while(nextCh2<rozmiar)
    {
        int p1=qrand()%rozmiar/2;
        int p2=qrand()%rozmiar/2;

        int m=qrand()%100+1;

        if(m<=40)
        {
            int pos=qrand()%8;

            Osobnik* o1=populacja->populacja[p1];
            Osobnik* o2=populacja->populacja[p2];;

            for(int j=0; j<pos; ++j)
            {

                populacja->populacja[nextCh]->chromosom[j]=o1->chromosom[j];
                populacja->populacja[nextCh2]->chromosom[j]=o2->chromosom[j];
            }

            for(int j=pos; j<populacja->rozmiar(); ++j)
            {
                //populacja->populacja->at(nextCh)->genom[j]=o2->genom[j];
                //populacja->populacja->at(nextCh2)->genom[j]=o1->genom[j];
            }
            nextCh+=2;
            nextCh2+=2;
        }
    }
}

bool osobnikSelect(Osobnik* o1, Osobnik* o2)
{
    return o1->przystosowanie>o2->przystosowanie;
}

void AlgorytmGenetyczny::selekcja()
{
    qSort(populacja->populacja.begin(),populacja->populacja.end(),osobnikSelect);
}

