#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <fstream>
#include <string>
#include <cmath>
#include <sstream>
#include <iomanip>
#include <algorithm>
using namespace std;

#define MAX 10000

void menu_glowne();
void informacja_powitalna();

void menu_klient();
void lista_produkt();
void lista_produkt_spozywcze();
void lista_produkt_przemyslowe();
void cena_produkt();
void dostepnosc_produkt();
void informacje_produkt();

void menu_sprzedawca();
void dodaj_produkt();
void dodaj_produkt_spozywcze();
void dodaj_produkt_przemyslowe();
void edytuj_produkt();
void usun_produkt();

void menu_kierownik();
void lista_pracownik();
void dodaj_pracownik();
void edytuj_pracownik();
void usun_pracownik();

void linia();

#endif