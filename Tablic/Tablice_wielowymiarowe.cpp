#include <iostream>

using namespace std;

void wypelnij(long t[][2048]);
//************************************************************************************************
void main_Tablice_wielowymiarowe()
{
	static long widmo[4][2048];
	wypelnij(widmo);

	cout << "Jaki przedzial: ";
	int pocz, koniec;
	cin >> pocz >> koniec;

	for(int pomiar = 0; pomiar < 4; pomiar++)
	{
		long suma = 0;

		for(int i = pocz; i <= koniec; i++)
		{
			suma += widmo[pomiar][i];
		}
		cout << "W probce: " << pomiar 
			 << "miedzy: " << pocz << ", " << koniec
			 << " jest suma: " << suma << endl;
	}

}
//************************************************************************************************
void wypelnij(long t[][2048])
{
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 2048; j++)
		{
			t[i][j] = j;
		}

	}

}
