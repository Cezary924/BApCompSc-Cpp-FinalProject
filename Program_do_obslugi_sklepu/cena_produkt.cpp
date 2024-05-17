#include "main.h"
#include "spozywcze.h"
#include "przemyslowe.h"

int liczba_produktow_cps = 0;
Spozywcze tablica_produktow_cps[MAX];
int liczba_produktow_cpp = 0;
Przemyslowe tablica_produktow_cpp[MAX];

void wczytaj_produkt_cps();
void wczytaj_produkt_cpp();

void cena_produkt()
{
    char wybor = '2';
    bool zmienna1 = false;
    bool zmienna2 = false;

    wczytaj_produkt_cps();
    wczytaj_produkt_cpp();

    string kod;
    
    system("clear");
    
    linia();
    cout << "|                                          Cena produktu                                          |" << endl;
    linia();

    cout << " Wprowadz kod produktu: ";
    cin >> kod; 

    bool zmienna3 = false;
    int zmienna4;
    int zmienna5;
    for(int a = 0; a < liczba_produktow_cps; a++)
    {
        if(tablica_produktow_cps[a].getKod() == kod)
        {
            zmienna3 = true;
            zmienna4 = a;
            zmienna5 = 1;
            break;
        }
    }
    
    if(zmienna3 == false)
    {
        for(int a = 0; a < liczba_produktow_cpp; a++)
        {
            if(tablica_produktow_cpp[a].getKod() == kod)
            {
                zmienna3 = true;
                zmienna4 = a;
                zmienna5 = 2;
                break;
            }
        }
    }

    if (zmienna3 == false)
    {
        while(wybor)
        {
            if(zmienna2 == true)
            {
                liczba_produktow_cps = 0;
                liczba_produktow_cpp = 0;
                break;
            }

            system("clear");

            linia();
            cout << "|                                          Cena produktu                                          |" << endl;
            linia();
            
            cout << " Nie znaleziono produktu o podanym kodzie." << endl;
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

        while(wybor)
        {   
            if(zmienna2 == true)
            {
                liczba_produktow_cps = 0;
                liczba_produktow_cpp = 0;
                break;
            }
            
            system("clear");
            linia();
            cout << "|                                          Cena produktu                                          |" << endl;
            linia();
            
            if(zmienna5 == 1) cout << " Cena produktu '" << tablica_produktow_cps[zmienna4].getNazwa() << "' o kodzie " << tablica_produktow_cps[zmienna4].getKod() << " to " << setprecision(2) << fixed << tablica_produktow_cps[zmienna4].getCena() << endl;
            else if(zmienna5 == 2) cout << " Cena produktu '" << tablica_produktow_cpp[zmienna4].getNazwa() << "' o kodzie " << tablica_produktow_cpp[zmienna4].getKod() << " to " << setprecision(2) << fixed << tablica_produktow_cpp[zmienna4].getCena() << endl;
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

void wczytaj_produkt_cps()
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
        tablica_produktow_cps[liczba_produktow_cps].set(cena, kod, ilosc, nazwa, data, rozmiar);
        liczba_produktow_cps++;

        while(plik >> nazwa >> rozmiar >> data >> cena >> kod >> ilosc)
        {
            tablica_produktow_cps[liczba_produktow_cps].set(cena, kod, ilosc, nazwa, data, rozmiar);
            liczba_produktow_cps++;

            if(liczba_produktow_cps + 1 == MAX)
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

void wczytaj_produkt_cpp()
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
        tablica_produktow_cpp[liczba_produktow_cpp].set(cena, kod, ilosc, nazwa, marka, kolor);
        liczba_produktow_cpp++;

        while(plik >> nazwa >> marka >> kolor >> cena >> kod >> ilosc)
        {
            tablica_produktow_cpp[liczba_produktow_cpp].set(cena, kod, ilosc, nazwa, marka, kolor);
            liczba_produktow_cpp++;

            if(liczba_produktow_cpp + 1 == MAX)
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