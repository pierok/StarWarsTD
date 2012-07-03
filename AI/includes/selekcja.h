#ifndef SELEKCJA_H
#define SELEKCJA_H


#include "AI/includes/populacja.h"

class Selekcja
{
public:
    virtual void selekcja(Populacja * populacja);
};


class SelekcjaElitarna : public Selekcja
{
public:
    void selekcja(Populacja * populacja);
};


class SelekcjaTurniejowa : public Selekcja
{
public:
    SelekcjaTurniejowa()
    {
        qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    }

    void selekcja(Populacja * populacja);
};


class SelekcjaLosowa : public Selekcja
{
public:
    SelekcjaLosowa()
    {
        qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    }

    void selekcja(Populacja * populacja);
};

class SelekcjaProporcjonalna : public Selekcja
{
public:
    void selekcja(Populacja * populacja);
};

#endif // SELEKCJA_H
