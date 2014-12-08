#include <iostream>

void cw4()
{
	std::cout << "Stewardzie, ilu leci pasazerow? ";
	int ile;
	std::cin >> ile;

	for(int i=1; i <= ile; i=i+1){
		std::cout << "Pasazer nr " << i << " prosze zapiac pasy! \n";
	}
	std::cout << "Skoro wszyscy juz zapieli, to ladujemy." << std::endl;
}