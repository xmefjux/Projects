#include <iostream>

using namespace std;

double
	poczatek_x,
	poczatek_y,
	skala_x = 1,
	skala_y = 1;
//****************************************************************************
inline double wspx(double wspolrzedna)
{
	return ( (wspolrzedna - poczatek_x) * skala_x);
}
//****************************************************************************
inline double wspy(double wspolrzedna)
{
	return ( (wspolrzedna - poczatek_y) * skala_y);
}
//****************************************************************************
void main_inline()
{
	double	x1 = 100,			// przyk�adowy punkt
			y1 = 100;

	cout << "Mamy w punkt o wspolrzednych" << endl;
	cout << "x = " << wspx(x1)
		<< " ,y = " << wspy(y1) << endl;

	// zmieniamy pocz�tek uk�adu wsp�rz�dnych
	poczatek_x = 20;
	poczatek_y = -500;

	cout << "Gdy przesuniemy uklad wspolrzednych tak," << endl
		 << "ze poczatek znajdzie sie w punkcie" << endl
		 << poczatek_x << ", " << poczatek_y << endl
		 << "to nowe wspolrzedne punktu" << endl
		 << "w takim ukladzie sa: "
		 << "x = " << wspx(x1)
		 << " y = " << wspy(y1) << endl;

	// zag�szczamy skal� osi poziomej
	skala_x = 0.5;
	cout << "Gdy dodatkowo zmienimy skale pozioma tak, ze skala x = " << skala_x << endl
		 << "to ten sam punkt ma teraz wspolrzedne: " << endl
		 << "x = " << wspx(x1)
		 << " y = " << wspy(y1) << endl;
}

// instrukcja inline (bardzo podobna do instrukcji macro w assemblerze)
// u�ywa si� jej do ma�ych funkcji, kt�re s� wykonywane wiele razy, by pomin�� przej�cie i powr�t do funkcji podczas wykonywania programu
// z pomoc� inline te funkcje zostan� wykonane "w linii"
// definicje takich funkcji musz� znajdowa� si� na g�rze ka�dego pliku lub najlepiej w pliku nag��wkowym