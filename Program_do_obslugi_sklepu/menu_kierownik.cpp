#include "main.h"

void menu_kierownik()
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
        
        cout << "|                                         Tryb kierownika                                         |" << endl;
        linia();
        
        cout << " 1. Lista pracownikow." << endl;
        cout << " 2. Dodaj pracownika." << endl;
        cout << " 3. Edytuj pracownika." << endl;
        cout << " 4. Usun pracownika." << endl;
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
                lista_pracownik();
                break;

            case '2':
                dodaj_pracownik();
                break;

            case '3':
                edytuj_pracownik();
                break;

            case '4':
                usun_pracownik();
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