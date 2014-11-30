#include <iostream>

using namespace std;
//******************************************************************************************************

// WskaŸnik do obiektu sta³ego nie mo¿e zamieniæ siê na wskaŸnik do obiektu nie-sta³ego (zmiennego).
// Nowy wskaŸnik nie mo¿e mieæ wiêkszych uprawnieñ w stosunku do pokazywanego obiektu.

void Const_cast()
{
	double zmienna = 0;
	const double stala = 3.14;

	double *wsk_do_zmiennej = &zmienna;
	const double *wsk_do_stalej = &stala;
	const double *wsk2_do_stalej;

	cout << "Na poczatku, stala = " << stala << endl;

	wsk2_do_stalej = wsk_do_zmiennej;

	// wsk_do_zmiennej = wsk_do_stalej;			// b³¹d
	wsk_do_zmiennej = const_cast<double*>(wsk_do_stalej);

	*wsk_do_zmiennej = -333;

	cout << "Potem ---> stala = " << stala << endl;

	// sta³y (nieruchomy) wskaŸnik do zmiennej
	// usuwamy sta³oœæ sta³ej, a nadajemy sta³oœæ (nieruchomoœæ) wskaŸnika

	double * const st_wsk_do_zmiennej = const_cast<double * const>(wsk_do_stalej);
	wsk_do_zmiennej = st_wsk_do_zmiennej;

	// ...
	int *wskint;
	wskint = reinterpret_cast<int*>(const_cast<double*>(wsk_do_stalej));
	// ...

	// const cast s³u¿y by dopasowaæ wyra¿enie ujête w nawias do typu stoj¹cego po lewej stronie =
	// Za pomoc¹ const_cast nie mo¿na usun¹æ przydomka const z ¿adnego obiektu.

}
