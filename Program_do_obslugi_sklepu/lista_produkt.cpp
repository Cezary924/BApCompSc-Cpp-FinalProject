#include "main.h"

void lista_produkt()
{
    char wybor = '2';
    bool zmienna1 = false;
    bool zmienna2 = false;

    while(wybor)
    {
        if(zmienna2 == true)
        {
            break;
        }
        
        system("clear");
        linia();
        
        cout << "|                                         Lista produktow                                         |" << endl;
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
                lista_produkt_spozywcze();
                break;

            case '2':
                lista_produkt_przemyslowe();
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