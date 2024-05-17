#include "przemyslowe.h"

Przemyslowe::Przemyslowe() : Produkt()
{
    nazwa = "Nazwa";
    marka = "Marka";
    kolor = "Kolor";
}

Przemyslowe::Przemyslowe(double _cena, string _kod, int _ilosc, string _nazwa, string _marka, string _kolor) : Produkt(_cena, _kod, _ilosc)
{
    nazwa = _nazwa;
    marka = _marka;
    kolor = _kolor;
}

string Przemyslowe::getNazwa()
{
    return nazwa;
}

string Przemyslowe::getMarka()
{
    return marka;
}

string Przemyslowe::getKolor()
{
    return kolor;
}

void Przemyslowe::set(double _cena, string _kod, int _ilosc, string _nazwa, string _marka, string _kolor)
{
    Produkt::set(_cena, _kod, _ilosc);
    nazwa = _nazwa;
    marka = _marka;
    kolor = _kolor;
}

string Przemyslowe::wypisz()
{
    ostringstream out;

    out << " Informacje o produkcie:" << endl
        << "    Typ: Artykul przemyslowy." << endl
        << "    Nazwa: " << getNazwa() << endl
        << "    Marka: " << getMarka() << endl
        << "    Kolor: " << getKolor() << endl
        << Produkt::wypisz();

    return out.str();
}