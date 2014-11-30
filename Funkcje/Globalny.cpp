#include <iostream>

using namespace std;

int liczba;

void fff(void);
//****************************************************************************
void main_globalny()
{
	int i;
	liczba = 10;
	i = 4;
	cout << "Wartosci: liczba = " << liczba << ", i = " << i << endl;
	fff();
}
//****************************************************************************
void fff(void)
{
	int x;
	x = 5;
	liczba--;
	// i = 4;				// b³¹d!

	cout << "(fff) sumka = " << (x + liczba) << endl;
}
//****************************************************************************

