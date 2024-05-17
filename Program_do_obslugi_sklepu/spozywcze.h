#ifndef SPOZYWCZE_H
#define SPOZYWCZE_H

#include "main.h"
#include "produkt.h"

class Spozywcze : public Produkt
{
    private:
        string nazwa;
        string data_waznosci;
        string rozmiar;

    public:
        Spozywcze();
        Spozywcze(double, string, int, string, string, string);
        string getNazwa();
        string getData_waznosci();
        string getRozmiar();
        void set(double, string, int, string, string, string);
        virtual string wypisz() override;
};

#endif