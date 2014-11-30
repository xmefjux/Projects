#include <iostream>

using namespace std;

#include <cstdlib>		// dla exit
#include <cmath>		// dla sinus
//******************************************************************************************************
void kurs();
void wiatraczek();
void wahadlo();
void zwloka_czasowa(int ile)
{
	for(int i = 0; i < ile * 1000; i++);
}

//******************************************************************************************************
void Tablica_wskaznikow_do_funkcji()
{
	void (*twf[3])() = {	&wahadlo,
							&wiatraczek,
							&kurs};
	int co;
	while(1)
	{
		cout << "-------------- Menu -------------" << endl
			 << "\t0 - wahadlo" << endl
			 << "\t1 - wiatraczek" << endl
			 << "\t2 - kurs" << endl
			 << "\t9 - koniec programu" << endl
			 << "Podaj numer zadanej akcji: ";
		cin >> co;

		switch(co)
		{
		case 0:
		case 1:
		case 2:
			(*twf[co])(); // twf[co]();
			break;

		case 9:
			exit(1);

		default:
			break;
		}

	}

}
//******************************************************************************************************
void kurs()
{
	for(int i = 0; i < 100; i++)
	{
		cout << "kurs "
			 << (232 + (i % 4))
			 << "...\r";
		zwloka_czasowa(50000);
	}
	cout << endl << "Pokazywalem kurs..." << endl;

}
//******************************************************************************************************
void wiatraczek()
{
	char symbol[] = { '|', '/', '-', '\\' };

	for (int i = 0; i < 100; i++)
	{
		cout << "		" << symbol[i % 4] << "\r";
		zwloka_czasowa(10000);
	}
	cout << endl << "Wiatraczek sie pokrecil..." << endl;

}
//******************************************************************************************************
void wahadlo()
{
	cout << '\n';

	char wzorek[25];
	for(int i = 0; i < 500; i++)
	{
		// przygotowanie tablicy spacji
		for(int k = 0; k < 25; k++) wzorek[k] = ' ';
		wzorek[24] = 0; // koñcz¹cy C-string znak null

		// wstawienie w jeden z elementów znaczka '*'
		int pozycja = 12 * sin(i / 20.0) + 12;
		wzorek[pozycja] = '*';

		// wydruk na ekran, a potem powrót karetki do pocz¹tku linijki
		cout << wzorek << '\r';
		zwloka_czasowa(5000);
	}
	cout << endl;

}
//******************************************************************************************************