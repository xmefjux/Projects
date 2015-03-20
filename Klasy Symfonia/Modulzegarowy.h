/*
 * Modulzegarowy.h
 *
 *  Created on: 20 mar 2015
 *      Author: xmef
 */

#ifndef MODULZEGAROWY_H_
#define MODULZEGAROWY_H_

#include "includy.h"

// przykład klasy z przydomkiem mutable - zmienialny
// jeśli mamy funkcję składową const to można ją wywoływać tylko na rzecz obiektów const i nie ma prawa ona modyfikować ich składników
// natomiast jeśli do składnika klasy dopiszemy przydomek mutable to będzie on mógł być modyfikowany w obiekcie const z funkcji const

class Modul_zegarowy {
private:
	mutable long moj_biezacy_czas;

	char nazwa[100];
	int co_ile_przyspiesza;
	void f() { cout << "Wywolalem funkcje prywatna!\n"; }
public:
	Modul_zegarowy(const char* opis, int niedokl);
	~Modul_zegarowy();


	long podaj_milisekundy() const { return moj_biezacy_czas; }
	long podaj_sekundy() const { return moj_biezacy_czas / 1000; }
	void drukuj_czas() { cout << nazwa << ": " << moj_biezacy_czas / 1000 << "s "; }
	void wyzeruj_czas() { moj_biezacy_czas = 0; }

	void mija_milisekunda() const;
	void synchronizuj_sie_z(const Modul_zegarowy* wsk_z_kim);
};

#endif /* MODULZEGAROWY_H_ */
