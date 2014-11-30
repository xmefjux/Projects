#include <iostream>
#include <cstdlib>
#include <new>
//******************************************************************************************************
using namespace std;
//******************************************************************************************************
void funkcja_alarmowa();
long k;
//******************************************************************************************************
void Zapas_pamieci()
{
	// W sytuacji kiedy wyczerpiemy dostêpny obszar pamiêci, a chcemy utworzyæ nowy obiekt, komputer mo¿e nas o tym powiadomiæ na 3 sposoby:
	// - zwrot adresu zero - (sposób "dawny")
	// - rzucenie wyj¹tku bad_alloc - (sposób "nowoczesny")
	// - wywo³anie jakiejœ zaproponowanej przez nas funkcji.

	// 1.
	// Zwrot adresu zero
	{
		double *wsk, *wsk1;
		wsk = new (nothrow) double[100000000];
		wsk1 = new (nothrow) double[100000000];
		if(!wsk1)
		{
			cout << "Rezerwacja nieudana" << endl;
			// tu reakcja na tê nieudan¹ rezerwacjê
			// ...
		}
		delete wsk; delete wsk1;
	}
	// 2.
	// Nowy sposób: try{} catch{} - rzucanie i ³apanie wyj¹tku
	{
		double *wsk, *wsk1;
		try
		{
			wsk = new double[100000000];
			wsk1 = new double[100000000];
			// uda³o siê, pracujemy na takim obiekcie
			// ...
			// ...
		}
		catch(bad_alloc)
		{
			cout << "Przechwycona nieudana rezerwacja pamieci !!!" << endl;
			// reakcja na tê pora¿kê
			// ...
		
		}
	}
	// 3.
	// Wywo³anie zaproponowanej przez nas funkcji - funkcja set_new_handler
	
	set_new_handler(funkcja_alarmowa);
	try
	{
		for(k = 0; ; k++)
		{
			new int;
		}
	}
	catch(bad_alloc)
	{
		cout << "Zabraklo pamieci przy k = " << k << "!" << endl;
	}

	
}
//******************************************************************************************************
void funkcja_alarmowa()
{
	cout << "Zabraklo pamieci przy k = " << k << "!" << endl;
	exit(1);
	// throw bad_alloc();
}
