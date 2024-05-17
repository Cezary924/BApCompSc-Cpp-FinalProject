#include "main.h"
#include "pracownik.h"

int liczba_pracownikow_ep = 0;
Pracownik tablica_pracownikow_ep[MAX];

void wczytaj_pracownik_ep();

void edytuj_pracownik()
{
    char wybor = '2';
    bool zmienna1 = false;
    bool zmienna2 = false;

    wczytaj_pracownik_ep();

    string stanowisko, imie, nazwisko;
    double pensja;
    
    system("clear");
    
    linia();
    cout << "|                                        Edytuj pracownika                                        |" << endl;
    linia();

    cout << " Wprowadz stare dane: " << endl;
    cout << "    Wprowadz stanowisko: ";
    cin >> stanowisko;
    cout << "    Wprowadz imie: ";
    cin >> imie;
    cout << "    Wprowadz nazwisko: ";
    cin >> nazwisko;
    try
    {
        cout << "    Wprowadz pensje: ";
        if((cin >> pensja).fail())
        {
            throw bad_cast();
        }    
    }
    catch(...)
    {
        linia();
        cout << " Wyjatek. Probowano przypisac zmiennym liczbowym nieodpowiednia wartosc." << endl;
        linia();
        exit(EXIT_FAILURE);
    }

    bool zmienna3 = false;
    int zmienna4;
    for(int a = 0; a < liczba_pracownikow_ep; a++)
    {
        if(tablica_pracownikow_ep[a].getStanowisko() == stanowisko)
        {
            if(tablica_pracownikow_ep[a].getImie() == imie)
            {
                if(tablica_pracownikow_ep[a].getNazwisko() == nazwisko)
                {
                    if(tablica_pracownikow_ep[a].getPensja() == pensja)
                    {
                        zmienna3 = true;
                        zmienna4 = a;
                    }
                }
            }
        }

        if(zmienna3 == true)
        {
            break;
        }
    }
    if (zmienna3 == false)
    {
        while(wybor)
        {
            if(zmienna2 == true)
            {
                liczba_pracownikow_ep = 0;
                break;
            }

            system("clear");

            linia();
            cout << "|                                        Edytuj pracownika                                        |" << endl;
            linia();
            
            cout << " Nie znaleziono pracownika o podanych danych." << endl;
            linia();

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
                case '0':
                    zmienna2 = true;
                    break;

                default:
                    zmienna1 = true;
                    break;
            };
        }
    }
    else
    {
        linia();
        cout << " Wprowadz nowe dane: " << endl;
        cout << "    Wprowadz stanowisko: ";
        cin >> stanowisko;
        cout << "    Wprowadz imie: ";
        cin >> imie;
        cout << "    Wprowadz nazwisko: ";
        cin >> nazwisko;
        try
        {
            cout << "    Wprowadz pensje: ";
            if((cin >> pensja).fail())
            {
                throw bad_cast();
            }    
        }
        catch(...)
        {
            linia();
            cout << " Wyjatek. Probowano przypisac zmiennym liczbowym nieodpowiednia wartosc." << endl;
            linia();
            exit(EXIT_FAILURE);
        }

        tablica_pracownikow_ep[zmienna4].set(imie, nazwisko, stanowisko, pensja);
    
        ofstream plik("dane/pracownicy.txt", ios::out);
        if (!plik)
        {
            cerr << " Blad otwarcia pliku!" << endl;
            exit(EXIT_FAILURE);
        }

        for(int a = 0; a < liczba_pracownikow_ep; a++)
        {
            plik << tablica_pracownikow_ep[a].getImie() << " " << tablica_pracownikow_ep[a].getNazwisko() << " "
                << tablica_pracownikow_ep[a].getStanowisko() << " " << tablica_pracownikow_ep[a].getPensja() << endl;
        }

        char wybor = '2';
        bool zmienna1 = false;
        bool zmienna2 = false;

        while(wybor)
        {
            if(zmienna2 == true)
            {
                liczba_pracownikow_ep = 0;
                break;
            }
            
            system("clear");
            linia();
            
            cout << "|                                        Edytuj pracownika                                        |" << endl;
            linia();
            
            cout << " Pomyslnie edytowano dane pracownika." << endl;
            linia();

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
                case '0':
                    zmienna2 = true;
                    break;

                default:
                    zmienna1 = true;
                    break;
            };
        }
    }
}

void wczytaj_pracownik_ep()
{
    ifstream plik("dane/pracownicy.txt", ios::in);
    if (!plik)
    {
        cerr << " Blad otwarcia pliku!" << endl;
        exit(EXIT_FAILURE);
    }

    string imie;
    string nazwisko;
    string stanowisko;
    double pensja;
    if (plik >> imie >> nazwisko >> stanowisko >> pensja)
    {
        tablica_pracownikow_ep[liczba_pracownikow_ep].set(imie, nazwisko, stanowisko, pensja);
        liczba_pracownikow_ep++;

        while(plik >> imie >> nazwisko >> stanowisko >> pensja)
        {
            tablica_pracownikow_ep[liczba_pracownikow_ep].set(imie, nazwisko, stanowisko, pensja);
            liczba_pracownikow_ep++;

            if(liczba_pracownikow_ep + 1 == MAX)
            {
                break;
            }
        }
    }
    else
    {
        cout << " Brak danych w pliku!" << endl;
    }
}