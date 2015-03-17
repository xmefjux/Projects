/*
 * numer.h
 *
 *  Created on: 17 mar 2015
 *      Author: xmef
 */

#ifndef NUMER_H_
#define NUMER_H_

#include <cstring>
#include <iostream>
using namespace std;

// przykładowa klasa z użyciem konstruktora
// konstruktor jest to funkcja składowa klasy, która nie ma żadnego typu zwracanego i taką samą nazwę jak klasa
// jest ona wywoływana zawsze, automatycznie, tylko raz, w momencie powołania obiektu do życia, nadaje mu wartość początkową

class numer {
	// jeżeli nie ma podane inaczej, dane są private
	int liczba;
	char nazwa[40];
public:
	// funkcje składowe
	// konstruktor - tylko deklaracja
	numer(int k, const char* opis);
	//virtual ~numer();

	void schowaj(int m)
	{
		liczba = m;
		melduj();
	}
	int zwracaj() { return liczba; }

	void melduj()
	{
		cout << nazwa << liczba << endl;
	}
};

#endif /* NUMER_H_ */
