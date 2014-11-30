#include <iostream>
#include "Definicje.h"
#include <stdlib.h>

using namespace std;

//void funkcja(float t[ ]) {}
//float tablica[] = { 7, 8.12, 4, 4.12 };

void potrojenie(int ile, long t[ ]);
void main_Tablica_enum();
void main_Tablice_znakowe();
void main_Tablice_wielowymiarowe();
void main_cw_XVII();
void main_cw_XVIII();
void main_cw_XXIII();
void main_cw_XXVI();
void main_cw_XXVIII(double t[][5][30], int a, int b, int c);
void main_cw_XXIX();
//************************************************************************************************
int main()
{
	/*int t[4];
	for(int i = 0; i < 4; i++)
	{
		t[i] = 100 * i;
	}
	cout << "Wydruk tresci tablicy: " << endl;
	for(int i = 0; i < 4; i++)
	{
		cout << "Element nr: " << i << " ma wartosc " << t[i] << endl;
	}

	// wywo�anie funkcji z tablic� jako argument
	//funkcja(tablica); // NAZWA TABLICY jest r�wnocze�nie ZDRESEM ZEROWOEGO JEJ ELEMENTU
	
	const int rozmiar = 8192;
	long widmo[rozmiar];
	//------ nadanie warto�ci pocz�tkowej
	for(int i = 0; i < rozmiar; i ++)
	{
		widmo[i] = i;
		if(i < 6)		// pokazanie pierwszych sze�ciu
			cout << "widmo[" << i << "] = " << widmo[i] << endl; 
	}
	// --------- uwaga, wywo�ujemy funkcj�!
	potrojenie(rozmiar, widmo);
	cout << "Po wywolaniu funkcji" << endl;
	for(int i = 0; i < 4; i++)
	{
		cout << "widmo[" << i << "] = " << widmo[i] << endl; 
	}*/

	//main_Tablica_enum();
	//main_Tablice_znakowe();
	//main_Tablice_wielowymiarowe();

	
	
	//// cw_II
	//int a  = 1;
	//unsigned int b = 2;
	//int tx[2];
	//tx[0] = a;
	//tx[1] = b;
	//// nast�pi niejawna konwersja na typ int

	// cw_V
	//const int x = 10;
	//int w[x];

	// cw_VIII
	enum ruch { w_przod, w_tyl, stop };
	ruch t_ruch[15] = { w_przod, w_tyl, stop, stop, w_tyl };

	// cw_XI
	char cw_xi[14] = { "programowanie" };
	// cw_XII
	char cw_xii[3] = { 'x', 'y', 'z' };

	char tab1[4] = { "1,2" };

	// cw_XVI
	char tabl[10] = { "ABCD" };
	tabl[6] = 'm';
	//tabl[10] = { "GGGG" };
	//tabl[0] = { "GGGG" };
	//tabl[5] = "a";
	//tabl[] = 'a';
	//tabl = '7';
	//tabl = "7";

	// cw_XVII
	//main_cw_XVII();

	// cw_XVIII
	//main_cw_XVIII();

	// cw_XXI
	/*char a1 [] = "Litwo, ojczyzno moja";
	char a2 [] = "ABC";
	char a3 [] = "123456789012345678901234567890";

	for(int i = 0; i <= sizeof(a1); i++)
	{
		a2[i] = a1[i];
	}
	for(int i = 0; i <= sizeof(a1); i++)
	{
		a3[i] = a1[i];
	}
	cout << a1 << endl << a2 << endl << a3 << endl;*/

	// cw_XXIII
	//main_cw_XXIII();

	// cw_XXVI
	//main_cw_XXVI();

	// cw_XXVII
	double tab[10][5][30];
	/*cout << tab << endl;
	cout << &tab[0][0][0] << endl;
	cout << tab[1] << endl;
	cout << &tab[1][0][0] << endl;
	cout << tab[6][4] << endl;
	cout << &tab[6][4][0] << endl;*/

	// cw_XXVIII
	//main_cw_XXVIII(tab, 10, 5, 30);

	//enum { zero, jeden, dwa };

	// cw_XXIX
	main_cw_XXIX();

	//system("pause");
}
//****************************************************************************************************************
void potrojenie(int ile, long t[ ])
{
	for(int i = 0; i < ile; i++)
	{
		t[i] *= 3;
	}
}
