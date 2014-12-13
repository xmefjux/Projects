/*
 * Lista.cpp
 *
 *  Created on: 13 gru 2014
 *      Author: xmef
 */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <list>
using namespace std;
//******************************************************************************************************
struct Pozycja {
	string nazwisko;
	int numer;
};
list<Pozycja> ksiazka_tel_list;
// za pomocą indeksu nie będziemy sięgać do elementów listy, tak jak w przyadku vector
// bedziemy natomiast przeglądać listę w poszukiwaniu elementu z podaną wartością
// Skorzystamy z faktu, że lista jest ciągiem.
//******************************************************************************************************
void Lista()
{

}
//******************************************************************************************************
/*
 * Poszukiwanie elementu s rozpoczyna się od początku listy i trwa aż do znalezienia s lub osiągnięca końca listy.
 * Każda kolekcja z biblioteki standardowej zawiera funkcje begin() i end(), które przekazują iterator odpowiednio
 * do pierwszego elementu listy  i pierwszego za ostatnim.
 * Jeśli nie musimy modyfikować elementu kolekcji to typem, którego potrzebujemy jest const_iterator.
 * W przeciwnym razie używamy zwykłego typu iterator.
 */
void drukuj_pozycje(const string& s)
{
	typedef list<Pozycja> ::const_iterator LI;
	for(LI i = ksiazka_tel_list.begin(); i != ksiazka_tel_list.end(); i++)
	{
		const Pozycja& p = *i; // dla uproszczenia używamy referencji
		if(s == p.nazwisko)
		{
			cout << p.nazwisko << ' '	<< p.numer << endl;
			return;
		}
	}
}
//******************************************************************************************************
void dodaj_pozycje(Pozycja& p, list<Pozycja>::iterator i)
{
	ksiazka_tel_list.push_front(p); // dodaj na początek
	ksiazka_tel_list.push_back(p); // dodaj na koniec
	ksiazka_tel_list.insert(i, p); // dodaj przed elementem wskazywanym przez i
}
//******************************************************************************************************
//******************************************************************************************************
//******************************************************************************************************
//******************************************************************************************************
//******************************************************************************************************
