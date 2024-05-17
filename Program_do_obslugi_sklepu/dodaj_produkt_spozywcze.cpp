#include "main.h"
#include "spozywcze.h"
#include "przemyslowe.h"

int liczba_produktow_ddps = 0;
Spozywcze tablica_produktow_ddps[MAX];
int liczba_produktow_ddpp = 0;
Przemyslowe tablica_produktow_ddpp[MAX];

int liczba_cyfr_lps(int);
void wczytaj_produkt_ddps();
void wczytaj_produkt_ddpp();

void dodaj_produkt_spozywcze()
{
    string nazwa, rozmiar, data, kod;
    double cena;
    int ilosc;
    
    system("clear");
    
    wczytaj_produkt_ddps();
    wczytaj_produkt_ddpp();
    
    linia();
    cout << "|                                          Dodaj produkt                                          |" << endl;
    linia();

    cout << " Wprowadz nazwe: ";
    cin >> nazwa;
    cout << " Wprowadz rozmiar/ilosc: ";
    cin >> rozmiar;
    cout << " Wprowadz date waznosci: ";
    cin >> data;
    try
    {
        cout << " Wprowadz dostepna ilosc: ";
        if((cin >> ilosc).fail())
        {
            throw bad_cast();
        }    
        cout << " Wprowadz cene: ";
        if((cin >> cena).fail())
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
    cout << " Wprowadz kod produktu: ";
    cin >> kod;   

    bool zmienna4 = false;

    while(1)
    {
        bool zmienna3 = false;
        for(int a = 0; a < liczba_produktow_ddps; a++)
        {
            if(tablica_produktow_ddps[a].getKod() == kod)
            {
                zmienna3 = true;
                zmienna4 = true;
                break;
            }
        }
        
        if(zmienna3 == false)
        {
            for(int a = 0; a < liczba_produktow_ddpp; a++)
            {
                if(tablica_produktow_ddpp[a].getKod() == kod)
                {
                    zmienna3 = true;
                    zmienna4 = true;
                    break;
                }
            }
        }
        
        if(zmienna3 == true)
        {
            int kod_int = rand() % 99999999999;
            int l_c = liczba_cyfr_lps(kod_int);
            string kod_pomocniczy;
            for(int b = 0; b < 11-l_c; b++)
            {
                kod_pomocniczy += "0";
            }
            kod_pomocniczy += to_string(kod_int);
            kod = kod_pomocniczy;
            
        }

        if(zmienna3 == false) break;
    }

    Spozywcze pomocniczy(cena, kod, ilosc, nazwa, data, rozmiar);

    ofstream plik("dane/produkty/spozywcze.txt", ios::app);
    if (!plik)
    {
        cerr << " Blad otwarcia pliku!" << endl;
        exit(EXIT_FAILURE);
    }

    plik << pomocniczy.getNazwa() << " " << pomocniczy.getRozmiar() << " " 
        << pomocniczy.getData_waznosci() << " " << pomocniczy.getCena() << " "
        << pomocniczy.getKod() << " " << pomocniczy.getIlosc() << endl;

    char wybor = '2';
    bool zmienna1 = false;
    bool zmienna2 = false;

    while(wybor)
    {
        if(zmienna2 == true)
        {
            liczba_produktow_ddps = 0;
            liczba_produktow_ddpp = 0;
            break;
        }
        
        system("clear");
        
        linia();
        cout << "|                                          Dodaj produkt                                          |" << endl;
        linia();
        
        cout << " Pomyslnie dodano nowy produkt." << endl;
        linia();

        if(zmienna4 == true)
        {
            cout << " Wprowadzony kod jest juz zajety, dlatego wygenerowano nowy: " << pomocniczy.getKod() << endl;
            linia();
        }

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

void wczytaj_produkt_ddps()
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
        tablica_produktow_ddps[liczba_produktow_ddps].set(cena, kod, ilosc, nazwa, data, rozmiar);
        liczba_produktow_ddps++;

        while(plik >> nazwa >> rozmiar >> data >> cena >> kod >> ilosc)
        {
            tablica_produktow_ddps[liczba_produktow_ddps].set(cena, kod, ilosc, nazwa, data, rozmiar);
            liczba_produktow_ddps++;

            if(liczba_produktow_ddps + 1 == MAX)
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

void wczytaj_produkt_ddpp()
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
        tablica_produktow_ddpp[liczba_produktow_ddpp].set(cena, kod, ilosc, nazwa, marka, kolor);
        liczba_produktow_ddpp++;

        while(plik >> nazwa >> marka >> kolor >> cena >> kod >> ilosc)
        {
            tablica_produktow_ddpp[liczba_produktow_ddpp].set(cena, kod, ilosc, nazwa, marka, kolor);
            liczba_produktow_ddpp++;

            if(liczba_produktow_ddpp + 1 == MAX)
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