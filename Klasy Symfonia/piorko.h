/*
 * piorko.h
 *
 *  Created on: 17 mar 2015
 *      Author: xmef
 */

#ifndef PIORKO_H_
#define PIORKO_H_

#include "includy.h"

enum tak_czy_nie { nie, tak };



class piorko {
	int poz_x;
	int poz_y;
	static int zezwolenie;
	char kolor[30];

public:
	void jazda (int x, int y);
	static void czy_mozna(tak_czy_nie odp);
	piorko(const char* kol);
	~piorko();
};

#endif /* PIORKO_H_ */
