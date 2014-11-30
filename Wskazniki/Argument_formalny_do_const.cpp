#include <iostream>

using namespace std;
//******************************************************************************************************
void pokazywacz(const int *wsk, int ile);
void zmieniacz(int *wsk, int ile);
//******************************************************************************************************
void Argument_formalny_do_const()
{
	// Wska�nik do sta�ego obiektu. Taki wska�nik wskazuje na obiekty, ale nie pozwala na ich modyfikacj�.
	// Funkcja definiuje sobie na stosie wska�nik do obiektu sta�ego. Otrzymany adres obiektu wstawia do w�a�nie takiego wska�nika.

	// Je�li mamy obiekt sta�y (z przydomkiem const) to nie mo�na do niego pokazywa� zwyk�ym wska�nikiem, tylko z przydomkiem const.

	int tablica[4] = { 110, 120, 130, 140 };

	pokazywacz(tablica, 4);
	zmieniacz(tablica, 4);
	pokazywacz(tablica, 4);
	cout << "Dla potwierdzenia tablica[3] = " << tablica[3] << endl;

	// Ustawienie wska�nika na konkretn� kom�rk� w pami�ci.
	int *wsk_temperatury;
	wsk_temperatury = reinterpret_cast<int*>(93952);
	//*wsk_temperatury = 1; // przypisanie jakiej� warto�ci do tej kom�rki w pami�ci
	cout << "Obecna komorka " << *wsk_temperatury << endl;
}
//******************************************************************************************************
void pokazywacz(const int *wsk, int ile)
{
	cout << "Dziala pokazywacz" << endl;

	for(int i = 0; i < ile; i++, wsk++)
	{
		// *wsk += 22; // b��d! z powodu przydomka const
		cout << "element nr " << i << " ma wartosc " << *wsk << endl;
	}

}
//******************************************************************************************************
void zmieniacz(int *wsk, int ile)
{
	cout << "Dziala zmieniacz" << endl;

	for(int i = 0; i < ile; i++, wsk++)
	{
		*wsk += 500;		// wolno nam! (*wsk czyli to co kryje si� pod wska�nikiem - element tablicy)
		cout << "element nr " << i << " ma wartosc " << *wsk << endl;
	}

}
