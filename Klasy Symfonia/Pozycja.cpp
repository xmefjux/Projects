/*
 * Pozycja.cpp
 *
 *  Created on: 20 mar 2015
 *      Author: xmef
 */

#include "includy.h"
#include "Pozycja.h"

Pozycja::Pozycja(int a, int b) {
	// TODO Auto-generated constructor stub
	x = a;
	y = b;
}

Pozycja::~Pozycja() {
	// TODO Auto-generated destructor stub
}

void Pozycja::wypis() const volatile
{
	cout << x << ", " << y << endl;
}

void Pozycja::przesun(int a, int b)
{
	x = a;
	y = b;
}
