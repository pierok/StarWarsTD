#include "AI/includes/algorytmGenetyczny.h"
#include <iostream>
/*
AlgorytmGenetyczny::AlgorytmGenetyczny(Populacja *pop)
{
    populacja=pop;
    pokolenie=0;
}

void AlgorytmGenetyczny::mutacja()
{
    std::cout<<"========MUtacaj start============"<<std::endl;
    for(int i=0; i<populacja->rozmiar();++i)
    {
        int m=qrand()%100+1;

        if(m<30)
        {
            int iloscM=qrand()%populacja->populacja[i]->rozmiar;

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

    std::cout<<"========MUtacaj2 start============"<<std::endl;
    for(int i=0; i<populacja->rozmiar();++i)
    {
        int m=qrand()%100+1;

        if(m<20)
        {

            std::cout<<"++++++++++++MUtacaj2 OK+++++++++++"<<std::endl;
            int iloscM=qrand()%populacja->populacja[i]->rozmiar;

            for(int j=0; j<iloscM; ++j)
            {
                int pos1=qrand()%populacja->populacja[i]->rozmiar;

                int type=qrand()%3+1;

                int x=qrand()%2680;
                int y=qrand()%2680;

                populacja->populacja[i]->chromosom[pos1]->setTowerType(type);
                populacja->populacja[i]->chromosom[pos1]->setTowerX(x);
                populacja->populacja[i]->chromosom[pos1]->setTowerY(y);

            }
        }
    }
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



        int m=qrand()%100+1;

        if(m<=60)
        {
            std::cout<<"p1: "<<p1<<" p2: "<<p2<<std::endl;
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
                populacja->populacja[nextCh]->chromosom[j]->resetGen();
                populacja->populacja[nextCh]->chromosom[j]->setTowerType(o2->chromosom[j]->getTowerType());
                populacja->populacja[nextCh]->chromosom[j]->setTowerX(o2->chromosom[j]->getTowerX());
                populacja->populacja[nextCh]->chromosom[j]->setTowerY(o2->chromosom[j]->getTowerY());

            }

            populacja->populacja[nextCh]->rozmiar=o2->rozmiar;

            for(int j=pos; j<o1->rozmiar; ++j)
            {

                populacja->populacja[nextCh2]->chromosom[j]->resetGen();
                populacja->populacja[nextCh2]->chromosom[j]->setTowerType(o1->chromosom[j]->getTowerType());
                populacja->populacja[nextCh2]->chromosom[j]->setTowerX(o1->chromosom[j]->getTowerX());
                populacja->populacja[nextCh2]->chromosom[j]->setTowerY(o1->chromosom[j]->getTowerY());

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

    std::cout<<"===============Selekcja=========="<<std::endl;
    qSort(populacja->populacja.begin(),populacja->populacja.end(),osobnikSelect);
}
*/

AGDef::AGDef(Populacja *pop, Selekcja* s)
{
    populacja=pop;
    pokolenie=0;
    selekcja=s;
}

