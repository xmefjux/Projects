#include <iostream>
#include <new>

using namespace std;
//******************************************************************************************************

// Przyk³ad jak operator new mo¿e nie rezerwowaæ pamiêci, jeœli podamy mu miejsce, które nale¿y ju¿ donas - wówczas jedynie wybuduje on na danym miejscu ¿¹dany obiekt.

void Umiejscawiajacy_operator_new()
{
	// Wstêpna rezerwacja du¿ego obszaru pamiêci (czyli kupujemy grunt na osiedle domów)
	int *osiedle = new int[5000];
	// Niwelowanie zdobytego w³aœnie obszaru (inicjalizacja poszczególnych komórek - usuwanie œmieci)
	for(int i = 0; i < 5000; i++) 
		osiedle[i] = 1;
	// Teraz na tym terenie mo¿emy tworzyæ nowe obiekty
	// umieszczenie nowego obiektu
	void *gdzie = &osiedle[100];		// wkaŸnik jest typu void, bo ma tylko pokazywaæ na dane miejsce
	int *wskint = new (gdzie) int;

	// praca z tym obiektem
	*wskint = 222;
	cout << "*wskint = " << (*wskint) << endl;

	// --------------
	gdzie = &osiedle[102];
	int *wTabi = new (gdzie) int[3];

	// praca z t¹ tablic¹
	for(int m = 0; m < 3; m++)
	{
		wTabi[m] = 1000 + m;
		cout << "wTabi[" << m << "] = " << wTabi[m] << " ";
	}
	cout << endl;
	// ---------------
	gdzie = &osiedle[106];
	double *wTabd = new (gdzie) double[3];
	
	// praca z t¹ tablic¹
	for(int n = 0; n < 3; n++)
	{
		wTabd[n] = 1 + (0.1 * n);
		cout << "wTabd[" << n << "] = " << wTabd[n] << " ";
	}
	cout << endl;

	// w miejscu o adresie podawanym liczbowo
	cout << "Napisz jakis adres pomiedzy: "
		 << reinterpret_cast<int>(&osiedle[112])
		 << " - "
		 << reinterpret_cast<int>(&osiedle[116])
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

	// po co to u¿ywaæ:
	// Czas zu¿yty na ci¹g³e rezerwacje i zwalnianie pamiêci mo¿e byæ wtedy znacz¹cy. Lepiej wtedy zrobiæ to raz, hurtowo.
}
