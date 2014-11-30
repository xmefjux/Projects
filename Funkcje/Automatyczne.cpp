#include <iostream>

using namespace std;

int zwroc();
void pisz();
//
//extern void funkcja_egipska();

extern int x;
// zmienna globalna lub z przestrzeni nazw jest zawsze inicjalizowana warto�ci� zerow� (odpowiednio dla ka�dego typu)
// te zmienne s� zak�adane w normalnym obszarze pami�ci

//****************************************************************************
void main_automatyczne()
{
	//funkcja_egipska();
	// auto int m; <- auto jest domniemane wewn�trz funkcji
	x = zwroc();
	//cout << x << endl;
	//pisz();

	// kompilator przydziela stos dla funkcji
	// zmienna m jest tworzona na stosie
	// nie mo�na zwraca� adresu takiej zmiennej, bo przestaje ona istnie� po wykonaniu funkcji
	// pod tym adresem b�dzie ju� co� zupe�nie innego
	// przy ponownym wywo�aniu funkcji nie ma gwarancji, �e zmienna m b�dzie mia�a tak� sam� warto�� jak przed unicestwieniem
	// obiekty automatyczne s� inicjalizowane warto�ci� �mieciow�, nale�y do nich wpierw przypisa� jaka� sensown� warto��
	// zmienne lokalne dla jakiej� funkcji s� powo�ywane do �ycia w momencie ich definicji, a gdy ko�czy si� wykonywanie tej funkcji przestaj� istnie�
}
//****************************************************************************
int zwroc()
{
	int a = 5;
	return a;
}
//****************************************************************************
void pisz()
{
	for(int i=100; i>=1; i--)
	{
		if(i < 10)
			cout << "00" << i << endl;
		else if(i < 100)
			cout << "0" << i << endl;
		else
			cout << i << endl;
	}
}