void AGDef::mutacja()
{
    //std::cout<<"========MUtacaj start============"<<std::endl;
    for(int i=0; i<populacja->rozmiar();++i)
    {
        int m=qrand()%100+1;

        if(m<30)
        {
            int iloscM=qrand()%populacja->populacja[i]->rozmiar;

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


void AGDef::mutacja2()
{

    //std::cout<<"========MUtacaj2 start============"<<std::endl;
    for(int i=0; i<populacja->rozmiar();++i)
    {
        int m=qrand()%100+1;

        if(m<20)
        {

            //std::cout<<"++++++++++++MUtacaj2 OK+++++++++++"<<std::endl;
            int iloscM=qrand()%populacja->populacja[i]->rozmiar;

            for(int j=0; j<iloscM; ++j)
            {
                int pos1=qrand()%populacja->populacja[i]->rozmiar;

                int type=qrand()%3+1;

                int x=qrand()%2680;
                int y=qrand()%2680;

                populacja->populacja[i]->chromosom[pos1]->setTowerType(type);
                populacja->populacja[i]->chromosom[pos1]->setTowerX(x);
                populacja->populacja[i]->chromosom[pos1]->setTowerY(y);

            }
        }
    }
}

void AGDef::krzyzowanie()
{
    std::cout<<"===============Krzy¿owanie=========="<<std::endl;
    int rozmiar=populacja->rozmiar();
    int nextCh=populacja->proporcja;
    int nextCh2=populacja->proporcja+1;


    for(int i=0; i<populacja->proporcja; ++i)
    {
        populacja->populacja[i]->kopiujOsobnika(populacja->wynikSelekcji[i]);
    }

    while(nextCh2<rozmiar)
    {
        int p1=qrand()%populacja->proporcja;
        int p2=qrand()%populacja->proporcja;



        int m=qrand()%100+1;

        if(m<=60)
        {
            //std::cout<<"p1: "<<p1<<" p2: "<<p2<<std::endl;
            int pos=qrand()%populacja->wynikSelekcji[p1]->rozmiar;

            Osobnik* o1=populacja->wynikSelekcji[p1];
            Osobnik* o2=populacja->wynikSelekcji[p2];

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
                populacja->populacja[nextCh]->chromosom[j]->resetGen();
                populacja->populacja[nextCh]->chromosom[j]->setTowerType(o2->chromosom[j]->getTowerType());
                populacja->populacja[nextCh]->chromosom[j]->setTowerX(o2->chromosom[j]->getTowerX());
                populacja->populacja[nextCh]->chromosom[j]->setTowerY(o2->chromosom[j]->getTowerY());

            }

            populacja->populacja[nextCh]->rozmiar=o2->rozmiar;

            for(int j=pos; j<o1->rozmiar; ++j)
            {

                populacja->populacja[nextCh2]->chromosom[j]->resetGen();
                populacja->populacja[nextCh2]->chromosom[j]->setTowerType(o1->chromosom[j]->getTowerType());
                populacja->populacja[nextCh2]->chromosom[j]->setTowerX(o1->chromosom[j]->getTowerX());
                populacja->populacja[nextCh2]->chromosom[j]->setTowerY(o1->chromosom[j]->getTowerY());

            }

            populacja->populacja[nextCh2]->rozmiar=o1->rozmiar;
            nextCh+=2;
            nextCh2+=2;
        }else
        {
            populacja->populacja[nextCh]->kopiujOsobnika(populacja->wynikSelekcji[p1]);
            populacja->populacja[nextCh2]->kopiujOsobnika(populacja->wynikSelekcji[p2]);

            nextCh+=2;
            nextCh2+=2;
        }
    }
    std::cout<<"===============Koniec Kzyrzowanie=========="<<std::endl;
}
/*
bool osobnikSelect(Osobnik* o1, Osobnik* o2)
{
    return o1->przystosowanie>o2->przystosowanie;
}*/

/*void AGDef::selekcja()
{

    //std::cout<<"===============Selekcja=========="<<std::endl;
    qSort(populacja->populacja.begin(),populacja->populacja.end(),osobnikSelect);
}*/





AGOf::AGOf(PopulacjaOf *pop)
{
    populacjaOf=pop;
    pokolenie=0;
}

void AGOf::mutacja()
{
    //std::cout<<"========MUtacaj start============"<<std::endl;
    for(int i=0; i<populacjaOf->rozmiar();++i)
    {
        int m=qrand()%100+1;

        if(m<30)
        {
            int iloscM=qrand()%populacjaOf->populacja[i]->rozmiar;

            int popSize = populacjaOf->populacja[i]->rozmiar;
            int pos1=0;
            int pos2=0;

            for(int j=0; j<iloscM; ++j)
            {
                pos1=qrand()%popSize;
                pos2=qrand()%popSize;

                GenOf* g1=populacjaOf->populacja[i]->chromosom[pos1];
                populacjaOf->populacja[i]->chromosom[pos1]=populacjaOf->populacja[i]->chromosom[pos2];
                populacjaOf->populacja[i]->chromosom[pos2]=g1;
            }
        }
    }
}


void AGOf::mutacja2()
{

    //std::cout<<"========MUtacaj2 start============"<<std::endl;
    for(int i=0; i<populacjaOf->rozmiar();++i)
    {
        int m=qrand()%100+1;

        if(m<20)
        {

            //std::cout<<"++++++++++++MUtacaj2 OK+++++++++++"<<std::endl;
            int iloscM=qrand()%populacjaOf->populacja[i]->rozmiar;

            for(int j=0; j<iloscM; ++j)
            {
                int pos1=qrand()%populacjaOf->populacja[i]->rozmiar;

                int type=qrand()%2;
                int target=qrand()%2;

                int x=qrand()%2680;
                int y=qrand()%2680;

                populacjaOf->populacja[i]->chromosom[pos1]->setEnemyType(type);
                populacjaOf->populacja[i]->chromosom[pos1]->setDeployX(x);
                populacjaOf->populacja[i]->chromosom[pos1]->setDeployY(y);
                populacjaOf->populacja[i]->chromosom[pos1]->setTarget(target);

            }
        }
    }
}

void AGOf::krzyzowanie()
{
   // std::cout<<"===============Krzy¿owanie=========="<<std::endl;
    int rozmiar=populacjaOf->rozmiar();
    int nextCh=rozmiar/2;
    int nextCh2=rozmiar/2+1;

    while(nextCh2<rozmiar)
    {
        int p1=qrand()%rozmiar/2;
        int p2=qrand()%rozmiar/2;

        int m=qrand()%100+1;

        if(m<=60)
        {
            //std::cout<<"p1: "<<p1<<" p2: "<<p2<<std::endl;
            int pos=qrand()%2;

            OsobnikOf* o1=populacjaOf->populacja[p1];
            OsobnikOf* o2=populacjaOf->populacja[p2];

            for(int j=0; j<pos; ++j)
            {
                populacjaOf->populacja[nextCh]->chromosom[j]->resetGen();
                populacjaOf->populacja[nextCh]->chromosom[j]->setEnemyType(o1->chromosom[j]->getEnemyType());
                populacjaOf->populacja[nextCh]->chromosom[j]->setDeployX(o1->chromosom[j]->getDeployX());
                populacjaOf->populacja[nextCh]->chromosom[j]->setDeployY(o1->chromosom[j]->getDeployY());
                populacjaOf->populacja[nextCh]->chromosom[j]->setTarget(o1->chromosom[j]->getTarget());

                populacjaOf->populacja[nextCh2]->chromosom[j]->resetGen();
                populacjaOf->populacja[nextCh2]->chromosom[j]->setEnemyType(o2->chromosom[j]->getEnemyType());
                populacjaOf->populacja[nextCh2]->chromosom[j]->setDeployX(o2->chromosom[j]->getDeployX());
                populacjaOf->populacja[nextCh2]->chromosom[j]->setDeployY(o2->chromosom[j]->getDeployY());
                populacjaOf->populacja[nextCh2]->chromosom[j]->setTarget(o2->chromosom[j]->getTarget());
            }

            for(int j=pos; j<o2->rozmiar; ++j)
            {
                populacjaOf->populacja[nextCh]->chromosom[j]->resetGen();
                populacjaOf->populacja[nextCh]->chromosom[j]->setEnemyType(o2->chromosom[j]->getEnemyType());
                populacjaOf->populacja[nextCh]->chromosom[j]->setDeployX(o2->chromosom[j]->getDeployX());
                populacjaOf->populacja[nextCh]->chromosom[j]->setDeployY(o2->chromosom[j]->getDeployY());
                populacjaOf->populacja[nextCh]->chromosom[j]->setTarget(o2->chromosom[j]->getTarget());

            }

            populacjaOf->populacja[nextCh]->rozmiar=o2->rozmiar;

            for(int j=pos; j<o1->rozmiar; ++j)
            {

                populacjaOf->populacja[nextCh2]->chromosom[j]->resetGen();
                populacjaOf->populacja[nextCh2]->chromosom[j]->setEnemyType(o1->chromosom[j]->getEnemyType());
                populacjaOf->populacja[nextCh2]->chromosom[j]->setDeployX(o1->chromosom[j]->getDeployX());
                populacjaOf->populacja[nextCh2]->chromosom[j]->setDeployY(o1->chromosom[j]->getDeployY());
                populacjaOf->populacja[nextCh2]->chromosom[j]->setTarget(o1->chromosom[j]->getTarget());

            }

            populacjaOf->populacja[nextCh2]->rozmiar=o1->rozmiar;
            nextCh+=2;
            nextCh2+=2;
        }
    }
    //std::cout<<"===============Koniec=========="<<std::endl;
}

bool osobnikSelect2(OsobnikOf* o1, OsobnikOf* o2)
{
    return o1->przystosowanie>o2->przystosowanie;
}

void AGOf::selekcja()
{

    //std::cout<<"===============Selekcja=========="<<std::endl;
    qSort(populacjaOf->populacja.begin(),populacjaOf->populacja.end(),osobnikSelect2);
}

