/*
 * pion_main.cpp
 *
 *  Created on: 17 mar 2015
 *      Author: xmef
 */
#include "includy.h"

#include "pion.h"

// składnik statyczny może pojawiać się jako argument domniemany jakiejś funkcji składowej tej klasy. Składnik nie-statyczny nie mógłby
// Klasy które są definiowane lokalnie (czyli np w obrębie jednej funkcji) - nie mogą mieć danych statycznych

void pion_main()
{
	cout << "Poczatek programu, teraz jest pionkow = " << pion::ile_pionkow;

	pion czerwony;
	pion zielony;

	cout << "\nPo definicji pionkow\n";

	// odczytywanie informacji zapisanych w danej statycznej (public)

	cout << "Klasa mowi ze pionkow jest " << pion::ile_pionkow << endl;
	cout << "czerwony, ze " << czerwony.ile_pionkow << endl;
	cout << "zielony, ze " << zielony.ile_pionkow << endl;

	pion bialy;

	cout << "po definicji jeszcze jednego jest ich: "
		 << zielony.ile_pionkow << endl;

	//pionki ida do przodu
	zielony.przesun(2);
	czerwony.przesun(6);
	bialy.przesun(3);

	//interesuje nas ile zarabia pionek (dana statyczna prywatna)

	/* cout << "pionek zarabia " << pion::pensja; */ // błąd!

	// jedyna szansa to zapytać pionka funkcją składową
	cout << "Czerwony, ile zarabiacie? " << czerwony.ile_zarabia();
	cout << "\nBialy, ile zarabiacie? " << bialy.ile_zarabia();
}
