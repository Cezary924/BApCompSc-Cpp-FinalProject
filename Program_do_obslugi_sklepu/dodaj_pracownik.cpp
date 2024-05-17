#include "main.h"
#include "pracownik.h"

void dodaj_pracownik()
{
    string stanowisko, imie, nazwisko;
    double pensja;
    
    system("clear");
    
    linia();
    cout << "|                                        Dodaj  pracownika                                        |" << endl;
    linia();

    cout << " Wprowadz stanowisko: ";
    cin >> stanowisko;
    cout << " Wprowadz imie: ";
    cin >> imie;
    cout << " Wprowadz nazwisko: ";
    cin >> nazwisko;
    try
    {
        cout << " Wprowadz pensje: ";
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
    
    Pracownik pomocniczy(imie, nazwisko, stanowisko, pensja);

    ofstream plik("dane/pracownicy.txt", ios::app);
    if (!plik)
    {
        cerr << " Blad otwarcia pliku!" << endl;
        exit(EXIT_FAILURE);
    }

    plik << pomocniczy.getImie() << " " << pomocniczy.getNazwisko() << " " 
        << pomocniczy.getStanowisko() << " " << pomocniczy.getPensja() << endl;

    char wybor = '2';
    bool zmienna1 = false;
    bool zmienna2 = false;

    while(wybor)
    {
        if(zmienna2 == true)
        {
            break;
        }
        
        system("clear");
        
        linia();
        cout << "|                                        Dodaj  pracownika                                        |" << endl;
        linia();
        
        cout << " Pomyslnie dodano nowego pracownika." << endl;
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