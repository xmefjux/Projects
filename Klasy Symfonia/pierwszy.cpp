/*
 * pierwszy.cpp
 *
 *  Created on: 24 lut 2015
 *      Author: xmef
 */
#include "includy.h"

#include "osoba.h"
#include "bilet.h"
//*****************************************************************************************
void prezentacja(osoba &ktos);
extern void funkcja_w_innym_pliku();
//*****************************************************************************************
void pierwszy()
{
	osoba kompozytor;
	osoba autor;

	kompozytor.zapamietaj("Fryderyk Chopin", 36);
	autor.zapamietaj("Marcel Proust", 34);

	// wywołujemy funkcję, wysyłając obiekty
	prezentacja(kompozytor);
	prezentacja(autor);

	cout << endl << "Uzywamy w tym pliku tez klasy bilet" << endl;

	bilet zolty;
	bilet niebieski;

	zolty.zapamietaj("Frankfurt", "Paris", bilet::ekspres, 1);
	zolty.wypisz();

	niebieski.zapamietaj("Zurich", "Genewa", bilet::ekspres, 1);
	niebieski.wypisz();

	niebieski.zmien_rodzaj_pociagu(bilet::pospieszny);
	cout << endl << "Po zmianie tego biletu..." << endl;
	niebieski.wypisz();

	funkcja_w_innym_pliku();
}
//*****************************************************************************************
void prezentacja(osoba &ktos)
{
	cout << "Mam zaszczyt przedstawic panstwu, \nOto we wlasnej osobie: ";
	ktos.wypisz();
}
