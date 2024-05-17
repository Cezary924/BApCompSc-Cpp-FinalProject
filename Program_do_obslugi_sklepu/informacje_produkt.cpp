#include "main.h"
#include "spozywcze.h"
#include "przemyslowe.h"

int liczba_produktow_ips = 0;
Spozywcze tablica_produktow_ips[MAX];
int liczba_produktow_ipp = 0;
Przemyslowe tablica_produktow_ipp[MAX];

void wczytaj_produkt_ips();
void wczytaj_produkt_ipp();

void informacje_produkt()
{
    char wybor = '2';
    bool zmienna1 = false;
    bool zmienna2 = false;

    wczytaj_produkt_ips();
    wczytaj_produkt_ipp();

    string kod;
    
    system("clear");
    
    linia();
    cout << "|                                      Informacje o produkcie                                     |" << endl;
    linia();

    cout << " Wprowadz kod produktu: ";
    cin >> kod; 

    bool zmienna3 = false;
    int zmienna4;
    int zmienna5;
    for(int a = 0; a < liczba_produktow_ips; a++)
    {
        if(tablica_produktow_ips[a].getKod() == kod)
        {
            zmienna3 = true;
            zmienna4 = a;
            zmienna5 = 1;
            break;
        }
    }
    
    if(zmienna3 == false)
    {
        for(int a = 0; a < liczba_produktow_ipp; a++)
        {
            if(tablica_produktow_ipp[a].getKod() == kod)
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
                liczba_produktow_ips = 0;
                liczba_produktow_ipp = 0;
                break;
            }

            system("clear");

            linia();
            cout << "|                                      Informacje o produkcie                                     |" << endl;
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
                liczba_produktow_ips = 0;
                liczba_produktow_ipp = 0;
                break;
            }
            
            system("clear");
            linia();
            cout << "|                                      Informacje o produkcie                                     |" << endl;
            linia();
            
            if(zmienna5 == 1) cout << tablica_produktow_ips[zmienna4].wypisz();
            else if(zmienna5 == 2) cout << tablica_produktow_ipp[zmienna4].wypisz();
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

void wczytaj_produkt_ips()
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
        tablica_produktow_ips[liczba_produktow_ips].set(cena, kod, ilosc, nazwa, data, rozmiar);
        liczba_produktow_ips++;

        while(plik >> nazwa >> rozmiar >> data >> cena >> kod >> ilosc)
        {
            tablica_produktow_ips[liczba_produktow_ips].set(cena, kod, ilosc, nazwa, data, rozmiar);
            liczba_produktow_ips++;

            if(liczba_produktow_ips + 1 == MAX)
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

void wczytaj_produkt_ipp()
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
        tablica_produktow_ipp[liczba_produktow_ipp].set(cena, kod, ilosc, nazwa, marka, kolor);
        liczba_produktow_ipp++;

        while(plik >> nazwa >> marka >> kolor >> cena >> kod >> ilosc)
        {
            tablica_produktow_ipp[liczba_produktow_ipp].set(cena, kod, ilosc, nazwa, marka, kolor);
            liczba_produktow_ipp++;

            if(liczba_produktow_ipp + 1 == MAX)
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