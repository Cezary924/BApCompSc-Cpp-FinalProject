#ifndef PRACOWNIK_H
#define PRACOWNIK_H

#include "main.h"

class Pracownik
{
    private:
        string imie;
        string nazwisko;
        string stanowisko;
        double pensja;
    
    public:
        Pracownik();
        Pracownik(string, string, string, double);
        void set(string, string, string, double);
        string getImie();
        string getNazwisko();
        string getStanowisko();
        double getPensja();
};

#endif