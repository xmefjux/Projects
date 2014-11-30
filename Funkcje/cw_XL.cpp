#include <iostream>

using namespace std;

int silnia(int n, int wynik = 1);
//****************************************************************************
int silnia(int n, int wynik)
{
	int suma = 0;
	static int krok;
	krok++;
	wynik = (wynik * krok);
	if(n - 1)
	{
		suma = silnia(n - 1, wynik);
	}
	else
	{
		suma = wynik;
		return suma;
	}
}