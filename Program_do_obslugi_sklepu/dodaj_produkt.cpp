#include "main.h"

void dodaj_produkt()
{
    char wybor = '2';
    bool zmienna1 = false;
    bool zmienna2 = false;
    bool zmienna3 = false;

    while(wybor)
    {
        if(zmienna2 == true || zmienna3 == true)
        {
            break;
        }
        
        system("clear");
        linia();
        
        cout << "|                                          Dodaj produkt                                          |" << endl;
        linia();
        
        cout << " 1. Artykuly spozywcze." << endl;
        cout << " 2. Artykuly przemyslowe." << endl;
        cout << " 0. Cofnij." << endl;
        linia();
        
        if(zmienna1 == true)
        {
            cout << " Nie ma takiej opcji!" << endl;
            linia();
        }
        zmienna1 = false;
        
        cout << " Twoj wybor: ";
        cin >> wybor;
        linia();

        switch(wybor)
        {
            case '1':
                dodaj_produkt_spozywcze();
                zmienna3 = true;
                break;

            case '2':
                dodaj_produkt_przemyslowe();
                zmienna3 = true;
                break;

            case '0':
                zmienna2 = true;
                break;

            default:
                zmienna1 = true;
                break;
        };
    }
}