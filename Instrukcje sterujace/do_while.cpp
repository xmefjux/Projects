#include <iostream>

void cw3()
{
	char litera;
	do {
		std::cout << "Napisz jakas litere: ";
		std::cin >> litera;
		std::cout << "\nNapisales: " << litera << std::endl;
	}while(litera != 'K');

	std::cout << "Skoro napisales K to konczymy!" << std::endl;
}