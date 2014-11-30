#include <iostream>
#include "nagl.h"

using namespace std;

int ile_murzynow = 9;

//****************************************************************************
void main_afryka()
{
	cout << "Poczatek programu" << endl;
	funkcja_francuska();
	funkcja_niemiecka();
	cout << "Koniec programu" << endl;
}
//****************************************************************************
void funkcja_egipska()
{
	cout << "Jestem w Kairze! ----------" << endl;
	cout << "Na swiecie jest " << ile_murzynow << " murzynow, oraz "
		 << ile_europejczykow << " europejczykow" << endl;
}
//****************************************************************************
void funkcja_kenijska()
{
	cout << "Jestem w Nairobi! ---------" << endl;
	cout << "Na swiecie jest " << ile_murzynow << " murzynow, oraz "
		 << ile_europejczykow << " europejczykow" << endl;
}
//****************************************************************************

// zapis extern int m; jest tylko deklaracj�, deklaracji tego samego obiektu mo�e by� wiele, definicja tylko jedna
// extern oznacza: deklaracja obiektu, kt�ry znajduje si� mo�e w innym pliku, ale to nic pewnego
// poprawna jest deklaracja tego samego obiektu w pliku nag��wkowym i jego definicja w pliku �r�d�owym
// extern int ile_murzynow; w nagl.h
// int ile_murzynow; w afryka.cpp
// natomiast deklaracja w postaci extern int m = 4; uznana b�dzie jako definicja (w pliku nag��wkowym i �r�d�owym)