/*
 * File.cpp
 *
 *  Created on: 13 gru 2014
 *      Author: xmef
 */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <list>
#include <complex>
#include <algorithm>
using namespace std;
//******************************************************************************************************
/*template <class C, class T> int count (const C& v, T val)
{
	typename C::const_iterator i = find(v.begin(), v.end(), val);
	int n = 0;
	while(i != v.end()){
		++n;
		++i;
		i = find(i, v.end(), val);
	}
	return n;
}*/
//******************************************************************************************************
/*
 * Często mamy do czynienia z kolekcjami wskaźników i chcielibyśmy wywołać metodę wskazywanego obiektu, a nie funkcję globalną.
 * Załóżmy, że chcemy wywołać metodę Figura::rysuj() dla każdego elementu list<Figura*>.
 * void rysuj(Figura* p)
 * {
 * 		p->rysuj();
 * }
 * void f(list<Figura*>& fg)
 * {
 * 		for_each(fg.begin(), fg.end(), rysuj); // for each wywołuje metodę rysuj() dla każdego elementu z zakresu fg.begin()-fg.end()
 * }
 * Uogólniając, możemy napisać:
 * void g(list<Figura*>& fg)
 * {
 * 		for_each(fg.begin(), fg.end(), mem_fun(&Figura::rysuj));
 * }
 * Wzorzecz mem_fun z biblioteki standardowej otrzymuje jako argument wskaźnik do metody i tworzy coś, co można wywołać dla
 * wskaźnika obiektu klasy, z której pochodzi ta metoda. Wynik wywołania mem_fun(&Figura::rysuj) otrzymuje argument Figura*
 * i przekazuje to, co otrzyma od Figura::rysuj().
 * Mechanizm mem_fun() jest ważny, gdyż pozwala na stosowanie standardowych algorytmów dla kolekcji obiektów polimorficznych.
 */
//******************************************************************************************************
//******************************************************************************************************
//******************************************************************************************************
//******************************************************************************************************
//******************************************************************************************************
//******************************************************************************************************
//******************************************************************************************************
