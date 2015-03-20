/*
 * gadula.cpp
 *
 *  Created on: 17 mar 2015
 *      Author: xmef
 */

#include "gadula.h"

int licz;

void fff(int, int, int) { cout << "funkcja glob\n"; }

gadula::gadula(int k, const char* opis) {
	// TODO Auto-generated constructor stub
	strcpy(tekst, (opis ? opis :""));
	licz = k;
	cout << "Konstruuje obiekt " << tekst << endl;
	gadula::fff(1);
	::fff(1, 2, 3);
	gadula::fff(1, 2);
	//fff(1, 2, 3); // domyślnie przed tym stoi gadula::
	// dlatego zalecane jest by zawsze to pisać, bo może to być mylące
}

gadula::~gadula() {
	// TODO Auto-generated destructor stub
	cout << "Pracuje destruktor (sprzata)" << tekst << endl;
}

void gadula::fff(int a) { cout << "funkcja klasy 1\n"; }

void gadula::fff(int a, int b) { cout << "funkcja klasy 2\n"; }

