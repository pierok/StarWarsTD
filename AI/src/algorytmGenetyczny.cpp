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
            int iloscM=qrand()%populacja->rozmiar();

            int popSize = populacja->populacja[i]->rozmiar;
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


void AlgorytmGenetyczny::mutacja2()
{
    /*for(int i=0; i<populacja->rozmiar();++i)
    {
        int m=qrand()%100+1;

        if(m<10)
        {
            int iloscM=qrand()%populacja->rozmiar();

            int popSize = populacja->populacja[i]->rozmiar;
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
    }*/

}

void AlgorytmGenetyczny::krzyzowanie()
{
    std::cout<<"===============Krzy¿owanie=========="<<std::endl;
    int rozmiar=populacja->rozmiar();
    int nextCh=rozmiar/2;
    int nextCh2=rozmiar/2+1;

    while(nextCh2<rozmiar)
    {
        int p1=qrand()%rozmiar/2;
        int p2=qrand()%rozmiar/2;

        std::cout<<"p1: "<<p1<<" p2: "<<p2<<std::endl;

        int m=qrand()%100+1;

        if(m<=60)
        {
            int pos=qrand()%8;

            Osobnik* o1=populacja->populacja[p1];
            Osobnik* o2=populacja->populacja[p2];


            for(int j=0; j<pos; ++j)
            {


                populacja->populacja[nextCh]->chromosom[j]->resetGen();
                populacja->populacja[nextCh]->chromosom[j]->setTowerType(o1->chromosom[j]->getTowerType());
                populacja->populacja[nextCh]->chromosom[j]->setTowerX(o1->chromosom[j]->getTowerX());
                populacja->populacja[nextCh]->chromosom[j]->setTowerY(o1->chromosom[j]->getTowerY());



                populacja->populacja[nextCh2]->chromosom[j]->resetGen();
                populacja->populacja[nextCh2]->chromosom[j]->setTowerType(o2->chromosom[j]->getTowerType());
                populacja->populacja[nextCh2]->chromosom[j]->setTowerX(o2->chromosom[j]->getTowerX());
                populacja->populacja[nextCh2]->chromosom[j]->setTowerY(o2->chromosom[j]->getTowerY());
            }

            for(int j=pos; j<o2->rozmiar; ++j)
            {

                if(j>populacja->populacja[nextCh]->chromosom.size()-1)
                {
                    Gen* gen=new Gen();
                    gen->setTowerType(o2->chromosom[j]->getTowerType());
                    gen->setTowerX(o2->chromosom[j]->getTowerX());
                    gen->setTowerY(o2->chromosom[j]->getTowerY());
                    populacja->populacja[nextCh]->chromosom.push_back(gen);
                }else
                {

                    populacja->populacja[nextCh]->chromosom[j]->resetGen();
                    populacja->populacja[nextCh]->chromosom[j]->setTowerType(o2->chromosom[j]->getTowerType());
                    populacja->populacja[nextCh]->chromosom[j]->setTowerX(o2->chromosom[j]->getTowerX());
                    populacja->populacja[nextCh]->chromosom[j]->setTowerY(o2->chromosom[j]->getTowerY());
                }

            }

            populacja->populacja[nextCh]->rozmiar=o2->rozmiar;

            for(int j=pos; j<o1->rozmiar; ++j)
            {
                if(j>populacja->populacja[nextCh2]->chromosom.size()-1)
                {
                    Gen* gen=new Gen();
                    gen->resetGen();
                    gen->setTowerType(o1->chromosom[j]->getTowerType());
                    gen->setTowerX(o1->chromosom[j]->getTowerX());
                    gen->setTowerY(o1->chromosom[j]->getTowerY());
                    populacja->populacja[nextCh2]->chromosom.push_back(gen);
                }else
                {
                    populacja->populacja[nextCh2]->chromosom[j]->resetGen();
                    populacja->populacja[nextCh2]->chromosom[j]->setTowerType(o1->chromosom[j]->getTowerType());
                    populacja->populacja[nextCh2]->chromosom[j]->setTowerX(o1->chromosom[j]->getTowerX());
                    populacja->populacja[nextCh2]->chromosom[j]->setTowerY(o1->chromosom[j]->getTowerY());
                }

            }

            populacja->populacja[nextCh2]->rozmiar=o1->rozmiar;
            nextCh+=2;
            nextCh2+=2;
        }
    }
    std::cout<<"===============Koniec=========="<<std::endl;
}

bool osobnikSelect(Osobnik* o1, Osobnik* o2)
{
    return o1->przystosowanie>o2->przystosowanie;
}

void AlgorytmGenetyczny::selekcja()
{
    qSort(populacja->populacja.begin(),populacja->populacja.end(),osobnikSelect);
}

