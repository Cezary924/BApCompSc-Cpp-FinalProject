#include "main.h"
#include "spozywcze.h"
#include "przemyslowe.h"

int liczba_produktow_dps = 0;
Spozywcze tablica_produktow_dps[MAX];
int liczba_produktow_dpp = 0;
Przemyslowe tablica_produktow_dpp[MAX];

void wczytaj_produkt_dps();
void wczytaj_produkt_dpp();

void dostepnosc_produkt()
{
    char wybor = '2';
    bool zmienna1 = false;
    bool zmienna2 = false;

    wczytaj_produkt_dps();
    wczytaj_produkt_dpp();

    string kod;
    
    system("clear");
    
    linia();
    cout << "|                                       Dostepnosc produktu                                       |" << endl;
    linia();

    cout << " Wprowadz kod produktu: ";
    cin >> kod; 

    bool zmienna3 = false;
    int zmienna4;
    int zmienna5;
    for(int a = 0; a < liczba_produktow_dps; a++)
    {
        if(tablica_produktow_dps[a].getKod() == kod)
        {
            zmienna3 = true;
            zmienna4 = a;
            zmienna5 = 1;
            break;
        }
    }
    
    if(zmienna3 == false)
    {
        for(int a = 0; a < liczba_produktow_dpp; a++)
        {
            if(tablica_produktow_dpp[a].getKod() == kod)
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
                liczba_produktow_dps = 0;
                liczba_produktow_dpp = 0;
                break;
            }

            system("clear");

            linia();
            cout << "|                                       Dostepnosc produktu                                       |" << endl;
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
                liczba_produktow_dps = 0;
                liczba_produktow_dpp = 0;
                break;
            }
            
            system("clear");
            linia();
            cout << "|                                       Dostepnosc produktu                                       |" << endl;
            linia();
            
            if(zmienna5 == 1) cout << " Dostepna ilosc produktu '" << tablica_produktow_dps[zmienna4].getNazwa() << "' o kodzie " << tablica_produktow_dps[zmienna4].getKod() << ": " << setprecision(2) << fixed << tablica_produktow_dps[zmienna4].getIlosc() << endl;
            else if(zmienna5 == 2) cout << " Dostepna ilosc produktu '" << tablica_produktow_dpp[zmienna4].getNazwa() << "' o kodzie " << tablica_produktow_dpp[zmienna4].getKod() << ": " << setprecision(2) << fixed << tablica_produktow_dpp[zmienna4].getIlosc() << endl;
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

void wczytaj_produkt_dps()
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
        tablica_produktow_dps[liczba_produktow_dps].set(cena, kod, ilosc, nazwa, data, rozmiar);
        liczba_produktow_dps++;

        while(plik >> nazwa >> rozmiar >> data >> cena >> kod >> ilosc)
        {
            tablica_produktow_dps[liczba_produktow_dps].set(cena, kod, ilosc, nazwa, data, rozmiar);
            liczba_produktow_dps++;

            if(liczba_produktow_dps + 1 == MAX)
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

void wczytaj_produkt_dpp()
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
        tablica_produktow_dpp[liczba_produktow_dpp].set(cena, kod, ilosc, nazwa, marka, kolor);
        liczba_produktow_dpp++;

        while(plik >> nazwa >> marka >> kolor >> cena >> kod >> ilosc)
        {
            tablica_produktow_dpp[liczba_produktow_dpp].set(cena, kod, ilosc, nazwa, marka, kolor);
            liczba_produktow_dpp++;

            if(liczba_produktow_dpp + 1 == MAX)
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