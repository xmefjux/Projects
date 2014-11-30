#include <iostream>
using namespace std;
#include <stdio.h>

//void umiesc(

void szachownica()
{
	// rezerwacja obszaru pami�ci
	char *szachownica = new char[8*8*sizeof(long)];
	// ustawienie wska�nika na ten obszar
	long *ptr_long = new (szachownica) long;
	// tablica figury
	//long *figury[]

	cout << "Na jakim polu szachownicy mam umie�ci� nowy obiekt typu long? Podaj symbol literowy: ";
	getchar();
	cout << "Podaj symbol cyfrowy: "; getchar();

}
