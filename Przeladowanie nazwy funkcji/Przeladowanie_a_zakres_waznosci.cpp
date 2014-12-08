/*
 * Przeladowanie_a_zakres_waznosci.cpp
 *
 *  Created on: 8 gru 2014
 *      Author: xmef
 */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
//******************************************************************************************************
extern void dzwiek(int a);
//******************************************************************************************************
void Przeladowanie_a_zakres_waznosci()
{
	dzwiek(1);
	{
		// w tym miejscu nie dochodzi do przeładowania, a do zasłonięcia nazwy
		extern void dzwiek(double);
		dzwiek(2);
		dzwiek(3.14);
	}
	dzwiek(5);
	dzwiek(6.28);
	{
		void fun(int m[2][4]);
		void fun(int m[2][3]);
	}
}
//******************************************************************************************************
// Aby rzeczywiście mieć obie funkcje o tej samej nazwie (przeładowane) muszą one mieć identyczny zakres ważności.
/*
 * Nie można przeładować funkcji używając instrukcji typedef
 * typedef int calkow;
 * void fun(int);
 * void fun(calkow);
 * są to dwie te same funkcje, z taką samą listą argumentów
 * (typ enum, chociaż jest całkowity, jest różny od int i można z nim przeładować funkcję)
 *
 * ------------------------------------------------------------------------------------------------------------
 *
 * Tablica oraz wskaźnik uznawane są za identyczne typy argumentów (inne jest tylko oznaczenie).
 * Nie można ich przeładowywać.
 * Tablice wielowymiarowe o różnych długościach np. [2][3] i [2][4] są rozróżniane jako inne typy.
 * Wymiar najbardziej z lewej może być ten sam, ponieważ nie bierze udziału w obliczaniu położenia danego elementu w pamięci.
 *
 * ------------------------------------------------------------------------------------------------------------
 *
 * Referencja oraz wartość nie są rozróżnialnymi typami w argumencie formalnym funkcji.
 * void fun(int k); i void(int &m); nie można w ten sposób przeładować
 *
 * Podobnie jest z przydomkami const i volatile
 * typy z tymi przydomkami uznawane są przez identyczne (mające ten sam inicjalizator) i przez co nie można ich przeładowywać
 *
 * ------------------------------------------------------------------------------------------------------------
 *
 * Inaczej jest ze wskaźnikami do typów z przydomkiem const i volatile.
 * Ponieważ dla dowolnego typu T następujące deklaracje argumentów formalnych:
 * 			T *
 * const 	T *
 * volatile T *
 * wymagają każda odmiennego inicjalizatora (odmiennego argumentu wywołania).
 *
 * ------------------------------------------------------------------------------------------------------------
 *
 * Podobnie z referencjami obiektów z przydomkiem const i volatile.
 * 			T &
 * const 	T &
 * volatile T &
 * wymagają każda odmiennego inicjalizatora.
 * Poprawne przeładowanie: void f(int &m); void f(const int &m); void f(volatile int &m);
 *
 */
