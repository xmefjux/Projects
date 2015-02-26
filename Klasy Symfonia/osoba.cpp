/*
 * osoba.cpp
 *
 *  Created on: 24 lut 2015
 *      Author: xmef
 */
#include "osoba.h"
#include <cstring>
//*****************************************************************************************
extern void zapis_osoby_na_wakacje(const osoba *jej_adres);
//*****************************************************************************************
void osoba::zapamietaj(const char *napis, int lata)
{
	strcpy(this->nazwisko, (napis ? napis : "Anonim"));
	this->wiek = lata;
}
//*****************************************************************************************
void osoba::moje_wakacje()
{
	zapis_osoby_na_wakacje(this);
	// funkcja składowa moje_wakacje zostanie wywołana dla jakiegoś obiektu, this zwróci adres tego obiektu
	// przydomek const jest dla bezpieczeństwa, by nie robić zmian na tym adresie
}
//*****************************************************************************************
