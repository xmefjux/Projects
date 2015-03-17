/*
 * gadula.cpp
 *
 *  Created on: 17 mar 2015
 *      Author: xmef
 */

#include "gadula.h"

gadula::gadula(int k, const char* opis) {
	// TODO Auto-generated constructor stub
	strcpy(tekst, (opis ? opis :""));
	licz = k;
	cout << "Konstruuje obiekt " << tekst << endl;
}

gadula::~gadula() {
	// TODO Auto-generated destructor stub
	cout << "Pracuje destruktor (sprzata)" << tekst << endl;
}
