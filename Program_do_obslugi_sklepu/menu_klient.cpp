#include "main.h"

void menu_klient()
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
        
        cout << "|                                          Tryb  klienta                                          |" << endl;
        linia();
        
        cout << " 1. Lista produktow." << endl;
        cout << " 2. Cena produktu." << endl;
        cout << " 3. Dostepnosc produktu." << endl;
        cout << " 4. Informacje o produkcie." << endl;
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
                lista_produkt();
                break;

            case '2':
                cena_produkt();
                break;

            case '3':
                dostepnosc_produkt();
                break;

            case '4':
                informacje_produkt();
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