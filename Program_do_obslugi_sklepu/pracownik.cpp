#include "pracownik.h"

Pracownik::Pracownik()
{
    imie = "Imie";
    nazwisko = "Nazwisko";
    stanowisko = "Stanowisko";
    pensja = 0.00;
}

Pracownik::Pracownik(string _imie, string _nazwisko, string _stanowisko, double _pensja)
{
    imie = _imie;
    nazwisko = _nazwisko;
    stanowisko = _stanowisko;
    if(_pensja >= 0)
    {
        pensja = _pensja;
    }
    else
    {
        pensja = 0.00;
    }
}

void Pracownik::set(string _imie, string _nazwisko, string _stanowisko, double _pensja)
{
    imie = _imie;
    nazwisko = _nazwisko;
    stanowisko = _stanowisko;
    if(_pensja >= 0)
    {
        pensja = _pensja;
    }
    else
    {
        pensja = 0.00;
    }
}

string Pracownik::getImie()
{
    return imie;
}

string Pracownik::getNazwisko()
{
    return nazwisko;
}

string Pracownik::getStanowisko()
{
    return stanowisko;
}

double Pracownik::getPensja()
{
    return pensja;
}