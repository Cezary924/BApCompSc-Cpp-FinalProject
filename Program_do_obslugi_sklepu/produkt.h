#ifndef PRODUKT_H
#define PRODUKT_H

#include "main.h"

class Produkt
{
    private:
        double cena;
        string kod;
        int ilosc;

    public:
        Produkt();
        Produkt(double, string, int);
        double getCena();
        string getKod();
        int getIlosc();
        void set(double, string, int);
        virtual string wypisz();
};

#endif