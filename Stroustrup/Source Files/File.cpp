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
template <class C, class T> int count (const C& v, T val)
{
	typename C::const_iterator i = find(v.begin(), v.end(), val);
	int n = 0;
	while(i != v.end()){
		++n;
		++i;
		i = find(i, v.end(), val);
	}
	return n;
}
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
// ćw. [2] napisz deklaracje do definicji i definicje do deklaracji
/*char ch; // char ch = 0;
string s; // string s = 0;
int licznik = 1; // int licznik;
const double pi = 3.1414926535897932385; // do const musi być definicja, bo trzeba przypisać w momencie deklaracji i tylko wtedy
extern int numer_bledu; // w innym pliku int numer_bledu = 0;

char* imie = "Njal"; // char* imie; - nie jest zbyt rozsądne nie nadawać wskaźnikowi wartości w momencie deklaracji
char* sezon[] = { "wiosna", "lato", "jesien", "zima" }; // char* sezon[];

struct Data { int d, m, r; }; // Struct Data;
int dzien(Data *p) { return p->d; } // int dzien(Data *p);
double sqrt(double); // double sqrt(double x) { return 0.0 }
template<class T> T abs(T a) { return a<0 ? -a : a;	} // template<class T> T abs(T);

struct Uzytkownik; // struct Uzytkownik { };
typedef complex<short> Punkt;
enum piwo { Carlsberg, Tuborg, Thor };
namespace NS { int a; }*/
//******************************************************************************************************
//******************************************************************************************************
//******************************************************************************************************
//******************************************************************************************************
