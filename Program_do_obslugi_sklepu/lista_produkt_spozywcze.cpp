#include "main.h"
#include "spozywcze.h"

int liczba_produktow_spozywcze = 0;
Spozywcze tablica_produktow_spozywcze[MAX];

void wczytaj_produkt_spozywcze();
void wydrukuj_produkt_s();
int liczba_cyfr_lps(int);

void lista_produkt_spozywcze()
{
    char wybor = '2';
    bool zmienna1 = false;
    bool zmienna2 = false;

    wczytaj_produkt_spozywcze();

    while(wybor)
    {
        if(zmienna2 == true)
        {
            liczba_produktow_spozywcze = 0;
            break;
        }
        system("clear");
        linia();

        cout << "|                                       Artykuly  spozywcze                                       |" << endl;
        linia();

        wydrukuj_produkt_s();
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

void wczytaj_produkt_spozywcze()
{
    ifstream plik("dane/produkty/spozywcze.txt", ios::in);
    if (!plik)
    {
        linia();
        cerr << " Blad otwarcia pliku!" << endl;
        linia();
        exit(EXIT_FAILURE);
    }

    string nazwa;
    string rozmiar;
    string data;
    double cena;
    string kod;
    int ilosc;
    if (plik >> nazwa >> rozmiar >> data >> cena >> kod >> ilosc)
    {
        tablica_produktow_spozywcze[liczba_produktow_spozywcze].set(cena, kod, ilosc, nazwa, data, rozmiar);
        liczba_produktow_spozywcze++;

        while(plik >> nazwa >> rozmiar >> data >> cena >> kod >> ilosc)
        {
            tablica_produktow_spozywcze[liczba_produktow_spozywcze].set(cena, kod, ilosc, nazwa, data, rozmiar);
            liczba_produktow_spozywcze++;

            if(liczba_produktow_spozywcze + 1 == MAX)
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

void wydrukuj_produkt_s()
{
    int maksymalne_wartosci[6] = {0, 0, 0, 0, 0, 0};

    for(int i = 0; i < liczba_produktow_spozywcze; i++)
    {
        if(maksymalne_wartosci[0] < tablica_produktow_spozywcze[i].getNazwa().length())
        {
            maksymalne_wartosci[0] = tablica_produktow_spozywcze[i].getNazwa().length();
        }
    }
    if(maksymalne_wartosci[0] < 6) maksymalne_wartosci[0] = 6;
    maksymalne_wartosci[0] += 3;

    for(int i = 0; i < liczba_produktow_spozywcze; i++)
    {
        if(maksymalne_wartosci[1] < tablica_produktow_spozywcze[i].getRozmiar().length())
        {
            maksymalne_wartosci[1] = tablica_produktow_spozywcze[i].getRozmiar().length();
        }
    }
    if(maksymalne_wartosci[1] < 14) maksymalne_wartosci[1] = 14;
    maksymalne_wartosci[1] += 3;

    for(int i = 0; i < liczba_produktow_spozywcze; i++)
    {
        if(maksymalne_wartosci[2] < tablica_produktow_spozywcze[i].getData_waznosci().length())
        {
            maksymalne_wartosci[2] = tablica_produktow_spozywcze[i].getData_waznosci().length();
        }
    }
    if(maksymalne_wartosci[2] < 14) maksymalne_wartosci[2] = 14;
    maksymalne_wartosci[2] += 3;

    for(int i = 0; i < liczba_produktow_spozywcze; i++)
    {
        if(maksymalne_wartosci[3] < tablica_produktow_spozywcze[i].getKod().length())
        {
            maksymalne_wartosci[3] = tablica_produktow_spozywcze[i].getKod().length();
        }
    }
    if(maksymalne_wartosci[3] < 12) maksymalne_wartosci[3] = 12;
    maksymalne_wartosci[3] += 3;

    for(int i = 0; i < liczba_produktow_spozywcze; i++)
    {
        if(maksymalne_wartosci[4] < liczba_cyfr_lps(tablica_produktow_spozywcze[i].getIlosc()))
        {
            maksymalne_wartosci[4] = liczba_cyfr_lps(tablica_produktow_spozywcze[i].getIlosc());
        }
    }
    if(maksymalne_wartosci[4] < 15) maksymalne_wartosci[4] = 15;
    maksymalne_wartosci[4] += 3;

    if(liczba_cyfr_lps(liczba_produktow_spozywcze) < 4)
    {
        maksymalne_wartosci[5] = 3;
    }
    else
    {
        maksymalne_wartosci[5] = liczba_cyfr_lps(liczba_produktow_spozywcze) - 1;
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

    cout << " ROZMIAR/ILOSC";
    przerwa = 14 - maksymalne_wartosci[1];
    for(int i = 0; i > przerwa; i--)
    {
        cout << " ";
    }

    cout << " DATA WAZNOSCI";
    przerwa = 14 - maksymalne_wartosci[2];
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

    for(int j = 0; j < liczba_produktow_spozywcze; j++)
    {
        cout << " " << j+1 << ".";
        przerwa = liczba_cyfr_lps(j+1) - maksymalne_wartosci[5];
        for(int i = 0; i > przerwa; i--)
        {
            cout << " ";
        }        
        
        cout << tablica_produktow_spozywcze[j].getNazwa();
        przerwa = tablica_produktow_spozywcze[j].getNazwa().length() - maksymalne_wartosci[0];
        for(int i = 0; i > przerwa; i--)
        {
            cout << " ";
        }

        cout << tablica_produktow_spozywcze[j].getRozmiar();
        przerwa = tablica_produktow_spozywcze[j].getRozmiar().length() - maksymalne_wartosci[1];
        for(int i = 0; i > przerwa; i--)
        {
            cout << " ";
        }

        cout << tablica_produktow_spozywcze[j].getData_waznosci();
        przerwa = tablica_produktow_spozywcze[j].getData_waznosci().length() - maksymalne_wartosci[2];
        for(int i = 0; i > przerwa; i--)
        {
            cout << " ";
        }

        cout << tablica_produktow_spozywcze[j].getIlosc();
        przerwa = liczba_cyfr_lps(tablica_produktow_spozywcze[j].getIlosc()) - maksymalne_wartosci[4];
        for(int i = 0; i > przerwa; i--)
        {
            cout << " ";
        }  

        cout << tablica_produktow_spozywcze[j].getKod();
        przerwa = tablica_produktow_spozywcze[j].getKod().length() - maksymalne_wartosci[3];
        for(int i = 0; i > przerwa; i--)
        {
            cout << " ";
        }

        cout << setprecision(2) << fixed << tablica_produktow_spozywcze[j].getCena() << endl;
    }
}

int liczba_cyfr_lps(int n)
{
    int i = 0;
    for(i = 0; n > 0; i++)
    {
        n = n / 10;
    }
    return i;
}