/*
 * Slownik.cpp
 *
 *  Created on: 13 gru 2014
 *      Author: xmef
 */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm> // std::find_if
#include <string.h>
#include <map>
using namespace std;
//******************************************************************************************************
// słownik jest kolekcją par wartości
// w innych kontekstach słownik jest znany jako tablica asocjacyjna lub odwzorowanie
// map<key, value>
map<string, int> ksiazka_tel_map;
// w tym przypadku klucz = string (imie, nazwisko), wartość = int (numer telefonu)
//******************************************************************************************************
void drukuj_pozycje_map(const string& s)
{
	if(int i = ksiazka_tel_map[s]) cout << s << ' ' << i << endl;
	// jeśli jako indeks poda się wartość pierwszego typu (klucz) to słownik przekaże (zwróci) odpowiadającą mu wartość drugiego typu (value)
	// jeśli nie znajdzie pozycji z kluczem s to z książki telefonicznej uzyska się wartość domyślną (typu odwzorowanego(value))
	// dla typu int wartość domyślna to 0 (zakładamy, że to niepoprawny nr telefonu)
}
//******************************************************************************************************
// poniższa funkcja jest predykatem
// Predykat jest wywoływany dla każdego elementu i przekazuje wartość logiczną, która służy w algorytmie do wykonania zamierzonego zadania.
// funkcja find_if() umożliwia szukanie do chwili, gdy predykat przekaże wartość true, informując o znalezieniu pożądanego elementu.
// funkcja count_if() umożliwia zliczanie, ile razy predykat ma wartość true.
bool wieksze_niz_42(const pair<const string, int>& r)
{
	return r.second > 42;
}
//******************************************************************************************************
void f(map<string, int>& m)
{
	typedef map<string, int>::const_iterator MI;
	MI i = find_if(m.begin(), m.end(), wieksze_niz_42);
	int c42 = count_if(m.begin(), m.end(), wieksze_niz_42);
}
//******************************************************************************************************
//******************************************************************************************************
//******************************************************************************************************
//******************************************************************************************************
