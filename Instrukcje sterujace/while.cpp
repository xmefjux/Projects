#include <iostream>

void cw2()
{
	int ile;

	std::cout << "Ile gwiazdek ma miec kapitan? : ";
	std::cin >> ile;
	std::cout << "\nNo to narysujmy wszystkie " << ile << " : ";

	// pêtla while rysuj¹ca gwiazdki
	while(ile)
	{
		std::cout << "*";
		ile = ile - 1;
	}
	// na dowód, ¿e mia³ prawo przerwaæ pêtlê
	std::cout << "\nTeraz zmienna ile ma wartosc " << ile << std::endl;
}