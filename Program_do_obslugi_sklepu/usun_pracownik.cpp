#include "main.h"
#include "pracownik.h"

int liczba_pracownikow_up = 0;
Pracownik tablica_pracownikow_up[MAX];
int zmienna4;

void wczytaj_pracownik_up();
void usuwanie_pracownika();

void usun_pracownik()
{
    char wybor = '2';
    bool zmienna1 = false;
    bool zmienna2 = false;

    wczytaj_pracownik_up();

    string stanowisko, imie, nazwisko;
    double pensja;
    
    system("clear");
    
    linia();
    cout << "|                                         Usun pracownika                                         |" << endl;
    linia();

    cout << " Wprowadz dane pracownika do usuniecia: " << endl;
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
    zmienna4;
    for(int a = 0; a < liczba_pracownikow_up; a++)
    {
        if(tablica_pracownikow_up[a].getStanowisko() == stanowisko)
        {
            if(tablica_pracownikow_up[a].getImie() == imie)
            {
                if(tablica_pracownikow_up[a].getNazwisko() == nazwisko)
                {
                    if(tablica_pracownikow_up[a].getPensja() == pensja)
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
                liczba_pracownikow_up = 0;
                break;
            }

            system("clear");

            linia();
            cout << "|                                         Usun pracownika                                         |" << endl;
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

        char wybor = '2';
        bool zmienna1 = false;
        bool zmienna2 = false;
        bool zmienna5 = false;

        while(wybor)
        {
            if(zmienna2 == true)
            {
                liczba_pracownikow_up = 0;

                char wybor_nowy = '2';
                bool zmienna11 = false;
                bool zmienna22 = false;

                while(wybor_nowy)
                {
                    if(zmienna22 == true)
                    {
                        break;
                    }
                    
                    system("clear");
                    linia();
                    
                    cout << "|                                         Usun pracownika                                         |" << endl;
                    linia();
                    
                    if(zmienna5 == true) cout << " Pomyslnie usunieto pracownika." << endl;
                    else cout << " Nie usunieto pracownika." << endl;
                    linia();

                    cout << " 0. Cofnij." << endl;
                    linia();
                    
                    if(zmienna11 == true)
                    {
                        cout << " Nie ma takiej opcji!" << endl;
                        linia();
                    }
                    zmienna11 = false;
                    
                    cout << " Twoj wybor: ";
                    cin >> wybor_nowy;
                    linia();

                    switch(wybor_nowy)
                    {
                        case '0':
                            zmienna22 = true;
                            break;

                        default:
                            zmienna11 = true;
                            break;
                    };
                }

                break;
            }
            
            system("clear");
            linia();
            
            cout << "|                                         Usun pracownika                                         |" << endl;
            linia();
            
            cout << " Czy na pewno chcesz usunac dane tego pracownika?" << endl;
            linia();

            cout << " 1. Tak." << endl;
            cout << " 2. Nie." << endl;
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
                    usuwanie_pracownika();
                    zmienna2 = true;
                    zmienna5 = true;
                    break;

                case '2':
                    zmienna2 = true;
                    zmienna5 = false;
                    break;

                default:
                    zmienna1 = true;
                    break;
            };
        }
    }
}

void wczytaj_pracownik_up()
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
        tablica_pracownikow_up[liczba_pracownikow_up].set(imie, nazwisko, stanowisko, pensja);
        liczba_pracownikow_up++;

        while(plik >> imie >> nazwisko >> stanowisko >> pensja)
        {
            tablica_pracownikow_up[liczba_pracownikow_up].set(imie, nazwisko, stanowisko, pensja);
            liczba_pracownikow_up++;

            if(liczba_pracownikow_up + 1 == MAX)
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

void usuwanie_pracownika()
{
    string temp_s[3];
    double temp_d;

    for (int a = zmienna4; a < liczba_pracownikow_up - 1; a++)
    {
        temp_s[0] = tablica_pracownikow_up[a + 1].getImie();
        temp_s[1] = tablica_pracownikow_up[a + 1].getNazwisko();
        temp_s[2] = tablica_pracownikow_up[a + 1].getStanowisko();
        temp_d = tablica_pracownikow_up[a + 1].getPensja();

        tablica_pracownikow_up[a].set(temp_s[0], temp_s[1], temp_s[2], temp_d);
    }
    liczba_pracownikow_up--;

    ofstream plik("dane/pracownicy.txt", ios::out);
    if (!plik)
    {
        cerr << " Blad otwarcia pliku!" << endl;
        exit(EXIT_FAILURE);
    }

    for (int a = 0; a < liczba_pracownikow_up; a++)
    {
        plik << tablica_pracownikow_up[a].getImie() << " " << tablica_pracownikow_up[a].getNazwisko() << " "
             << tablica_pracownikow_up[a].getStanowisko() << " " << tablica_pracownikow_up[a].getPensja() << endl;
    }
}