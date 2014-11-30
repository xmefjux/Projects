#include <iostream>

using namespace std;
//******************************************************************************************************
void Stale_wskazniki()
{
	int zoo;
	int * const wskaz = &zoo; // wskaz jest to sta�y (const) wska�nik (*) pokazuj�cy na obiekty typu int.
	// inicjalizacja nast�puje od razu poniewa� jest to STA�Y wska�nik

	// R�nica mi�dzy sta�ym wska�nikiem, a wska�nikiem do sta�ych:
	// Sta� wska�nik to taki, kt�ry zawsze pokazuje na to samo. Nie mo�na nim poruszy�.
	// Wska�nik do obiektu sta�ego to taki wska�nik, kt�ry pokazywany obiekt uznaje za sta�y. Nie mo�e go wi�c modyfikowa�.

	const double * const p = 0; // p jest sta�ym (const) wska�nikiem (*) pokazuj�cym na obiekt typu double traktowany jako sta�y (const).

	// Przyk�ad u�ycia sta�ego (nieruchomego) wska�nika

	int a = 5,
		b = 100;
	int * wa;									// Zwyk�y wska�nik
	int * const st_wsk = &a;					// Nieruchomy wska�nik

	wa = &a;									// ustaw wska�nik na zmienn� a
	*wa = 1;									// za�adowanie 1 do zmiennej a
	*st_wsk = 2;								// za�adowanie 2 do zmiennej a

	// ------ teraz pr�bujemy poruszy� oba wska�niki

	wa = &b;									// przestaw wska�nik, by pokazywa� na zmienn� b

	//st_wsk = &b;								// b��d - bo to jest nieruchomy wska�nik !!!
												// jest na zawsze ustawiony na zmienn� a
	// --------------------------------------------------------------------------------------------------------------------
	// Przyk�ad wska�nika pokazuj�cego na sta��

	int x[4] = { 0, 1, 2, 3 };
	static int tmp;
	int *w;										// zwyk�y wska�nik
	const int * wsk_do_st;						// wska�nik do obiektu sta�ego. Nie musi on by� od razu ustawiany. Mo�na nim nawet porusza�.

	w = x;										// ustawienie obu wska�nik�w na pocz�tek tablicy
	wsk_do_st = x;

	tmp = *w;									// odczytanie zerowego elementu tablicy
	tmp = *wsk_do_st;							// jak wy�ej

	// ---------- przesuni�cie wska�nik�w na nast�pny element tablicy
	w++;
	wsk_do_st++;								// porusza� nim wolno

	// ---------- b�dziemy tam wpisywa�
	*w = 0;										// wpisanie 0 do elementu x[1]
	//*wsk_do_st = 0;								// B��d! Ten wska�nik traktuje to, na co pokazuje jako obiekt sta�y.
												// Za pomoc� tego wska�nika obiektu modyfikowa� nie wolno.

	// --------------------------------------------------------------------------------------------------------------------
	// Przyk�ad na sta�y (nieruchomy) wska�nik do sta�ego obiektu

	int m = 6,
		n = 4,
		tmp1;
	const int * const ws = &m;					// poniewa� jest to sta�y wska�nik nale�y go od razu zainicjalizowa� adresem, na jaki ma pokazywa�

	tmp1 = *ws;									// odczytanie warto�ci z obiektu pokazywanego

	//*ws = 15;									// b��d! zapisa� tam nie mo�emy. Wska�nik traktuje sw�j obiekt jako sta�y.
	//w = &n;									// b��d! wska�nik na dodatek jest nieruchomy, nie mo�na nim pokazywa� na obiekt inny ni� m
}
