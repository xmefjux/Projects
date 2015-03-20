/*
 * Modulzegarowy.cpp
 *
 *  Created on: 20 mar 2015
 *      Author: xmef
 */

#include "Modulzegarowy.h"

Modul_zegarowy::Modul_zegarowy(const char* opis, int niedokl) {
	// TODO Auto-generated constructor stub
	strcpy(nazwa, (opis ? opis : "Bez opisu"));
	co_ile_przyspiesza = niedokl;
	moj_biezacy_czas = 0;
}

Modul_zegarowy::~Modul_zegarowy() {
	// TODO Auto-generated destructor stub
}

void Modul_zegarowy::mija_milisekunda() const
{
	moj_biezacy_czas++;
	if(!(moj_biezacy_czas % co_ile_przyspiesza))
	{
		moj_biezacy_czas++;
	}
}

void Modul_zegarowy::synchronizuj_sie_z(const Modul_zegarowy* wsk_z_kim)
{
	long czas_odniesienia = wsk_z_kim->podaj_milisekundy();
	if(moj_biezacy_czas != czas_odniesienia)
	{
		cout << nazwa <<": Korekta w "
			 << (czas_odniesienia / 1000)
			 << " sek. ("
			 << czas_odniesienia - moj_biezacy_czas
			 << " ms)" << endl;

		// właściwa synchronizacja
		moj_biezacy_czas = czas_odniesienia;
	}
	Modul_zegarowy::f();
}
