#include <iostream>

void cw2()
{
	int ile;

	std::cout << "Ile gwiazdek ma miec kapitan? : ";
	std::cin >> ile;
	std::cout << "\nNo to narysujmy wszystkie " << ile << " : ";

	// p�tla while rysuj�ca gwiazdki
	while(ile)
	{
		std::cout << "*";
		ile = ile - 1;
	}
	// na dow�d, �e mia� prawo przerwa� p�tl�
	std::cout << "\nTeraz zmienna ile ma wartosc " << ile << std::endl;
}