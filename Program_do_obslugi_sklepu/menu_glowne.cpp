#include "main.h"

void menu_glowne()
{
    char wybor = '6';
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
        cout << "|                                           Menu glowne                                           |" << endl;
        linia();
        cout << " 1. Tryb klienta." << endl;
        cout << " 2. Tryb pracownika." << endl;
        cout << " 3. Tryb kierownika." << endl;
        cout << " 4. Informacje o programie." << endl;
        cout << " 0. Wyjscie z programu." << endl;
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
                menu_klient();
                break;

            case '2':
                menu_sprzedawca();
                break;

            case '3':
                menu_kierownik();
                break;

            case '4':
                informacja_powitalna();
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