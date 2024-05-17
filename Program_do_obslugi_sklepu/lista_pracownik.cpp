#include "main.h"
#include "pracownik.h"

int liczba_pracownikow_lp = 0;
Pracownik tablica_pracownikow_lp[MAX];

void wczytaj_pracownik_lp();
void wydrukuj_pracownik();
int liczba_cyfr_lp(int);

void lista_pracownik()
{
    char wybor = '2';
    bool zmienna1 = false;
    bool zmienna2 = false;

    wczytaj_pracownik_lp();

    while(wybor)
    {
        if(zmienna2 == true)
        {
            liczba_pracownikow_lp = 0;
            break;
        }
        system("clear");
        linia();
        cout << "|                                        Lista pracownikow                                        |" << endl;
        linia();
        wydrukuj_pracownik();
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

void wczytaj_pracownik_lp()
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
        tablica_pracownikow_lp[liczba_pracownikow_lp].set(imie, nazwisko, stanowisko, pensja);
        liczba_pracownikow_lp++;

        while(plik >> imie >> nazwisko >> stanowisko >> pensja)
        {
            tablica_pracownikow_lp[liczba_pracownikow_lp].set(imie, nazwisko, stanowisko, pensja);
            liczba_pracownikow_lp++;

            if(liczba_pracownikow_lp + 1 == MAX)
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

void wydrukuj_pracownik()
{
    int maksymalne_wartosci[4] = {0, 0, 0, 0};

    for(int i = 0; i < liczba_pracownikow_lp; i++)
    {
        if(maksymalne_wartosci[0] < tablica_pracownikow_lp[i].getImie().length())
        {
            maksymalne_wartosci[0] = tablica_pracownikow_lp[i].getImie().length();
        }
    }
    if(maksymalne_wartosci[0] < 4) maksymalne_wartosci[0] = 5;
    maksymalne_wartosci[0] += 3;

    for(int i = 0; i < liczba_pracownikow_lp; i++)
    {
        if(maksymalne_wartosci[1] < tablica_pracownikow_lp[i].getNazwisko().length())
        {
            maksymalne_wartosci[1] = tablica_pracownikow_lp[i].getNazwisko().length();
        }
    }
    if(maksymalne_wartosci[1] < 9) maksymalne_wartosci[1] = 9;
    maksymalne_wartosci[1] += 3;

    for(int i = 0; i < liczba_pracownikow_lp; i++)
    {
        if(maksymalne_wartosci[2] < tablica_pracownikow_lp[i].getStanowisko().length())
        {
            maksymalne_wartosci[2] = tablica_pracownikow_lp[i].getStanowisko().length();
        }
    }
    if(maksymalne_wartosci[2] < 11) maksymalne_wartosci[2] = 11;
    maksymalne_wartosci[2] += 3;

    if(liczba_cyfr_lp(liczba_pracownikow_lp) < 4)
    {
        maksymalne_wartosci[3] = 3;
    }
    else
    {
        maksymalne_wartosci[3] = liczba_cyfr_lp(liczba_pracownikow_lp) - 1;
    }

    cout << " LP.";
    int przerwa = 4 - maksymalne_wartosci[3];
    for(int i = 0; i > przerwa; i--)
    {
        cout << " ";
    }

    cout << " STANOWISKO";
    przerwa = 11 - maksymalne_wartosci[2];
    for(int i = 0; i > przerwa; i--)
    {
        cout << " ";
    }

    cout << " IMIE";
    przerwa = 5 - maksymalne_wartosci[0];
    for(int i = 0; i > przerwa; i--)
    {
        cout << " ";
    }

    cout << " NAZWISKO";
    przerwa = 9 - maksymalne_wartosci[1];
    for(int i = 0; i > przerwa; i--)
    {
        cout << " ";
    }

    cout << " PENSJA" << endl;

    for(int j = 0; j < liczba_pracownikow_lp; j++)
    {
        cout << " " << j+1 << ".";
        przerwa = liczba_cyfr_lp(j+1) - maksymalne_wartosci[3];
        for(int i = 0; i > przerwa; i--)
        {
            cout << " ";
        }        
        
        cout << tablica_pracownikow_lp[j].getStanowisko();
        przerwa = tablica_pracownikow_lp[j].getStanowisko().length() - maksymalne_wartosci[2];
        for(int i = 0; i > przerwa; i--)
        {
            cout << " ";
        }

        cout << tablica_pracownikow_lp[j].getImie();
        przerwa = tablica_pracownikow_lp[j].getImie().length() - maksymalne_wartosci[0];
        for(int i = 0; i > przerwa; i--)
        {
            cout << " ";
        }

        cout << tablica_pracownikow_lp[j].getNazwisko();
        przerwa = tablica_pracownikow_lp[j].getNazwisko().length() - maksymalne_wartosci[1];
        for(int i = 0; i > przerwa; i--)
        {
            cout << " ";
        }

        cout << setprecision(2) << fixed << tablica_pracownikow_lp[j].getPensja() << endl;
    }
}

int liczba_cyfr_lp(int n)
{
    int i = 0;
    for(i = 0; n > 0; i++)
    {
        n = n / 10;
    }
    return i;
}