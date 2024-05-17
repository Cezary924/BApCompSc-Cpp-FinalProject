#include "main.h"
#include "przemyslowe.h"

int liczba_produktow_przemyslowe = 0;
Przemyslowe tablica_produktow_przemyslowe[MAX];

void wczytaj_produkt_przemyslowe();
void wydrukuj_produkt_p();
int liczba_cyfr_lpp(int);

void lista_produkt_przemyslowe()
{
    char wybor = '2';
    bool zmienna1 = false;
    bool zmienna2 = false;

    wczytaj_produkt_przemyslowe();

    while(wybor)
    {
        if(zmienna2 == true)
        {
            liczba_produktow_przemyslowe = 0;
            break;
        }
        system("clear");
        linia();

        cout << "|                                      Artykuly  przemyslowe                                      |" << endl;
        linia();

        wydrukuj_produkt_p();
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

void wczytaj_produkt_przemyslowe()
{
    ifstream plik("dane/produkty/przemyslowe.txt", ios::in);
    if (!plik)
    {
        linia();
        cerr << " Blad otwarcia pliku!" << endl;
        linia();
        exit(EXIT_FAILURE);
    }

    string nazwa;
    string marka;
    string kolor;
    double cena;
    string kod;
    int ilosc;
    if (plik >> nazwa >> marka >> kolor >> cena >> kod >> ilosc)
    {
        tablica_produktow_przemyslowe[liczba_produktow_przemyslowe].set(cena, kod, ilosc, nazwa, marka, kolor);
        liczba_produktow_przemyslowe++;

        while(plik >> nazwa >> marka >> kolor >> cena >> kod >> ilosc)
        {
            tablica_produktow_przemyslowe[liczba_produktow_przemyslowe].set(cena, kod, ilosc, nazwa, marka, kolor);
            liczba_produktow_przemyslowe++;

            if(liczba_produktow_przemyslowe + 1 == MAX)
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

void wydrukuj_produkt_p()
{
    int maksymalne_wartosci[6] = {0, 0, 0, 0, 0, 0};

    for(int i = 0; i < liczba_produktow_przemyslowe; i++)
    {
        if(maksymalne_wartosci[0] < tablica_produktow_przemyslowe[i].getNazwa().length())
        {
            maksymalne_wartosci[0] = tablica_produktow_przemyslowe[i].getNazwa().length();
        }
    }
    if(maksymalne_wartosci[0] < 6) maksymalne_wartosci[0] = 6;
    maksymalne_wartosci[0] += 3;

    for(int i = 0; i < liczba_produktow_przemyslowe; i++)
    {
        if(maksymalne_wartosci[1] < tablica_produktow_przemyslowe[i].getMarka().length())
        {
            maksymalne_wartosci[1] = tablica_produktow_przemyslowe[i].getMarka().length();
        }
    }
    if(maksymalne_wartosci[1] < 6) maksymalne_wartosci[1] = 6;
    maksymalne_wartosci[1] += 3;

    for(int i = 0; i < liczba_produktow_przemyslowe; i++)
    {
        if(maksymalne_wartosci[2] < tablica_produktow_przemyslowe[i].getKolor().length())
        {
            maksymalne_wartosci[2] = tablica_produktow_przemyslowe[i].getKolor().length();
        }
    }
    if(maksymalne_wartosci[2] < 6) maksymalne_wartosci[2] = 6;
    maksymalne_wartosci[2] += 3;

    for(int i = 0; i < liczba_produktow_przemyslowe; i++)
    {
        if(maksymalne_wartosci[3] < tablica_produktow_przemyslowe[i].getKod().length())
        {
            maksymalne_wartosci[3] = tablica_produktow_przemyslowe[i].getKod().length();
        }
    }
    if(maksymalne_wartosci[3] < 12) maksymalne_wartosci[3] = 12;
    maksymalne_wartosci[3] += 3;

    for(int i = 0; i < liczba_produktow_przemyslowe; i++)
    {
        if(maksymalne_wartosci[4] < liczba_cyfr_lpp(tablica_produktow_przemyslowe[i].getIlosc()))
        {
            maksymalne_wartosci[4] = liczba_cyfr_lpp(tablica_produktow_przemyslowe[i].getIlosc());
        }
    }
    if(maksymalne_wartosci[4] < 15) maksymalne_wartosci[4] = 15;
    maksymalne_wartosci[4] += 3;

    if(liczba_cyfr_lpp(liczba_produktow_przemyslowe) < 4)
    {
        maksymalne_wartosci[5] = 3;
    }
    else
    {
        maksymalne_wartosci[5] = liczba_cyfr_lpp(liczba_produktow_przemyslowe) - 1;
    }

    cout << " LP.";
    int przerwa = 4 - maksymalne_wartosci[5];
    for(int i = 0; i > przerwa; i--)
    {
        cout << " ";
    }

    cout << " NAZWA";
    przerwa = 6 - maksymalne_wartosci[0];
    for(int i = 0; i > przerwa; i--)
    {
        cout << " ";
    }

    cout << " MARKA";
    przerwa = 6 - maksymalne_wartosci[1];
    for(int i = 0; i > przerwa; i--)
    {
        cout << " ";
    }

    cout << " KOLOR";
    przerwa = 6 - maksymalne_wartosci[2];
    for(int i = 0; i > przerwa; i--)
    {
        cout << " ";
    }

    cout << " DOSTEPNA ILOSC";
    przerwa = 15 - maksymalne_wartosci[4];
    for(int i = 0; i > przerwa; i--)
    {
        cout << " ";
    }

    cout << " KOD PRODUKTU";
    przerwa = 13 - maksymalne_wartosci[3];
    for(int i = 0; i > przerwa; i--)
    {
        cout << " ";
    }

    cout << " CENA" << endl;

    for(int j = 0; j < liczba_produktow_przemyslowe; j++)
    {
        cout << " " << j+1 << ".";
        przerwa = liczba_cyfr_lpp(j+1) - maksymalne_wartosci[5];
        for(int i = 0; i > przerwa; i--)
        {
            cout << " ";
        }        
        
        cout << tablica_produktow_przemyslowe[j].getNazwa();
        przerwa = tablica_produktow_przemyslowe[j].getNazwa().length() - maksymalne_wartosci[0];
        for(int i = 0; i > przerwa; i--)
        {
            cout << " ";
        }

        cout << tablica_produktow_przemyslowe[j].getMarka();
        przerwa = tablica_produktow_przemyslowe[j].getMarka().length() - maksymalne_wartosci[1];
        for(int i = 0; i > przerwa; i--)
        {
            cout << " ";
        }

        cout << tablica_produktow_przemyslowe[j].getKolor();
        przerwa = tablica_produktow_przemyslowe[j].getKolor().length() - maksymalne_wartosci[2];
        for(int i = 0; i > przerwa; i--)
        {
            cout << " ";
        }

        cout << tablica_produktow_przemyslowe[j].getIlosc();
        przerwa = liczba_cyfr_lpp(tablica_produktow_przemyslowe[j].getIlosc()) - maksymalne_wartosci[4];
        for(int i = 0; i > przerwa; i--)
        {
            cout << " ";
        }   

        cout << tablica_produktow_przemyslowe[j].getKod();
        przerwa = tablica_produktow_przemyslowe[j].getKod().length() - maksymalne_wartosci[3];
        for(int i = 0; i > przerwa; i--)
        {
            cout << " ";
        }

        cout << setprecision(2) << fixed << tablica_produktow_przemyslowe[j].getCena() << endl;
    }
}

int liczba_cyfr_lpp(int n)
{
    int i = 0;
    for(i = 0; n > 0; i++)
    {
        n = n / 10;
    }
    return i;
}