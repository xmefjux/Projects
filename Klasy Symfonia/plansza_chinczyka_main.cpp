/*
 * plansza_chinczyka_main.cpp
 *
 *  Created on: 17 mar 2015
 *      Author: xmef
 */
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cstring>
using namespace std;
#include "planszachinczyka.h"
//***************************************************************************************
void wydrukuj_z_referencji(const int &ref)
{
	cout << "(wydruk z referencji) wartosc: " << ref << endl;
}
//***************************************************************************************
void wydrukuj_ze_wskaznika(const int* wsk)
{
	cout << "(wydruk za pom. wskaznika) wartosc: " << *wsk << endl;
}
//***************************************************************************************
void plansza_chinczyka_main()
{
	// plansza_chinczyka klubowa;  --- nie musimy mieć obiektów

	cout << "Zanim zagramy, pytamy ile max graczy "
		 << plansza_chinczyka::max_graczy
		 << ", pol = " << plansza_chinczyka::ile_pol
		 << ", kolorow = " << plansza_chinczyka::ile_kolorow
		 << endl;

	cout << "Adres stalej plansza_chinczyka::ile_kolorow = "
		 << &plansza_chinczyka::ile_kolorow << endl;

	wydrukuj_z_referencji(plansza_chinczyka::ile_kolorow);
	wydrukuj_ze_wskaznika(&plansza_chinczyka::ile_kolorow);

	//===============================================================================
	// w stosunku do typu wyliczeniowego poniższe instrukcje są niemożliwe
	//cout << "Adres stalej plansza_chinczyka::max_pionow =_"
	//	 << plansza_chinczyka::max_pionow << endl;
	//wydrukuj_z_referencji(plansza_chinczyka::max_pionow);

	//===============================================================================
	// składnik statyczny bez odrębnej definicji - ma te same wady co enum
	//cout << "Adres stalej plansza_chinczyka::ile_pol = "
	//	 << plansza_chinczyka::ile_pol << endl;
	//wydrukuj_z_referencji(plansza_chinczyka::ile_pol);
}
