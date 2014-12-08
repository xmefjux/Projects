#include <iostream>

void cw6()
{
	int nr;
	
	std::cout << "daj nr: ";
	std::cin >> nr;
	
	switch(nr)
	{
	case 3:		std::cout << "*";
	case 2:		std::cout << "-";
	case 1:		std::cout << "!";
	}
}