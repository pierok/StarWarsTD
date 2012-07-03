#include "AI/includes/selekcja.h"
#include <iostream>

bool osobnikSelect(Osobnik* o1, Osobnik* o2)
{
    return o1->przystosowanie>o2->przystosowanie;
}

void SelekcjaElitarna::selekcja(Populacja* populacja)
{
    std::cout<<"============SELEKCJA ELITARNA=============="<<std::endl;
    qSort(populacja->populacja.begin(),populacja->populacja.end(),osobnikSelect);

    for(int i=0; i<populacja->proporcja;++i)
    {
        populacja->wynikSelekcji[i]->kopiujOsobnika(populacja->populacja[i]);
    }
    std::cout<<"============STOP SELEKCJA ELITARNA=============="<<std::endl;
}

void SelekcjaLosowa::selekcja(Populacja *populacja)
{
    std::cout<<"============SELEKCJA LOSOWA=============="<<std::endl;
    for(int i=0; i<populacja->proporcja;++i)
    {
        int x=qrand()%populacja->populacja.size();
        populacja->wynikSelekcji[i]->kopiujOsobnika(populacja->populacja[x]);
    }
    std::cout<<"============STOP SELEKCJA LOSOWA=============="<<std::endl;
}

void SelekcjaTurniejowa::selekcja(Populacja *populacja)
{
    std::cout<<"============SELEKCJA TURNIEJOWA=============="<<std::endl;


    QVector<Osobnik*> tmp;

    for(int i=0; i<populacja->proporcja;++i)
    {
        for(int j=0; j<5; ++j)
        {
            int x=qrand()%populacja->populacja.size();
            tmp.push_back(populacja->populacja[x]);
        }

        qSort(tmp.begin(),tmp.end(),osobnikSelect);
        tmp.erase(tmp.begin(),tmp.end());

        populacja->wynikSelekcji[i]->kopiujOsobnika(tmp[0]);
    }



    std::cout<<"============STOP SELEKCJA TURNIEJOWA=============="<<std::endl;
}
