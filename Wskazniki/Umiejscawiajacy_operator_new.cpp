#include <iostream>
#include <new>

using namespace std;
//******************************************************************************************************

// Przyk�ad jak operator new mo�e nie rezerwowa� pami�ci, je�li podamy mu miejsce, kt�re nale�y ju� donas - w�wczas jedynie wybuduje on na danym miejscu ��dany obiekt.

void Umiejscawiajacy_operator_new()
{
	// Wst�pna rezerwacja du�ego obszaru pami�ci (czyli kupujemy grunt na osiedle dom�w)
	int *osiedle = new int[5000];
	// Niwelowanie zdobytego w�a�nie obszaru (inicjalizacja poszczeg�lnych kom�rek - usuwanie �mieci)
	for(int i = 0; i < 5000; i++) 
		osiedle[i] = 1;
	// Teraz na tym terenie mo�emy tworzy� nowe obiekty
	// umieszczenie nowego obiektu
	void *gdzie = &osiedle[100];		// wka�nik jest typu void, bo ma tylko pokazywa� na dane miejsce
	int *wskint = new (gdzie) int;

	// praca z tym obiektem
	*wskint = 222;
	cout << "*wskint = " << (*wskint) << endl;

	// --------------
	gdzie = &osiedle[102];
	int *wTabi = new (gdzie) int[3];

	// praca z t� tablic�
	for(int m = 0; m < 3; m++)
	{
		wTabi[m] = 1000 + m;
		cout << "wTabi[" << m << "] = " << wTabi[m] << " ";
	}
	cout << endl;
	// ---------------
	gdzie = &osiedle[106];
	double *wTabd = new (gdzie) double[3];
	
	// praca z t� tablic�
	for(int n = 0; n < 3; n++)
	{
		wTabd[n] = 1 + (0.1 * n);
		cout << "wTabd[" << n << "] = " << wTabd[n] << " ";
	}
	cout << endl;

	// w miejscu o adresie podawanym liczbowo
	cout << "Napisz jakis adres pomiedzy: "
		 << reinterpret_cast<int*>(&osiedle[112])
		 << " - "
		 << reinterpret_cast<int*>(&osiedle[116])
		 << endl << "a ja tam zbuduje Ci obiekt: ";
	int adres;
	cin >> adres;
	gdzie = reinterpret_cast<void*>(adres);
	int *wskA = new (gdzie) int;

	// praca z tym obiektem
	*wskA = 114;
	cout << "Wartosc = " << (*wskA) << endl;

	// ----------
	cout << "Zobaczmy na te dzialke" << endl;
	for(int k = 99; k < 116; k++)
	{
		cout << "[" << k << "] = " << osiedle[k] << endl;
	}

	delete [] osiedle;

	// po co to u�ywa�:
	// Czas zu�yty na ci�g�e rezerwacje i zwalnianie pami�ci mo�e by� wtedy znacz�cy. Lepiej wtedy zrobi� to raz, hurtowo.
}
