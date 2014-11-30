#include <iostream>

using namespace std;

long potega(int stopien, long liczba);

//****************************************************************************
void main_potegi()
{
	int pocz, koniec;

	cout << "Program na obliczanie poteg licz calkowitych z zadanego przedzialu" << endl
		 << "Podaj poczatek przedialu: ";
	cin	 >> pocz;

	cout << endl << "Podaj koniec przedzialu: ";
	cin  >> koniec;

	// P�tla drukuj�ca wyniki z danego przedzia�u
	for(int i = pocz; i <= koniec; i++)
	{
		cout << i
			 << " do kwadratu = "
			 << potega(2, i)					// wywo�anie funkcji
			 << " a do szescianu = "
			 << potega(3, i)					// wywo�anie funkcji
			 << endl;
	}
}
//****************************************************************************
long potega(int stopien, long liczba)
{
	long wynik = liczba;
	for(int i = 1; i < stopien; i++)
	{
		wynik = wynik * liczba;					// to samo co wynik *= liczba;
	}
	return wynik;
}
//****************************************************************************