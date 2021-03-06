/*
 * gadula.h
 *
 *  Created on: 17 mar 2015
 *      Author: xmef
 */

#ifndef GADULA_H_
#define GADULA_H_

#include "includy.h"

// przykładowa klasa z użyciem destruktora
// tak samo jak konstruktor, destruktor jest wywoływany zawsze, automatycznie, tuż przed zniszczeniem obiektu
// konstruktor i destruktor są wywoływane zawsze, nawet jeśli ich sami nie zdefiniujemy
// przy samodzielnej definicji po prostu wykonają to o co ich poprosimy przed konstrukcją i destrukcją obiektu

class gadula {
	int licz;
	char tekst[40];
public:
	gadula(int k, const char* opis);
	~gadula(void);

	void fff(int);
	void fff(int, int);

	int zwracaj() { return licz; }
	void schowaj(int x) {licz = x; }
	void coto() { cout << tekst << " ma wartosc " << licz << endl; }

	static const int zmienna = 5;
};

#endif /* GADULA_H_ */
