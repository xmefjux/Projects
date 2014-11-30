#include <iostream>

using namespace std;
//******************************************************************************************************
void funkcja_wska(int *wsk, int rozmiar);
void funkcja_tabl(int tab[], int rozmiar);
void funkcja_wsk2(int *wsk, int rozmiar);
//******************************************************************************************************
void odbieranie_tablicy()
{
	int tafla[4] = { 5, 10, 15, 20 };
	funkcja_tabl(tafla, 4);
	funkcja_wska(tafla, 4);
	funkcja_wsk2(tafla, 4);
	cout << endl;
}
//******************************************************************************************************
void funkcja_tabl(int tab[], int rozmiar)
{
	cout << "Wewnatrz funkcja_tabl" << endl;
	for(int i = 0; i < rozmiar; i++)
	{
		cout << tab[i] << "\t";
	}
}
//******************************************************************************************************
void funkcja_wska(int *wsk, int rozmiar)
{
	cout << endl << "Wewnatrz funkcja_wska" << endl;
	for(int i = 0; i < rozmiar; i++)
	{
		cout << *(wsk++) << "\t";
	}
}
//******************************************************************************************************
void funkcja_wsk2(int *wsk, int rozmiar)
{
	cout << endl << "Wewnatrz funkcja_wsk2" << endl;
	for(int i = 0; i < rozmiar; i++)
	{
		cout << wsk[i] << "\t";
	}
}
//******************************************************************************************************