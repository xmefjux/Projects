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
	double	x1 = 100,			// przyk³adowy punkt
			y1 = 100;

	cout << "Mamy w punkt o wspolrzednych" << endl;
	cout << "x = " << wspx(x1)
		<< " ,y = " << wspy(y1) << endl;

	// zmieniamy pocz¹tek uk³adu wspó³rzêdnych
	poczatek_x = 20;
	poczatek_y = -500;

	cout << "Gdy przesuniemy uklad wspolrzednych tak," << endl
		 << "ze poczatek znajdzie sie w punkcie" << endl
		 << poczatek_x << ", " << poczatek_y << endl
		 << "to nowe wspolrzedne punktu" << endl
		 << "w takim ukladzie sa: "
		 << "x = " << wspx(x1)
		 << " y = " << wspy(y1) << endl;

	// zagêszczamy skalê osi poziomej
	skala_x = 0.5;
	cout << "Gdy dodatkowo zmienimy skale pozioma tak, ze skala x = " << skala_x << endl
		 << "to ten sam punkt ma teraz wspolrzedne: " << endl
		 << "x = " << wspx(x1)
		 << " y = " << wspy(y1) << endl;
}

// instrukcja inline (bardzo podobna do instrukcji macro w assemblerze)
// u¿ywa siê jej do ma³ych funkcji, które s¹ wykonywane wiele razy, by pomin¹æ przejœcie i powrót do funkcji podczas wykonywania programu
// z pomoc¹ inline te funkcje zostan¹ wykonane "w linii"
// definicje takich funkcji musz¹ znajdowaæ siê na górze ka¿dego pliku lub najlepiej w pliku nag³ówkowym