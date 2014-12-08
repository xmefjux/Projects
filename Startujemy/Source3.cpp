#include <iostream>
void cwiczenie2(){
	
	int		wejscie;				//dana wejsciowa w centymetrach
	double	przelicznik = 2.54;		// 1 cal = 2.54cm
	double	wyjscie_cale;			// wyjscie w calach

	std::cout << "Podaj centymetry: ";		// pobieramy liczbe
	std::cin >> wejscie;

	wyjscie_cale = wejscie * przelicznik;	// przeliczamy na centymetry

	std::cout << std::endl;
	std::cout << wejscie << " centymetrow to: " << wyjscie_cale << " cali.";
	std::cout << std::endl;
}