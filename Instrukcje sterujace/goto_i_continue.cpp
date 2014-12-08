#include <iostream>

void cw8()
{
	std::cout << "Cos piszemy\n";
	goto aaa;
	std::cout << "Tego nie piszemy";
aaa:
	std::cout << "Piszemy dalej\n";
	// goto mo¿na u¿ywaæ do wyskoczenia z mocno zagnie¿d¿onych pêtli
	// w innych przypadkach raczej unikaæ

	for(int k=0; k<12; k=k+1)
	{
		std::cout << "A";
		if(k>1)continue;
		std::cout << "b\n";
	}
	// continue przerywa pracê danej iteracji pêtli i przechodzi do nastêpnej iteracji bez wykonywania instrukcji po 'continue'
}
