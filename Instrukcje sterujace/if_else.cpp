#include <iostream>

void cw1()
{
	int wys, punkty_karne;					// definicja dw�ch zmiennych int
											// Obie s� tego samego typu, wi�c wystarczy przecinek oddzielaj�cy nazwy.
	std::cout << "Na jakiej wysokosci lecimy ? [w metrach]: ";
	std::cin >> wys;

	// ----------- rozwa�amy sytuacje -----------
	if(wys < 500)
	{
		std::cout << std::endl << wys << " metrow to za nisko!\n";
		punkty_karne = 1;
	}
	else{
		std::cout << std::endl << "Na wysokosci " << wys << " metrow jestes juz bezpieczny \n";
		punkty_karne = 0;
	}
	// -------------------- ocena Twoich wynik�w -----------------
	std::cout << "Masz " << punkty_karne << " punktow karnych \n";
	if(punkty_karne) std::cout << "Popraw sie!" << std::endl;
}