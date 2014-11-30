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

// zapis extern int m; jest tylko deklaracj¹, deklaracji tego samego obiektu mo¿e byæ wiele, definicja tylko jedna
// extern oznacza: deklaracja obiektu, który znajduje siê mo¿e w innym pliku, ale to nic pewnego
// poprawna jest deklaracja tego samego obiektu w pliku nag³ówkowym i jego definicja w pliku Ÿród³owym
// extern int ile_murzynow; w nagl.h
// int ile_murzynow; w afryka.cpp
// natomiast deklaracja w postaci extern int m = 4; uznana bêdzie jako definicja (w pliku nag³ówkowym i Ÿród³owym)