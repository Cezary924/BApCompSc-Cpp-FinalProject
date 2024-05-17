#include "produkt.h"

Produkt::Produkt()
{
    cena = 1.00;
    kod = "00000000000";
    ilosc = 1;
}

Produkt::Produkt(double _cena, string _kod, int _ilosc)
{
    kod = _kod;
    if(_cena < 0)
    {
        cena = 0.00;
    }
    else
    {
        cena = _cena;
    }
    if(_ilosc < 0)
    {
        ilosc = 0;
    }
    else
    {
        ilosc = _ilosc;
    }
}

double Produkt::getCena()
{
    return cena;
}

string Produkt::getKod()
{
    return kod;
}

int Produkt::getIlosc()
{
    return ilosc;
}

void Produkt::set(double _cena, string _kod, int _ilosc)
{
    kod = _kod;
    if(_cena < 0)
    {
        cena = 0.00;
    }
    else
    {
        cena = _cena;
    }
    if(_ilosc < 0)
    {
        ilosc = 0;
    }
    else
    {
        ilosc = _ilosc;
    }
}

string Produkt::wypisz()
{
    
    ostringstream out;

    out << "    Dostepna ilosc: " << getIlosc() << endl
        << setprecision(2) << fixed
        << "    Cena: " << getCena() << endl
        << "    Kod produktu: " << getKod() << endl;

    return out.str();
}