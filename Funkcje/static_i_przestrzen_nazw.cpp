#include <iostream>

using namespace std;

//static int x;
// zmienna globalna z przydomkiem static, staje si� obiektem globalnym tylko i wy��cznie w tym pliku �r�d�owym
// w innych plikach ta nazwa jest ju� nieznana
// ten spos�b jest ju� uznany jako przestarza�y i zamiast niego stosuje si� anonimow� przestrze� nazw

namespace // bez nazwy, wi�c anonimowa
{
	int x;								// definicja obiektu
	//----------------
	void funkcja()						// definicja funkcji
	{
		// ...
	}
	//-----------------
	double inna_funkcja(char z);		// deklaracja funkcji
}

double inna_funkcja(char z)
{
	x = 5;
	return static_cast<double>(x);
}