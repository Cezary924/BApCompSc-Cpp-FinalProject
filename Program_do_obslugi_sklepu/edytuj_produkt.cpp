#include "main.h"
#include "spozywcze.h"
#include "przemyslowe.h"

int liczba_produktow_eps = 0;
Spozywcze tablica_produktow_eps[MAX];
int liczba_produktow_epp = 0;
Przemyslowe tablica_produktow_epp[MAX];

void wczytaj_produkt_eps();
void wczytaj_produkt_epp();
void e_a_s(int, int);
void e_a_p(int, int);
void zapisz_do_pliku();

void edytuj_produkt()
{
    char wybor = '2';
    bool zmienna1 = false;
    bool zmienna2 = false;

    wczytaj_produkt_eps();
    wczytaj_produkt_epp();

    string kod;
    
    system("clear");
    
    linia();
    cout << "|                                         Edytuj  produkt                                         |" << endl;
    linia();

    cout << " Wprowadz kod produktu: ";
    cin >> kod;  

    bool zmienna3 = false;
    int zmienna4, zmienna5;
    for(int a = 0; a < liczba_produktow_eps; a++)
    {
        if(tablica_produktow_eps[a].getKod() == kod)
        {
            zmienna3 = true;
            zmienna4 = a;
            zmienna5 = 1;
            break;
        }
    }
    
    if(zmienna3 == false)
    {
        for(int a = 0; a < liczba_produktow_epp; a++)
        {
            if(tablica_produktow_epp[a].getKod() == kod)
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
                liczba_produktow_epp = 0;
                liczba_produktow_eps = 0;
                break;
            }

            system("clear");

            linia();
            cout << "|                                         Edytuj  produkt                                         |" << endl;
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
        while(wybor)
        {
            if(zmienna2 == true)
            {
                liczba_produktow_epp = 0;
                liczba_produktow_eps = 0;
                break;
            }

            system("clear");

            linia();
            cout << "|                                         Edytuj  produkt                                         |" << endl;
            linia();
            
            cout << " Wybierz nowy typ produktu:" << endl;
            linia();

            cout << " 1. Artykul spozywczy." << endl;
            cout << " 2. Artykul przemyslowy." << endl;
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
                    e_a_s(zmienna4, zmienna5);
                    zmienna2 = true;
                    break;

                case '2':
                    e_a_p(zmienna4, zmienna5);
                    zmienna2 = true;
                    break;

                default:
                    zmienna1 = true;
                    break;
            };
        }
    }        
}        

