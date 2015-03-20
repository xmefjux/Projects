/*
 * modul_zegarowy_main.cpp
 *
 *  Created on: 20 mar 2015
 *      Author: xmef
 */
#include "Modulzegarowy.h"

void modul_zegarowy_main()
{
	Modul_zegarowy ggamma("GAMMA", 4000);
	Modul_zegarowy separ(" SEPAR", 5010);
	Modul_zegarowy alfap("  ALFAP", 9200);

	cout << "Sprawdzenie dokladnosci zegarow\n";
	while(true)
	{
		ggamma.mija_milisekunda();
		separ.mija_milisekunda();
		alfap.mija_milisekunda();

		// kontrolnie drukujemy na ekran co 20 sekund
		if(!(separ.podaj_milisekundy() % 20000)) // separ.podaj % 20000
		{
			ggamma.drukuj_czas();
			separ.drukuj_czas();
			alfap.drukuj_czas();
			cout << endl;
		}

		if(separ.podaj_sekundy() > 60) break;
	}

	cout << "Jak widac, zegary chodza nierowno,\na roznice beda sie caly czas powiekszaly\n";

	cout << "Wprowadzenie obiektu odniesienia===\n";

	const Modul_zegarowy zloty("ZLOTY", 9999999);

	while(true)
	{
		ggamma.mija_milisekunda();
		separ.mija_milisekunda();
		alfap.mija_milisekunda();

		zloty.mija_milisekunda();

		if(!(zloty.podaj_milisekundy() % 1000)) // zloty.podaj % 1000
		{
			ggamma.synchronizuj_sie_z(&zloty);
			separ.synchronizuj_sie_z(&zloty);
			alfap.synchronizuj_sie_z(&zloty);

			//zloty.synchronizuj_sie_z(&gamma);
		}

		if(zloty.podaj_milisekundy() / 1000.0 >= 600)
		{
			cout << "Podsumowanie po 600 sekundach...\n";
			ggamma.drukuj_czas();
			separ.drukuj_czas();
			alfap.drukuj_czas();
			cout << endl;
			break;
		}
	}
}
