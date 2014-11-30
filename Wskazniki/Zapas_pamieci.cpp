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
	// W sytuacji kiedy wyczerpiemy dost�pny obszar pami�ci, a chcemy utworzy� nowy obiekt, komputer mo�e nas o tym powiadomi� na 3 sposoby:
	// - zwrot adresu zero - (spos�b "dawny")
	// - rzucenie wyj�tku bad_alloc - (spos�b "nowoczesny")
	// - wywo�anie jakiej� zaproponowanej przez nas funkcji.

	// 1.
	// Zwrot adresu zero
	{
		double *wsk, *wsk1;
		wsk = new (nothrow) double[100000000];
		wsk1 = new (nothrow) double[100000000];
		if(!wsk1)
		{
			cout << "Rezerwacja nieudana" << endl;
			// tu reakcja na t� nieudan� rezerwacj�
			// ...
		}
		delete wsk; delete wsk1;
	}
	// 2.
	// Nowy spos�b: try{} catch{} - rzucanie i �apanie wyj�tku
	{
		double *wsk, *wsk1;
		try
		{
			wsk = new double[100000000];
			wsk1 = new double[100000000];
			// uda�o si�, pracujemy na takim obiekcie
			// ...
			// ...
		}
		catch(bad_alloc)
		{
			cout << "Przechwycona nieudana rezerwacja pamieci !!!" << endl;
			// reakcja na t� pora�k�
			// ...
		
		}
	}
	// 3.
	// Wywo�anie zaproponowanej przez nas funkcji - funkcja set_new_handler
	
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
