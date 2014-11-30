#include <iostream>

using namespace std;

//static int x;
// zmienna globalna z przydomkiem static, staje siê obiektem globalnym tylko i wy³¹cznie w tym pliku Ÿród³owym
// w innych plikach ta nazwa jest ju¿ nieznana
// ten sposób jest ju¿ uznany jako przestarza³y i zamiast niego stosuje siê anonimow¹ przestrzeñ nazw

namespace // bez nazwy, wiêc anonimowa
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