void e_a_s(int zmienna4, int zmienna5)
{
    bool zmienna6 = false;
    if(zmienna5 == 1)
    {
        double cena;
        string kod, nazwa, data_waznosci, rozmiar;
        int ilosc;

        cout << " Wprowadz nazwe: ";
        cin >> nazwa;
        cout << " Wprowadz rozmiar/ilosc: ";
        cin >> rozmiar;
        cout << " Wprowadz date waznosci: ";
        cin >> data_waznosci;
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
        tablica_produktow_eps[zmienna4].set(cena, kod, ilosc, nazwa, data_waznosci, rozmiar);

        zapisz_do_pliku();
    }
    else
    {
        if(liczba_produktow_eps < MAX)
        {
            double cena;
            string kod, nazwa, data_waznosci, rozmiar;
            int ilosc;

            cout << " Wprowadz nazwe: ";
            cin >> nazwa;
            cout << " Wprowadz rozmiar/ilosc: ";
            cin >> rozmiar;
            cout << " Wprowadz date waznosci: ";
            cin >> data_waznosci;
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

            tablica_produktow_eps[liczba_produktow_eps].set(cena, kod, ilosc, nazwa, data_waznosci, rozmiar);
            for(int a = zmienna4; a < liczba_produktow_epp-1; a++)
            {
                double _cena = tablica_produktow_epp[a+1].getCena();
                string _kod = tablica_produktow_epp[a+1].getKod();
                string _nazwa = tablica_produktow_epp[a+1].getNazwa();
                string _marka = tablica_produktow_epp[a+1].getMarka();
                string _kolor = tablica_produktow_epp[a+1].getKolor();
                int _ilosc = tablica_produktow_epp[a+1].getIlosc();
                tablica_produktow_epp[a].set(_cena, _kod, _ilosc, _nazwa, _marka, _kolor);
            }
            liczba_produktow_eps++;
            liczba_produktow_epp--;

            zapisz_do_pliku();
        }
        else
        {
            zmienna6 = true;
            char wybor = '2';
            bool zmienna1 = false;
            bool zmienna2 = false;
            while (wybor)
            {
                if (zmienna2 == true)
                {
                    liczba_produktow_epp = 0;
                    liczba_produktow_eps = 0;
                    break;
                }

                system("clear");

                linia();
                cout << "|                                         Edytuj  produkt                                         |" << endl;
                linia();

                cout << " Przekroczono limit produktow." << endl;
                linia();

                cout << " 0. Cofnij." << endl;
                linia();

                if (zmienna1 == true)
                {
                    cout << " Nie ma takiej opcji!" << endl;
                    linia();
                }
                zmienna1 = false;

                cout << " Twoj wybor: ";
                cin >> wybor;
                linia();

                switch (wybor)
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
    if(zmienna6 == false)
    {
        char wybor = '2';
        bool zmienna1 = false;
        bool zmienna2 = false;
        while (wybor)
        {
            if (zmienna2 == true)
            {
                liczba_produktow_epp = 0;
                liczba_produktow_eps = 0;
                break;
            }

            system("clear");

            linia();
            cout << "|                                         Edytuj  produkt                                         |" << endl;
            linia();

            cout << " Pomyslnie edytowano dane produktu." << endl;
            linia();

            cout << " 0. Cofnij." << endl;
            linia();

            if (zmienna1 == true)
            {
                cout << " Nie ma takiej opcji!" << endl;
                linia();
            }
            zmienna1 = false;

            cout << " Twoj wybor: ";
            cin >> wybor;
            linia();

            switch (wybor)
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

void e_a_p(int zmienna4, int zmienna5)
{
    bool zmienna6 = false;
    if(zmienna5 == 2)
    {
        double cena;
        string kod, nazwa, marka, kolor;
        int ilosc;

        cout << " Wprowadz nazwe: ";
        cin >> nazwa;
        cout << " Wprowadz marke: ";
        cin >> marka;
        cout << " Wprowadz kolor: ";
        cin >> kolor;
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
        tablica_produktow_epp[zmienna4].set(cena, kod, ilosc, nazwa, marka, kolor);

        zapisz_do_pliku();
    }
    else
    {
        if(liczba_produktow_epp < MAX)
        {
            double cena;
            string kod, nazwa, marka, kolor;
            int ilosc;

            cout << " Wprowadz nazwe: ";
            cin >> nazwa;
            cout << " Wprowadz marke: ";
            cin >> marka;
            cout << " Wprowadz kolor: ";
            cin >> kolor;
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
            tablica_produktow_epp[liczba_produktow_epp].set(cena, kod, ilosc, nazwa, marka, kolor);
            
            for(int a = zmienna4; a < liczba_produktow_eps-1; a++)
            {
                double _cena = tablica_produktow_eps[a+1].getCena();
                string _kod = tablica_produktow_eps[a+1].getKod();
                string _nazwa = tablica_produktow_eps[a+1].getNazwa();
                string _data_waznosci = tablica_produktow_eps[a+1].getData_waznosci();
                string _rozmiar = tablica_produktow_eps[a+1].getRozmiar();
                int _ilosc = tablica_produktow_eps[a+1].getIlosc();
                tablica_produktow_eps[a].set(_cena, _kod, _ilosc, _nazwa, _data_waznosci, _rozmiar);
            }
            liczba_produktow_eps--;
            liczba_produktow_epp++;

            zapisz_do_pliku();
        }
        else
        {
            zmienna6 = true;
            char wybor = '2';
            bool zmienna1 = false;
            bool zmienna2 = false;
            while (wybor)
            {
                if (zmienna2 == true)
                {
                    liczba_produktow_epp = 0;
                    liczba_produktow_eps = 0;
                    break;
                }

                system("clear");

                linia();
                cout << "|                                         Edytuj  produkt                                         |" << endl;
                linia();

                cout << " Przekroczono limit produktow." << endl;
                linia();

                cout << " 0. Cofnij." << endl;
                linia();

                if (zmienna1 == true)
                {
                    cout << " Nie ma takiej opcji!" << endl;
                    linia();
                }
                zmienna1 = false;

                cout << " Twoj wybor: ";
                cin >> wybor;
                linia();

                switch (wybor)
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
    if(zmienna6 == false)
    {
        char wybor = '2';
        bool zmienna1 = false;
        bool zmienna2 = false;
        while (wybor)
        {
            if (zmienna2 == true)
            {
                liczba_produktow_epp = 0;
                liczba_produktow_eps = 0;
                break;
            }

            system("clear");

            linia();
            cout << "|                                         Edytuj  produkt                                         |" << endl;
            linia();

            cout << " Pomyslnie edytowano dane produktu." << endl;
            linia();

            cout << " 0. Cofnij." << endl;
            linia();

            if (zmienna1 == true)
            {
                cout << " Nie ma takiej opcji!" << endl;
                linia();
            }
            zmienna1 = false;

            cout << " Twoj wybor: ";
            cin >> wybor;
            linia();

            switch (wybor)
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

void wczytaj_produkt_eps()
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
        tablica_produktow_eps[liczba_produktow_eps].set(cena, kod, ilosc, nazwa, data, rozmiar);
        liczba_produktow_eps++;

        while(plik >> nazwa >> rozmiar >> data >> cena >> kod >> ilosc)
        {
            tablica_produktow_eps[liczba_produktow_eps].set(cena, kod, ilosc, nazwa, data, rozmiar);
            liczba_produktow_eps++;

            if(liczba_produktow_eps + 1 == MAX)
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

void wczytaj_produkt_epp()
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
        tablica_produktow_epp[liczba_produktow_epp].set(cena, kod, ilosc, nazwa, marka, kolor);
        liczba_produktow_epp++;

        while(plik >> nazwa >> marka >> kolor >> cena >> kod >> ilosc)
        {
            tablica_produktow_epp[liczba_produktow_epp].set(cena, kod, ilosc, nazwa, marka, kolor);
            liczba_produktow_epp++;

            if(liczba_produktow_epp + 1 == MAX)
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

void zapisz_do_pliku()
{
    ofstream plik1("dane/produkty/spozywcze.txt", ios::out);
    if (!plik1)
    {
        cerr << " Blad otwarcia pliku!" << endl;
        exit(EXIT_FAILURE);
    }

    for(int a = 0; a < liczba_produktow_eps; a++)
    {
        plik1 << tablica_produktow_eps[a].getNazwa() << " " << tablica_produktow_eps[a].getRozmiar() << " " 
            << tablica_produktow_eps[a].getData_waznosci() << " " << tablica_produktow_eps[a].getCena() << " "
            << tablica_produktow_eps[a].getKod() << " " << tablica_produktow_eps[a].getIlosc() << endl;
    }

    ofstream plik2("dane/produkty/przemyslowe.txt", ios::out);
    if (!plik2)
    {
        cerr << " Blad otwarcia pliku!" << endl;
        exit(EXIT_FAILURE);
    }

    for(int a = 0; a < liczba_produktow_epp; a++)
    {
        plik2 << tablica_produktow_epp[a].getNazwa() << " " << tablica_produktow_epp[a].getMarka() << " " 
            << tablica_produktow_epp[a].getKolor() << " " << tablica_produktow_epp[a].getCena() << " "
            << tablica_produktow_epp[a].getKod() << " " << tablica_produktow_epp[a].getIlosc() << endl;
    }
}