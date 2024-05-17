#include "main.h"
#include "spozywcze.h"
#include "przemyslowe.h"

int liczba_produktow_ups = 0;
Spozywcze tablica_produktow_ups[MAX];
int liczba_produktow_upp = 0;
Przemyslowe tablica_produktow_upp[MAX];

void wczytaj_produkt_ups();
void wczytaj_produkt_upp();
void usuwanie_produktu(int, int);

void usun_produkt()
{
    char wybor = '2';
    bool zmienna1 = false;
    bool zmienna2 = false;

    wczytaj_produkt_ups();
    wczytaj_produkt_upp();

    string kod;
    
    system("clear");
    
    linia();
    cout << "|                                          Usun  produkt                                          |" << endl;
    linia();

    cout << " Wprowadz kod produktu do usuniecia: ";
    cin >> kod;    

    bool zmienna3 = false;
    int zmienna4;
    int zmienna55;
    for(int a = 0; a < liczba_produktow_ups; a++)
    {
        if(tablica_produktow_ups[a].getKod() == kod)
        {
            zmienna3 = true;
            zmienna4 = a;
            zmienna55 = 1;
            break;
        }
    }
    
    if(zmienna3 == false)
    {
        for(int a = 0; a < liczba_produktow_upp; a++)
        {
            if(tablica_produktow_upp[a].getKod() == kod)
            {
                zmienna3 = true;
                zmienna4 = a;
                zmienna55 = 2;
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
                liczba_produktow_ups = 0;
                liczba_produktow_upp = 0;
                break;
            }

            system("clear");

            linia();
            cout << "|                                          Usun  produkt                                          |" << endl;
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
        bool zmienna5 = false;

        while(wybor)
        {
            if(zmienna2 == true)
            {
                liczba_produktow_upp = 0;
                liczba_produktow_ups = 0;

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
                    cout << "|                                          Usun  produkt                                          |" << endl;
                    linia();
                    
                    if(zmienna5 == true) cout << " Pomyslnie usunieto produkt." << endl;
                    else cout << " Nie usunieto produktu." << endl;
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
            cout << "|                                          Usun  produkt                                          |" << endl;
            linia();
            
            cout << " Czy na pewno chcesz usunac dane produktu '";
            if(zmienna55 == 1) cout << tablica_produktow_ups[zmienna4].getNazwa();
            if(zmienna55 == 2) cout << tablica_produktow_upp[zmienna4].getNazwa();
            cout << "'?" << endl;
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
                    usuwanie_produktu(zmienna4, zmienna55);
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

void wczytaj_produkt_ups()
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
        tablica_produktow_ups[liczba_produktow_ups].set(cena, kod, ilosc, nazwa, data, rozmiar);
        liczba_produktow_ups++;

        while(plik >> nazwa >> rozmiar >> data >> cena >> kod >> ilosc)
        {
            tablica_produktow_ups[liczba_produktow_ups].set(cena, kod, ilosc, nazwa, data, rozmiar);
            liczba_produktow_ups++;

            if(liczba_produktow_ups + 1 == MAX)
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

void wczytaj_produkt_upp()
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
        tablica_produktow_upp[liczba_produktow_upp].set(cena, kod, ilosc, nazwa, marka, kolor);
        liczba_produktow_upp++;

        while(plik >> nazwa >> marka >> kolor >> cena >> kod >> ilosc)
        {
            tablica_produktow_upp[liczba_produktow_upp].set(cena, kod, ilosc, nazwa, marka, kolor);
            liczba_produktow_upp++;

            if(liczba_produktow_upp + 1 == MAX)
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

void usuwanie_produktu(int zmienna4, int zmienna5)
{
    if(zmienna5 == 1)
    {
        for (int a = zmienna4; a < liczba_produktow_ups - 1; a++)
        {
            double _cena = tablica_produktow_ups[a + 1].getCena();
            string _kod = tablica_produktow_ups[a + 1].getKod();
            string _nazwa = tablica_produktow_ups[a + 1].getNazwa();
            string _data_waznosci = tablica_produktow_ups[a + 1].getData_waznosci();
            string _rozmiar = tablica_produktow_ups[a + 1].getRozmiar();
            int _ilosc = tablica_produktow_ups[a + 1].getIlosc();
            tablica_produktow_ups[a].set(_cena, _kod, _ilosc, _nazwa, _data_waznosci, _rozmiar);
        }
        liczba_produktow_ups--;
    }
    else if(zmienna5 == 2)
    {
        for (int a = zmienna4; a < liczba_produktow_upp - 1; a++)
        {
            double _cena = tablica_produktow_upp[a + 1].getCena();
            string _kod = tablica_produktow_upp[a + 1].getKod();
            string _nazwa = tablica_produktow_upp[a + 1].getNazwa();
            string _marka = tablica_produktow_upp[a + 1].getMarka();
            string _kolor = tablica_produktow_upp[a + 1].getKolor();
            int _ilosc = tablica_produktow_upp[a + 1].getIlosc();
            tablica_produktow_upp[a].set(_cena, _kod, _ilosc, _nazwa, _marka, _kolor);
        }
        liczba_produktow_upp--;
    }

    ofstream plik1("dane/produkty/spozywcze.txt", ios::out);
    if (!plik1)
    {
        cerr << " Blad otwarcia pliku!" << endl;
        exit(EXIT_FAILURE);
    }

    for(int a = 0; a < liczba_produktow_ups; a++)
    {
        plik1 << tablica_produktow_ups[a].getNazwa() << " " << tablica_produktow_ups[a].getRozmiar() << " " 
            << tablica_produktow_ups[a].getData_waznosci() << " " << tablica_produktow_ups[a].getCena() << " "
            << tablica_produktow_ups[a].getKod() << " " << tablica_produktow_ups[a].getIlosc() << endl;
    }

    ofstream plik2("dane/produkty/przemyslowe.txt", ios::out);
    if (!plik2)
    {
        cerr << " Blad otwarcia pliku!" << endl;
        exit(EXIT_FAILURE);
    }

    for(int a = 0; a < liczba_produktow_upp; a++)
    {
        plik2 << tablica_produktow_upp[a].getNazwa() << " " << tablica_produktow_upp[a].getMarka() << " " 
            << tablica_produktow_upp[a].getKolor() << " " << tablica_produktow_upp[a].getCena() << " "
            << tablica_produktow_upp[a].getKod() << " " << tablica_produktow_upp[a].getIlosc() << endl;
    }
}