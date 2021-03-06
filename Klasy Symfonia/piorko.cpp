/*
 * piorko.cpp
 *
 *  Created on: 17 mar 2015
 *      Author: xmef
 */

#include "piorko.h"

// wewnątrz funkcji składowej statycznej nie jest możliwe jawne odwołanie się do wskaźnika this
// nie jest też możliwe odwołanie się do jakiegoś nie-statycznego składnika tej klasy. to dlatego, że dana będąca składnikiem klasy
// ma zawsze przed sobą niewidoczny wskaźnik this

// funkcja statyczna klasy nie dotyczy konkretnego obiektu, a raczej całej klasy tych obiektów

// klasa paszport ma konkretne imie i nazwisko dla każdego obiektu, ale np. godło w paszporcie jest takie samo dla każdego paszportu
// więc nie ma sensu dla każdego obiektu rezerwować pamięć dla godła, wystarczy jeden obiekt statyczny godło dla każdego obiektu

// funkcje statyczną można wywołać nawet wtedy gdy nie istnieje żaden obiekt danej klasy

// funkcja statyczna to tak jakby zwykła funkcja (nie trzeba jej wywoływać na rzecz obiektu), ale ma zakres ważności klasy,
// więc ma dostęp do jej prywatnych składników

/*
 * do czego może się przydać składnik statyczny w klasie
 * - przydaje się, gdy egzemplarze obiektów danej klasy mają porozumiewać się ze sobą
 * - gdy wszystkie obiekty mają tę samą cechę, która może się zmieniać
 * - może to być zmienna określająca ile obiektów danej klasy już istnieje
 * - może też służyć do tego, żeby wszystkie obiekty danej klasy mogły korzystać z jednego pliku dyskowego
 *   składnim statycznym jest wtedy kanał transmisji (strumień) do pliku
 * - składnik statyczny może zaoszczędzić miejsca, jedna cecha wspólna dla wszystkich obiektów w pamięci wystąpi tylko raz
 *
 */

int piorko::zezwolenie;

piorko::piorko(const char* kol) {
	// TODO Auto-generated constructor stub
	strcpy(kolor, (kol ? kol : ""));
	poz_x = poz_y = 0;
}

piorko::~piorko() {
	// TODO Auto-generated destructor stub
}

void piorko::jazda (int x, int y)
{
	cout << "Tu " << kolor << " piorko: ";
	if(zezwolenie)
	{
		poz_x = x;
		poz_y = y;
		cout << "Jade do punktu (" << poz_x << ", " << poz_y << ")\n";
	}
	else
	{
		cout << "Nie wolno mi jechac !\n";
	}
}
void piorko::czy_mozna(tak_czy_nie odp)
{
	zezwolenie = odp;
	//poz_x = 5; -- zwykły składnik nie może być w statycznej funkcji
}
