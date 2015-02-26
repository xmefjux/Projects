/*
 * drugi.cpp
 *
 *  Created on: 24 lut 2015
 *      Author: xmef
 */
#include <iostream>
using namespace std;

#include "bilet.h"
//*****************************************************************************************
void funkcja_w_innym_pliku()
{
	cout << "\nJestesmy w innym pliku programu, \ntu tez uzywamy biletow\n";
	bilet bialy;
	bialy.zapamietaj("Krakow", "Tarnow", bilet::osobowy);
	bialy.wypisz();

	cout << "Spieszy nam sie, zmieniamy bilet na taki: " << endl;
	bialy.zmien_rodzaj_pociagu(bilet::pospieszny);
	bialy.wypisz();
}
//*****************************************************************************************
