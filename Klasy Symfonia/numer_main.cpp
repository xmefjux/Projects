/*
 * numer_main.cpp
 *
 *  Created on: 17 mar 2015
 *      Author: xmef
 */
#include "includy.h"

#include "numer.h"

void numer_main()
{
	numer	samolot(1200, "Biezaca wysokosc ");
	numer	atmosfera(920, "Cisnienie atmosferyczne ");
	numer	kurs(63, "Kierunek lotu ");

	// wstępny raport
	samolot.melduj();
	kurs.melduj();
	atmosfera.melduj();

	cout << "\nKorekta lotu -----------------------------\n";
	samolot.schowaj(1201);
	// zmiana kursu o 3 stopnie
	kurs.schowaj(kurs.zwracaj() + 3);
	// ciśnienie spada
	atmosfera.schowaj(919);
}
