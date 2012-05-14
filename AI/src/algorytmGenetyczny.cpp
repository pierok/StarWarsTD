#include "AI/includes/algorytmGenetyczny.h"

AlgorytmGenetyczny::AlgorytmGenetyczny(Populacja *pop)
{
    populacja=pop;
    pokolenie=0;
}

void AlgorytmGenetyczny::mutacja()
{

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

