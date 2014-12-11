/*
 * Przyklad_1.cpp
 *
 *  Created on: 8 gru 2014
 *      Author: xmef
 */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
extern "C" {
#include "x.h"
}
using namespace std;
//******************************************************************************************************
void wypisz(int liczba);
void wypisz(char znak1, double x, const char *tekst);
void wypisz(int liczba, char znak);
void wypisz(char znak, int liczba); // różna kolejność argumentów także odróżnia dwie funkcje
//******************************************************************************************************
void Przyklad_1()
{
	wypisz(12345);
	wypisz(8, 'X');
	wypisz('D', 89.5, " stopni Celsiusza ");
	wypisz('M', 22);
}
//******************************************************************************************************
void wypisz(int liczba)
{
	cout << "Liczba typu int: " << liczba << endl;
}
//******************************************************************************************************
void wypisz(char znak1, double x, const char *tekst)
{
	cout << "Blok " << znak1 << ": " << x << tekst << endl;
}
//******************************************************************************************************
void wypisz(int liczba, char znak)
{
	cout << znak << ") " << liczba << endl;
}
//******************************************************************************************************
void wypisz(char znak, int liczba)
{
	cout << liczba << " razy wystapil stan " << znak << endl;
}
//******************************************************************************************************
/*
 *	void dru(int);
 *	void dru(double);
 *	void dru(int, int);
 *	void dru(int, double);
 *	wywołanie: dru(5, (int) 62.34); wywoła funkcję dru(int, int); przez rzutowanie drugiego argumentu na int
 *
 *	void zz(int);
 *	void zz(unsigned int);
 *	jest to poprawne przeładowanie, ponieważ int i unsigned int są różnymi typami
 *
 *	jeśli potrzebna jest funkcja o tym samym zestawie argumentów, zmiana ich kolejności może załatwić przeładowanie (lub dodanie jakiegoś argumentu)
 *
 *	----------------------------------------------------------------------------------------------------
 *
 *	Przeładowanie w przypadku argumentów domniemanych
 *
 *	void fun(double);
 *	void fun(const char*);
 *	void fun(int, double = 0);
 *
 *	tutaj nie może się pojawić deklaracja void fun(int); ponieważ funkcja z argumentem domniemanym, ma 'zakamuflowaną' taką deklarację
 *	void fun(int, double = 0); odpowiada dwóm deklaracjom: void fun(int); i void fun(int, double);
 *	definicja z n argumentami domniemanymi odpowiada n + 1 deklaracjom funkcji
 *
 *	-----------------------------------------------------------------------------------------------------
 *
 *	Kompilator realizuje przeładowanie w ten sposób, że zamienia nazwy przeładowanej funkcji na inne nazwy funkcji
 *	np. void akcja(); --> akcja__Fv, void akcja(int, double); --> akcja__Fid (Function, void, int, double)
 *	stąd też wiadomo dlaczego przeładowanie nie może różnić się tylko typem zwracanym, nie jest on doczepiany do zamienianej nazwy
 *	Czyli w rzeczywistości przeładowanie dla kompilatora to różne funkcje o różnych nazwach.
 *
 *	-----------------------------------------------------------------------------------------------------
 *
 *	Linkowanie z modułami z innych języków
 *	Kompilator c++ zamienia nazwy funkcji na inne (swoje) i przez to, deklaracje z innych języków są zamieniane i mogą nie działać.
 *	Aby uniknąć tego problemu należy deklarację z innego języka napisać w taki sposób:
 *	extern "C" void mapa(int, double);
 *	"C" nie mówi, że to musi być koniecznie klasyczny C, mówi, że nie jest to według konwencji C++
 *	Większą liczbę deklaracji takich funkcji można umieścić w bloku
 *	extern "C"
 *	{
 *		int		pierwsza(int);
 *		void	druga(double, char*, int);
 *		// ...
 *	}
 *	W takim bloku może być zawarta nawet dyrektywa include *	-----------------------------------------------------------------------------------------------------
 *
 *	extern "C"
 *	{
 *		#include "moje_deklar.h"
 *	}
 *
 *
 */
