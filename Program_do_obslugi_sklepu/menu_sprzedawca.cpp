#include "main.h"

void menu_sprzedawca()
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
        
        cout << "|                                         Tryb pracownika                                         |" << endl;
        linia();
        
        cout << " 1. Lista produktow." << endl;
        cout << " 2. Dodaj produkt." << endl;
        cout << " 3. Edytuj produkt." << endl;
        cout << " 4. Usun produkt." << endl;
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
                dodaj_produkt();
                break;

            case '3':
                edytuj_produkt();
                break;

            case '4':
                usun_produkt();
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