#include <iostream>

void cw7()
{
	int i = 7;
	while(1)
	{
		std::cout << "Petla, i = " << i << std::endl;
		i = i - 1;
		if(i<5)
		{
			std::cout << "Przerywamy!";
			break;
		}
	}

	std::cout << std::endl;

	int m, zakoncz = 3;
	for(int i=0; i < 4; i = i+1)
	{
		for(m=0; m < 10; m = m+1)
		{
			std::cout << "*";
			if(m > zakoncz)break;
		}
		std::cout << "\nKontynuujemy zewnetrzna petle for dla i = " << i << std::endl;
	}
	std::cout << std::endl;
}