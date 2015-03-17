/*
 * numer.cpp
 *
 *  Created on: 17 mar 2015
 *      Author: xmef
 */

#include "numer.h"

numer::numer(int k, const char* opis) {
	// TODO Auto-generated constructor stub
	liczba = k;
	strcpy(nazwa, (opis ? opis : ""));
}

/*numer::~numer() {
	// TODO Auto-generated destructor stub
}*/

