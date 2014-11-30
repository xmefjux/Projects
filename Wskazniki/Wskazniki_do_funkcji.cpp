#include <iostream>

using namespace std;
//******************************************************************************************************
// Przyk�ad definicji wska�nika do funkcji
	// int (*wfun)();	--- jak to czytamy?
	// Zaczynamy od nazwy. Nast�pnie poruszamy si� (o ile mo�na) w prawo, dlatego �e po prawej stronie mog� sta� tylko operatory () lub [] - a, jak wiemy,
	// s� one najsilniejsze z mo�liwych.
	// Potem, gdy ju� si� nie da w prawo (bo napotkali�my nawias zamykaj�cy), poruszamy si� w lewo. Je�li odczytali�my wszystko w obr�bie danego nawiasu
	// wychodzimy na zewn�trz niego i znowu zaczynamy w prawo.

	// Wi�c...
	// wfun
	// w prawo si� nie da, bo jest nawias zamykaj�cy, wi�c idziemy w lewo -
	// (*wfun)
	// - jest wska�nikiem... - (za�atwili�my ca�e wn�trze nawiasu, wi�c wychodzimy na zewn�trz i poruszamy si� w prawo, gdzie stoi bardzo mocny operator wywo�ania funkcji -
	// (*wfun)()
	// - do funkcji wywo�ywanej bez �adnych argument�w (nawias by� pusty) - teraz ju� w lewo -
	// - a zwracaj�c�...
	// int (*wfun)()
	// - warto�� typu int

	// Nawiasy by�y tutaj kluczowe, bo gdyby je opu�ci�:
	// int *wfun();
	// to by�aby deklaracja funkcji, a nie wska�nika.
	// wfun()
	// wfun jest funkcj� wywo�ywan� bez �adnych argument�w, a zwracaj�c�
	// *wfun()
	// wska�nik do
	// int *wfun()
	// typu int
	// Czyli co� zupe�nie innego. To dlatego, �e nawiasy s� silniejsze ni� gwiazdka.
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
			wskaz_fun = &pierwsza; // w tym przypadku operator & jest zb�dny, ale w przypadku tzw. funkcji sk�adowych jest potrzebny, wi�c lepiej u�ywa� go zawsze
			break;
		case 2:
			wskaz_fun = &druga; // podanie adresu funkcji odbywa si� bez nawias�w poniewa� tylko o niej m�wimy, a nie wywo�ujemy jej
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
			(*wskaz_fun)(); // wywo�anie funkcji pokazywanej wska�nikiem mo�na zapisa� na dwa sposoby
			// wska�nik_funkcji(argumenty);
			// (*wska�nik_funkcji)(argumenty);
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
