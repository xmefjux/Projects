#include <iostream>

void cw8()
{
	std::cout << "Cos piszemy\n";
	goto aaa;
	std::cout << "Tego nie piszemy";
aaa:
	std::cout << "Piszemy dalej\n";
	// goto mo�na u�ywa� do wyskoczenia z mocno zagnie�d�onych p�tli
	// w innych przypadkach raczej unika�

	for(int k=0; k<12; k=k+1)
	{
		std::cout << "A";
		if(k>1)continue;
		std::cout << "b\n";
	}
	// continue przerywa prac� danej iteracji p�tli i przechodzi do nast�pnej iteracji bez wykonywania instrukcji po 'continue'
}
