/*
 * osoba.h
 *
 *  Created on: 24 lut 2015
 *      Author: xmef
 */

#ifndef OSOBA_H_
#define OSOBA_H_
//*****************************************************************************************
#include "includy.h"
//*****************************************************************************************
// definicja klasy
class osoba
{
	char nazwisko[80];
	int wiek;
public:
	void zapamietaj(const char *napis, int lata);
	void wypisz()
	{
		cout << "\t" << this->nazwisko << ", lat: " << this->wiek << endl; // this nie jest tu potrzebne, ale żeby wiedzieć, że tam jest
	}
	void moje_wakacje();
	int globalna;
	void fun(){}
};
//*****************************************************************************************
#endif /* OSOBA_H_ */
