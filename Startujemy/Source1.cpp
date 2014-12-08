/* ----------------------------------------
Program na przeliczanie wysokosci podanej
w stopach na wysokoœæ w metrach.
Cwiczymy tu operacje wczytywania z klawiatury
i wypisywania na ekranie
-------------------------------------------*/
#include <iostream>
void funkcja()
{
	int		stopy;										// Do przechowania danej wejsciowej
	double	metry;										// Do wpisania wyniku
	double	przelicznik = 0.3;							// przelicznik: stopy na metry

	std::cout << "Podaj wysokosc w stopach: ";			// przyjecie danej z klawiatury
	std::cin >> stopy;

	metry = stopy * przelicznik;						// wlasciwe przeliczenie

	std::cout << std::endl;								// lub std:: cout << "\n"

	// ------- wypisanie wynikow --------
	std::cout << stopy << " stop - to jest: " << metry << " metrow\n";

	int 
		export_pszenicy
		;
}
//========================================================================================================
