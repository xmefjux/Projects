/*
 * pion.h
 *
 *  Created on: 17 mar 2015
 *      Author: xmef
 */

#ifndef PION_H_
#define PION_H_

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cstring>
using namespace std;

class pion {
private:
	int pozycja;
	static int pensja;
public:
	static int ile_pionkow;

	pion();
	~pion();

	int przesun(int ile)
	{
		return (pozycja += ile);
	}
	int ile_zarabia()
	{
		return pensja - 800;
	}
};

#endif /* PION_H_ */
