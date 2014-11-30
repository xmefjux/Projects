#include <iostream>

using namespace std;
//******************************************************************************************************
void pokazywacz(const int *wsk, int ile);
void zmieniacz(int *wsk, int ile);
//******************************************************************************************************
void Argument_formalny_do_const()
{
	// Wskaünik do sta≥ego obiektu. Taki wskaünik wskazuje na obiekty, ale nie pozwala na ich modyfikacjÍ.
	// Funkcja definiuje sobie na stosie wskaünik do obiektu sta≥ego. Otrzymany adres obiektu wstawia do w≥aúnie takiego wskaünika.

	// Jeúli mamy obiekt sta≥y (z przydomkiem const) to nie moøna do niego pokazywaÊ zwyk≥ym wskaünikiem, tylko z przydomkiem const.

	int tablica[4] = { 110, 120, 130, 140 };

	pokazywacz(tablica, 4);
	zmieniacz(tablica, 4);
	pokazywacz(tablica, 4);
	cout << "Dla potwierdzenia tablica[3] = " << tablica[3] << endl;

	// Ustawienie wskaünika na konkretnπ komÛrkÍ w pamiÍci.
	int *wsk_temperatury;
	wsk_temperatury = reinterpret_cast<int*>(93952);
	//*wsk_temperatury = 1; // przypisanie jakiejú wartoúci do tej komÛrki w pamiÍci
	cout << "Obecna komorka " << *wsk_temperatury << endl;
}
//******************************************************************************************************
void pokazywacz(const int *wsk, int ile)
{
	cout << "Dziala pokazywacz" << endl;

	for(int i = 0; i < ile; i++, wsk++)
	{
		// *wsk += 22; // b≥πd! z powodu przydomka const
		cout << "element nr " << i << " ma wartosc " << *wsk << endl;
	}

}
//******************************************************************************************************
void zmieniacz(int *wsk, int ile)
{
	cout << "Dziala zmieniacz" << endl;

	for(int i = 0; i < ile; i++, wsk++)
	{
		*wsk += 500;		// wolno nam! (*wsk czyli to co kryje siÍ pod wskaünikiem - element tablicy)
		cout << "element nr " << i << " ma wartosc " << *wsk << endl;
	}

}
