#include <iostream>

using namespace std;
//******************************************************************************************************
void Stale_wskazniki()
{
	int zoo;
	int * const wskaz = &zoo; // wskaz jest to sta≥y (const) wskaünik (*) pokazujπcy na obiekty typu int.
	// inicjalizacja nastÍpuje od razu poniewaø jest to STA£Y wskaünik

	// RÛønica miÍdzy sta≥ym wskaünikiem, a wskaünikiem do sta≥ych:
	// Sta≥ wskaünik to taki, ktÛry zawsze pokazuje na to samo. Nie moøna nim poruszyÊ.
	// Wskaünik do obiektu sta≥ego to taki wskaünik, ktÛry pokazywany obiekt uznaje za sta≥y. Nie moøe go wiÍc modyfikowaÊ.

	const double * const p = 0; // p jest sta≥ym (const) wskaünikiem (*) pokazujπcym na obiekt typu double traktowany jako sta≥y (const).

	// Przyk≥ad uøycia sta≥ego (nieruchomego) wskaünika

	int a = 5,
		b = 100;
	int * wa;									// Zwyk≥y wskaünik
	int * const st_wsk = &a;					// Nieruchomy wskaünik

	wa = &a;									// ustaw wskaünik na zmiennπ a
	*wa = 1;									// za≥adowanie 1 do zmiennej a
	*st_wsk = 2;								// za≥adowanie 2 do zmiennej a

	// ------ teraz prÛbujemy poruszyÊ oba wskaüniki

	wa = &b;									// przestaw wskaünik, by pokazywa≥ na zmiennπ b

	//st_wsk = &b;								// b≥πd - bo to jest nieruchomy wskaünik !!!
												// jest na zawsze ustawiony na zmiennπ a
	// --------------------------------------------------------------------------------------------------------------------
	// Przyk≥ad wskaünika pokazujπcego na sta≥π

	int x[4] = { 0, 1, 2, 3 };
	static int tmp;
	int *w;										// zwyk≥y wskaünik
	const int * wsk_do_st;						// wskaünik do obiektu sta≥ego. Nie musi on byÊ od razu ustawiany. Moøna nim nawet poruszaÊ.

	w = x;										// ustawienie obu wskaünikÛw na poczπtek tablicy
	wsk_do_st = x;

	tmp = *w;									// odczytanie zerowego elementu tablicy
	tmp = *wsk_do_st;							// jak wyøej

	// ---------- przesuniÍcie wskaünikÛw na nastÍpny element tablicy
	w++;
	wsk_do_st++;								// poruszaÊ nim wolno

	// ---------- bÍdziemy tam wpisywaÊ
	*w = 0;										// wpisanie 0 do elementu x[1]
	//*wsk_do_st = 0;								// B≥πd! Ten wskaünik traktuje to, na co pokazuje jako obiekt sta≥y.
												// Za pomocπ tego wskaünika obiektu modyfikowaÊ nie wolno.

	// --------------------------------------------------------------------------------------------------------------------
	// Przyk≥ad na sta≥y (nieruchomy) wskaünik do sta≥ego obiektu

	int m = 6,
		n = 4,
		tmp1;
	const int * const ws = &m;					// poniewaø jest to sta≥y wskaünik naleøy go od razu zainicjalizowaÊ adresem, na jaki ma pokazywaÊ

	tmp1 = *ws;									// odczytanie wartoúci z obiektu pokazywanego

	//*ws = 15;									// b≥πd! zapisaÊ tam nie moøemy. Wskaünik traktuje swÛj obiekt jako sta≥y.
	//w = &n;									// b≥πd! wskaünik na dodatek jest nieruchomy, nie moøna nim pokazywaÊ na obiekt inny niø m
}
