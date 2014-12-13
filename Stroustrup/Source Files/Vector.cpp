/*
 * Kolekcje.cpp
 *
 *  Created on: 13 gru 2014
 *      Author: xmef
 */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
using namespace std;
//******************************************************************************************************
struct Pozycja {
	string nazwisko;
	int numer;
};
Pozycja ksiazka_tel_tab[1000]; // lista z użyciem tablicy (tablica jako lista)
vector<Pozycja> ksiazka_tel_vector(1000); // 1000 to inicjalny rozmiar
// vector nie kontroluje zgodności zakresu
// z tego powodu powstała pochodna klasa Vec, która kontroluje zakres
//******************************************************************************************************
void Vector()
{

}
//******************************************************************************************************
void drukuj_pozycje_t(int i) // proste użycie
{
	cout << ksiazka_tel_tab[i].nazwisko << ' ' << ksiazka_tel_tab[i].numer << endl;
}
//******************************************************************************************************
void drukuj_pozycje_v(int i) // proste użycie, dokładnie tak samo jak dla tablicy
{
	cout << ksiazka_tel_vector[i].nazwisko << ' ' << ksiazka_tel_vector[i].numer << endl;
}
//******************************************************************************************************
void dodaj_pozycje_v(int n) // zwiększ rozmiar o n
{
	ksiazka_tel_vector.resize(ksiazka_tel_vector.size() + n);
}
//******************************************************************************************************
void f(vector<Pozycja>& v)
{
	vector<Pozycja> v2 = ksiazka_tel_vector; // czyli v2 jest wektorem z tysiącem elementów i są kopiowane elementy
	v = v2; // to przypisanie powoduje skopiowanie elementów danego wektora do drugiego
}
//******************************************************************************************************
//******************************************************************************************************
