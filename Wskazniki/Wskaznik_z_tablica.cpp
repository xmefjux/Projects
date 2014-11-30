#include <iostream>

using namespace std;
//******************************************************************************************************
void wskaznik_z_tablica()
{
	int *wi;
	double *wd;
	int tabint[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	double tabdbl[10];

	wd = tabdbl;	// wd = &tabdbl[0];
	for(int i = 0; i < 10; i++)
	{
		*(wd++) = i / 10.0;		// wpis warto��i do tablicy double
	}

	cout << "Tresc tablic na poczatku" << endl;

	wi = tabint;
	wd = tabdbl;

	for(int k = 0; k < 10; k++)
	{
		cout << k << ") \t" << *wi << "\t\t\t\t"		// przy u�ywaniu wska�nika zapis *wi jest po prostu warto�ci� na kt�r� ten wska�nik pokazuje
			 << *wd << endl;
		wi++;
		wd++;
	}

	// ---------- nowe ustawienie wska�nik�w -----------------

	wi = &tabint[5];
	wd = tabdbl + 2;		// wd = &tabdbl[2];
	
	// ------- wypisanie do tablic kilku nowych warto�ci -----

	for(int m = 0; m < 4; m++)
	{
		*(wi++) = -222;
		*(wd++) = -777.5;
	}

	cout << "Tresc tablic po wstawieniu nowych wartosci" << endl;
	wi = tabint;
	wd = tabdbl;
	for(int p = 0; p < 10; p++)
	{
		cout << "tabint[" << p << "] = "
			 << *(wi++)
			 << " \t\ttabdbl[" << p <<"] = "
			 << *(wd++)
			 << endl;
	}

	// ------ Komentarz --------
	// Nazwa tablicy jest jakby sta�ym wska�nikiem do jej zerowego elementu.
	// czyli:
	// tablica[3] jest r�wnowa�ne z *(tablica+3)
	// natomiast sama nazwa tablica nie zachowuje si� jak wska�nik (jest tylko adresem pierwszego elementu danej tablicy)


}
//******************************************************************************************************