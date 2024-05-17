#ifndef PRZEMYSLOWE_H
#define PRZEMYSLOWE_H

#include "main.h"
#include "produkt.h"

class Przemyslowe : public Produkt
{
    private:
        string nazwa;
        string marka;
        string kolor;

    public:
        Przemyslowe();
        Przemyslowe(double, string, int, string, string, string);
        string getNazwa();
        string getMarka();
        string getKolor();
        void set(double, string, int, string, string, string);
        virtual string wypisz() override;
};

#endif