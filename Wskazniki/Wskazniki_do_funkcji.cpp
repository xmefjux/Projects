#include <iostream>

using namespace std;
//******************************************************************************************************
// Przyk³ad definicji wskaŸnika do funkcji
	// int (*wfun)();	--- jak to czytamy?
	// Zaczynamy od nazwy. Nastêpnie poruszamy siê (o ile mo¿na) w prawo, dlatego ¿e po prawej stronie mog¹ staæ tylko operatory () lub [] - a, jak wiemy,
	// s¹ one najsilniejsze z mo¿liwych.
	// Potem, gdy ju¿ siê nie da w prawo (bo napotkaliœmy nawias zamykaj¹cy), poruszamy siê w lewo. Jeœli odczytaliœmy wszystko w obrêbie danego nawiasu
	// wychodzimy na zewn¹trz niego i znowu zaczynamy w prawo.

	// Wiêc...
	// wfun
	// w prawo siê nie da, bo jest nawias zamykaj¹cy, wiêc idziemy w lewo -
	// (*wfun)
	// - jest wskaŸnikiem... - (za³atwiliœmy ca³e wnêtrze nawiasu, wiêc wychodzimy na zewn¹trz i poruszamy siê w prawo, gdzie stoi bardzo mocny operator wywo³ania funkcji -
	// (*wfun)()
	// - do funkcji wywo³ywanej bez ¿adnych argumentów (nawias by³ pusty) - teraz ju¿ w lewo -
	// - a zwracaj¹c¹...
	// int (*wfun)()
	// - wartoœæ typu int

	// Nawiasy by³y tutaj kluczowe, bo gdyby je opuœciæ:
	// int *wfun();
	// to by³aby deklaracja funkcji, a nie wskaŸnika.
	// wfun()
	// wfun jest funkcj¹ wywo³ywan¹ bez ¿adnych argumentów, a zwracaj¹c¹
	// *wfun()
	// wskaŸnik do
	// int *wfun()
	// typu int
	// Czyli coœ zupe³nie innego. To dlatego, ¿e nawiasy s¹ silniejsze ni¿ gwiazdka.
//******************************************************************************************************
int pierwsza();
int druga();
void Wskazniki_do_funkcji()
{
	int i;
	int (*wskaz_fun)();

	cout << "Na ktora funkcje ma pokazac wskaznik?" << endl
		 << "pierwsza  -\t1" << endl << "czy druga -\t2" << endl
		 << "napisz numer: ";
	cin >> i;
	
	switch(i)
	{
		case 1:
			wskaz_fun = &pierwsza; // w tym przypadku operator & jest zbêdny, ale w przypadku tzw. funkcji sk³adowych jest potrzebny, wiêc lepiej u¿ywaæ go zawsze
			break;
		case 2:
			wskaz_fun = &druga; // podanie adresu funkcji odbywa siê bez nawiasów poniewa¿ tylko o niej mówimy, a nie wywo³ujemy jej
			break;
		default:
			wskaz_fun = 0; 
			break;
	}

	cout << "Wedlug rozkazu!" << endl;

	if(wskaz_fun)
	{
		for(i = 0; i < 3; i++)
		{
			(*wskaz_fun)(); // wywo³anie funkcji pokazywanej wskaŸnikiem mo¿na zapisaæ na dwa sposoby
			// wskaŸnik_funkcji(argumenty);
			// (*wskaŸnik_funkcji)(argumenty);
			//wskaz_fun();
		}

	}


}
//******************************************************************************************************
int pierwsza()
{
	cout << "funkcja pierwsza!" << endl;
	return 9;
}
//******************************************************************************************************
int druga()
{
	cout << "funkcja druga!" << endl;
	return 106;
}
