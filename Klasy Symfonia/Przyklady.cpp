/*
 * Przyklady.cpp
 *
 *  Created on: 20 lut 2015
 *      Author: xmef
 */
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cstring>
#include "osoba.h"

using namespace std;

// dane w klasie są w kolejności public, protected, private
// protected - dostęp ma klasa oraz klasy, które dziedziczą
// private dostęp mają tylko funkcje składowe klasy
// żadnych danych składowych klasy się nie inicjalizuje, nigdy
// jeśli nie ma wyszczególnione czy public itd to składniki będą private
// definicja funkcji składowej klasy może znajdować się wewnątrz klasy, ale wtedy będzie traktowana jako inline
// składnia funkcji składowej poza klasą typ zwracany nazwa_klasy::nazwa_funkcji() { }
// this - to jest "wskaźnik", który pokazuje na konkretny składnik obiektu danej klasy, dla którego daną funkcję wywołaliśmy
// this - podany jako argument funkcji, zwróci adres obiektu, który wywołał funkcje składową

// nazwa zasłania inną nazwę, niezależnie czy to jest to nazwa funkcji czy zmiennej

// jedna definicja klasy - jeden plik. Każda klasa umieszczona w osobnym pliku
// definicję klasy umieszcza się w osobnym pliku nagłówkowym
// definicje funkcji składowych klasy nie mogą znajdować się w pliku nagłówkowym razem z definicją klasy
// klasa tak naprawdę składa się z dwóch plików: nagłówkowego z definicją klasy i źródłowego z definicjami funkcji składowych


int globalna;

class pralka
{
public:
	void pierz(int program); // funkcje składowe
	void wiruj(int minuty);

	int		nr_programu;		// składniki klasy / dane składowe
	double	temperatura_prania;
	char	nazwa[80];

	int krochmalenie(void);
};



/*osoba student1;
osoba student2;
osoba profesor;
osoba pilot;*/

void zapis_osoby_na_wakacje(const osoba *jej_adres) {}

void Przyklady()
{
	pralka obiekt;
	obiekt.nr_programu = 1;
	pralka *wsk_pralka;
	wsk_pralka -> temperatura_prania;

	pralka czerwona;
	pralka *wskaz;
	pralka &ruda = czerwona;
	//odniesiemy do składników klasy się na 3 sposoby
	czerwona.temperatura_prania = 60;

	wskaz = &czerwona;
	wskaz -> temperatura_prania = 60;

	ruda.temperatura_prania = 60;

	// przykładowy program z użyciem klasy osoba
	osoba student1;
	osoba student2;
	osoba profesor;
	osoba pilot;

	cout << "Dla informacji podaje, ze jeden obiekt klasy osoba" << endl
		 << "ma rozmiar: " << sizeof(osoba) << " bajtow. To samo inaczej: "
		 << sizeof(student1) << " rozmiar obiektu student1" << endl;

	profesor.zapamietaj("Albert Einstein", 55);
	student1.zapamietaj("Ruediger Schubart", 26);
	student2.zapamietaj("Claudia Bach", 25);
	pilot.zapamietaj("Neil Armstrong", 37);

	cout << "Po wpisaniu informacji do obiektow. Sprawdzamy: " << endl
		 << "dane z obiektu profesor" << endl;
	profesor.wypisz();

	cout << "dane z obiektu student1" << endl;
	student1.wypisz();

	cout << "dane z obiektu student2" << endl;
	student2.wypisz();

	cout << "dane z obiektu pilot" << endl;
	pilot.wypisz();

	cout << "Podaj swoje nazwisko (tylko nazwisko): ";
	char magazynek[80];
	cin >> magazynek;

	cout << "Podaj swoj wiek: ";
	int ile;
	cin >> ile;
	pilot.zapamietaj(magazynek, ile);

	cout << "Oto dane ktore teraz sa zapamietane w obiektach profesor i pilot" << endl;
	profesor.wypisz();
	pilot.wypisz();

}
//*****************************************************************************************
/*void osoba::zapamietaj(const char *napis, int lata)
{
	strcpy(this->nazwisko, (napis ? napis : "Anonim"));
	this->wiek = lata;
	//zapis this-> może zostać pominięty, kompilator sa
	fun(); // wywołanie
	int fun;
	//fun(); - błąd, nazwa fun jest zasłonięta przez zmienną int i nie jest już funkcją
	osoba::fun(); // dostęp do funkcji składowej można uzyskać poprzez operatora zakresu
}*/
//*****************************************************************************************
/*void osoba::wypisz()
{
	int globalna;
	cout << this->nazwisko <<", lat: " << this->wiek	<< endl;
	::globalna = 100; // operator zakresu :: umożliwia nam dostęp do ewentualnie zasłoniętej zmiennej
	osoba::globalna = 10; // przypisanie do składnika klasy, operator zakresu daje dojście do zasłoniętej lokalnie zmiennej
	globalna = 5; // przypisanie do lokalnej zmiennej
}*/
//*****************************************************************************************

//*****************************************************************************************

//*****************************************************************************************
