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
    void selekcja(Populacja * populacja);
};


class SelekcjaLosowa : public Selekcja
{
public:
    void selekcja(Populacja * populacja);
};

class SelekcjaProporcjonalna : public Selekcja
{
public:
    void selekcja(Populacja * populacja);
};

#endif // SELEKCJA_H
