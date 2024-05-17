#include "spozywcze.h"

Spozywcze::Spozywcze() : Produkt()
{
    nazwa = "Nazwa";
    data_waznosci = "01.01.2021";
    rozmiar = "1szt.";
}

Spozywcze::Spozywcze(double _cena, string _kod, int _ilosc, string _nazwa, string _data_waznosci, string _rozmiar) : Produkt(_cena, _kod, _ilosc)
{
    nazwa = _nazwa;
    data_waznosci = _data_waznosci;
    rozmiar = _rozmiar;
}

string Spozywcze::getNazwa()
{
    return nazwa;
}

string Spozywcze::getData_waznosci()
{
    return data_waznosci;
}

string Spozywcze::getRozmiar()
{
    return rozmiar;
}

void Spozywcze::set(double _cena, string _kod, int _ilosc, string _nazwa, string _data_waznosci, string _rozmiar)
{
    Produkt::set(_cena, _kod, _ilosc);
    nazwa = _nazwa;
    data_waznosci = _data_waznosci;
    rozmiar = _rozmiar;
}

string Spozywcze::wypisz()
{
    ostringstream out;

    out << " Informacje o produkcie:" << endl
        << "    Typ: Artykul spozywczy." << endl
        << "    Nazwa: " << getNazwa() << endl
        << "    Rozmiar/ilosc: " << getRozmiar() << endl
        << "    Data waznosci: " << getData_waznosci() << endl
        << Produkt::wypisz();

    return out.str();
}