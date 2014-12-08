/*
 * Wysylanie_do_funkcji_adresu_innej_przeladowanej_funkcji.cpp
 *
 *  Created on: 8 gru 2014
 *      Author: xmef
 */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
//******************deklaracje funkcji o przeładowanej nazwie*******************************************
void przelad(int k);
void przelad(double x);
//******************deklaracje zwykłych funkcji*********************************************************
void pierwsza(void (*adrfun)(int));
void druga(void (*adrfun)(double));
//******************************************************************************************************
void (*zwrot(void))(int);
void Wysylanie_do_funkcji_adresu_innej_przeladowanej_funkcji()
{
	pierwsza(przelad);
	cout << "----------------------" << endl;
	druga(przelad);
	pierwsza(zwrot());
}
//******************************************************************************************************
void pierwsza(void (*adrfun)(int))
{
	cout << "Jestem wewnatrz funkcji PIERWSZA" << endl
		 << "teraz wywolam funkcje ktorej adres przyslano mi jako argument" << endl;
	(*adrfun)(5);
	cout << "PO wywolaniu funkcji (pierwsza)" << endl;
}
//******************************************************************************************************
void druga(void (*adrfun)(double))
{
	cout << "Jestem wewnatrz funkcji DRUGA" << endl
			 << "teraz wywolam funkcje ktorej adres przyslano mi jako argument" << endl;
		(*adrfun)(3.14);
		cout << "PO wywolaniu funkcji (druga)" << endl;
}
//******************************************************************************************************
void przelad(int k)
{
	cout << "**** Funkcja przelad - wersja: przelad(int)" << endl
		 << "argument k = " << k << endl;
}
//******************************************************************************************************
void przelad(double x)
{
	cout << "**** Funkcja przelad - wersja: przelad(double)" << endl
			 << "argument x = " << x << endl;
}
//******************************************************************************************************
/*
 * Przy wysyłaniu adresu przeładowanej funkcji kompilator wie o jaką funckcję chodzi, dzięki deklaracji wskaźnika do tej funkcji.
 */
//Zwracanie adresu przeładowanej funkcji
/*
 * Aby móc zwrócić adres funkcji void przelad(int) inną funkcją potrzebna jest funkcja zwracająca wskaźnik do takiej funkcji.
 * Nazwijmy ją zwrot. Ma ona zwracać wskaźnik do funkcji void f(int).
 *
 * zwrot jest funkcją wywoływaną bez żadnych argumentów
 * zwrot(void)
 * a która zwraca wskaźnik
 * *zwrot(void)
 * do funkcji
 * (*zwrot(void)) (...)
 * wywoływanej z argumentem typu int
 * (*zwrot(void))(int)
 *
 * Ciekawe jest to, że ta funkcja nie musi przyjąć jako argument funkcji, której adres ma zwrócić.
 *
 */
void (*zwrot(void))(int)
{
	cout << "zwracam wskaznik do funkcji!" << endl;
	return (&przelad);
}

