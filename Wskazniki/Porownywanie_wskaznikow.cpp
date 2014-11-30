#include <iostream>
#include <stdlib.h>

using namespace std;
//******************************************************************************************************
void porownywanie_wskaznikow()
{
	int *wsk1, *wsk2;
	int tab[10];

	for(int i = 0; i < 100; i++)
	{
		wsk1 = &tab[rand() % 10];
		wsk2 = &tab[rand() % 10];
		if(wsk1 == wsk2)
			cout << "oba wskazniki pokazuja na to samo!" << endl;
		else if(wsk1 != wsk2)
			cout << "wskazniki pokazuja na rozne obiekty" << endl;
	}

	int tablica[5];
	int *wsk_czer, *wsk_ziel;
	int i;
	
	wsk_czer = &tablica[rand() % 5]; // = tablica + 3
	cout << "Mamy piecioelementowa tablice" << endl
		 << "Wskaznik czerwony pokazuje na element o indeksie "<< (wsk_czer - tablica) << endl
		 << "Na ktory element ma pokazywac wskaznik zielony? (0 - 4): ";
	cin >> i;
	
	if(i < 0 || i > 4)
		cout << "Nie ma takiego elementu tablicy!" << endl;
	else
	{
		wsk_ziel = &tablica[i];
		cout << "Z przeprowadzonego porownania wskaznikow" << endl
			 << "czerwonego z zielonym wynika, ze:" << endl;

		// w�a�ciwa akcja por�wnania...

		if(wsk_czer > wsk_ziel)
			cout << "zielony pokazuje na element blizej poczatku tablicy." << endl;
		else if(wsk_czer < wsk_ziel)
			cout << "zielony pokazuje na element o wyzszym indeksie" << endl;
		else
			cout << "zielony i czerwony pokazuja na to samo" << endl;
	}

	// ---------- Wska�nik mo�na por�wna� z adresem 0 (zero)
	// Ka�dy wska�nik mo�e pokazywa� na adres 0. W ten spos�b zaznaczamy, �e wska�nik nie pokazuje na nic sensownego.

	int *wsk = 0; // = NULL;

	if(wsk == 0)
		cout << "Wskaznik nie pokazuje na nic sensownego!" << endl;
	if(!wsk)
		cout << "Wskaznik nie ustawiony!" << endl;

}
