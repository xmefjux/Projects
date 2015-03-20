/*
 * gadula_main.cpp
 *
 *  Created on: 17 mar 2015
 *      Author: xmef
 */
#include "includy.h"

#include "gadula.h"

// po wywołaniu tej funkcji obiekt globalny a zostanie "zniszczony" dwukrotnie
// ponieważ jawne (przez nas) wywołanie destruktora nie powoduje zniszczenia obiektu, tylko wywoła "sprzątanie"
// na końcu programu obiekt a zostanie zniszczony, pomimo tego, że sami wywołaliśmy destruktor
// jawne wywołanie destruktora jest potrzebne po to, żeby przed zniszczeniem obiektu posprzątać śmieci
// np. jeśli obiekt w czasie swojego istnienia dokonał jakiejś rezerwacji pamięci to należy tą pamięć zwolnić, najlepiej w destruktorze


gadula a(1, "obiekt a (GLOBALNY)");
gadula b(2, "obiekt b (GLOBALNY)");

void gadula_main()
{
	a.coto();
	b.coto();
	{
		cout << "Poczatek lokalnego zakresu -----------\n";
		gadula c(30, "obiekt c (lokalny)");
		gadula a(40, "obiekt a (lokalny)");

		cout << "\nCo teraz mamy: \n";
		a.coto();
		b.coto();
		c.coto();

		cout << "Do zaslonietego obiektu globalnego mozna sie jendak dostac\n";
		::a.coto();
		cout << "Konczy sie lokalny zakres ------------\n";
	}
	cout << "juz jestesmy poza blokiem\n";
	a.coto();
	b.coto();
	cout << "Sam uruchamiam destruktor obiektu a\n";
	a.~gadula();
	cout << "Koniec programu\n";
}
