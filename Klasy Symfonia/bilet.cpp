/*
 * bilet.cpp
 *
 *  Created on: 24 lut 2015
 *      Author: xmef
 */
#include "bilet.h"
#include "includy.h"
//*****************************************************************************************
void bilet::zapamietaj(const char* sk, const char* dok, rodzaj_pociagu poc, int kl)
{
	strcpy(this->skad, (sk ? sk : "Brak danych"));
	strcpy(this->dokad, (dok ? dok : "Brak danych"));
	this->jaki_pociag = poc;
	this->klasa = kl;
}
//*****************************************************************************************
void bilet::wypisz()
{
	char kreska[] = "[---------------------------------]\n";
	char brzegi[] = "[                           ]\r[";

	cout << kreska << brzegi
		 << " Bilet: " << this->skad << " --> " << this->dokad
		 << ", klasa " << this->klasa << endl
		 << brzegi
		 << "    na pociag " << this->opis_rodzaju() << endl << kreska;
}
//*****************************************************************************************
const char* bilet::opis_rodzaju()
{

	const char* nazwy[] = {
			"osobowy (lub regionalny)",
			"przyspieszony (lekko)",
			"pospieszny",
			"InterCity ekspres"
	};
	return nazwy[this->jaki_pociag];
}
//*****************************************************************************************
//*****************************************************************************************
//*****************************************************************************************
//*****************************************************************************************
//*****************************************************************************************
