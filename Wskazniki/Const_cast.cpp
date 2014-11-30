#include <iostream>

using namespace std;
//******************************************************************************************************

// Wska�nik do obiektu sta�ego nie mo�e zamieni� si� na wska�nik do obiektu nie-sta�ego (zmiennego).
// Nowy wska�nik nie mo�e mie� wi�kszych uprawnie� w stosunku do pokazywanego obiektu.

void Const_cast()
{
	double zmienna = 0;
	const double stala = 3.14;

	double *wsk_do_zmiennej = &zmienna;
	const double *wsk_do_stalej = &stala;
	const double *wsk2_do_stalej;

	cout << "Na poczatku, stala = " << stala << endl;

	wsk2_do_stalej = wsk_do_zmiennej;

	// wsk_do_zmiennej = wsk_do_stalej;			// b��d
	wsk_do_zmiennej = const_cast<double*>(wsk_do_stalej);

	*wsk_do_zmiennej = -333;

	cout << "Potem ---> stala = " << stala << endl;

	// sta�y (nieruchomy) wska�nik do zmiennej
	// usuwamy sta�o�� sta�ej, a nadajemy sta�o�� (nieruchomo��) wska�nika

	double * const st_wsk_do_zmiennej = const_cast<double * const>(wsk_do_stalej);
	wsk_do_zmiennej = st_wsk_do_zmiennej;

	// ...
	int *wskint;
	wskint = reinterpret_cast<int*>(const_cast<double*>(wsk_do_stalej));
	// ...

	// const cast s�u�y by dopasowa� wyra�enie uj�te w nawias do typu stoj�cego po lewej stronie =
	// Za pomoc� const_cast nie mo�na usun�� przydomka const z �adnego obiektu.

}
