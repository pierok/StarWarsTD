#include "AI/includes/algorytmGenetyczny.h"
#include <iostream>

AlgorytmGenetyczny::AlgorytmGenetyczny(Populacja *pop)
{
    populacja=pop;
    pokolenie=0;
}

void AlgorytmGenetyczny::mutacja()
{
    std::cout<<"mutacja"<<std::endl;
    for(int i=0; i<populacja->rozmiar();++i)
    {
        int m=qrand()%100+1;

        //if(m<=50)
        //{
           int popSize = populacja->populacja[i]->chromosom.size();

            int pos1=qrand()%popSize;
            int pos2=qrand()%popSize;
            std::cout<<"pos1 :"<<pos1<<std::endl;
            std::cout<<"pos2 :"<<pos2<<std::endl;

            Gen* g1=populacja->populacja[i]->chromosom[pos1];
            populacja->populacja[i]->chromosom[pos1]=populacja->populacja[i]->chromosom[pos2];
            populacja->populacja[i]->chromosom[pos2]=g1;
       // }
    }

}

void AlgorytmGenetyczny::krzyzowanie()
{

}

bool osobnikSelect(Osobnik* o1, Osobnik* o2)
{
    return o1->przystosowanie>o2->przystosowanie;
}

void AlgorytmGenetyczny::selekcja()
{
    qSort(populacja->populacja.begin(),populacja->populacja.end(),osobnikSelect);
}

