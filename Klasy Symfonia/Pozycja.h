/*
 * Pozycja.h
 *
 *  Created on: 20 mar 2015
 *      Author: xmef
 */

#ifndef POZYCJA_H_
#define POZYCJA_H_

#include "includy.h"

class Pozycja {
private:
	int x;
	int y;
public:
	Pozycja(int a, int b);
	~Pozycja();

	void wypis() const volatile;
	void przesun(int a, int b);
};

#endif /* POZYCJA_H_ */
