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
}
