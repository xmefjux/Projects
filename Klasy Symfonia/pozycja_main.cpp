/*
 * pozycja_main.cpp
 *
 *  Created on: 20 mar 2015
 *      Author: xmef
 */
#include "includy.h"
#include "Pozycja.h"

// funkcja składowa z przydomkiem const obiecuje, że jeśli się ją wywoła na rzecz jakiegoś obiektu
// nie będzie ona modyfikowała jego danych składowych
// Ważne w sytuacji kiedy chcemy definiować stałe obiekty danej klasy

// składnia funkcji volatile jest identyczna z const (podmienić słówko const na volatile)

// funkcja może być jednocześnie const i volatile

// wskaźnik this wewnątrz takich funkcji jest typu const lub volatile lub const volatile

// jeśli funkcje z tymi przydomkami są przeładowane to kompilator odrzuca wszystkie funkcje nie-const jeśli wywołanie było
// na rzecz obiektu const

void pozycja_main()
{
	Pozycja samochod(40, 50);
	Pozycja pies(30, 80);

	const Pozycja dom(50, 50);

	// zastosowanie funkcji składowej const

	samochod.wypis();
	pies.wypis();
	dom.wypis();

	// zastosowanie funkcji nie-const

	samochod.przesun(4, 10);
	pies.przesun(50, 50);
	// dom.przesun(0, 0);

	samochod.wypis();
	pies.wypis();
	dom.wypis();
}
