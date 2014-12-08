#include <iostream>

void cw5()
{
	std::cout	<< "Kapitanie, ktory podzespol sprawdzic?\n"
				<< "nr 10 - Silnik \nnr 35 - Stery \nnr 28 - Radar\n"
				<< "Podaj kapitanie numer: ";
	int ktory;
	std::cin >> ktory;

	switch(ktory)
	{
		case 10:
			std::cout << "Sprawdzamy silnik\n";
			break;

		case 28:
			std::cout << "Sprawdzamy radar\n";
			break;

		case 35:
			std::cout << "Sprawdzamy stery\n";
			break;

		default:
			std::cout << "Zazadales nr " << ktory << " - nie znam takiego!\n";
			break;
	}
}