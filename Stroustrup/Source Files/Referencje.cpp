/*
 * Referencje.cpp
 *
 *  Created on: 13 lut 2015
 *      Author: xmef
 */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <list>
#include <complex>
#include <algorithm>
#include "header.h"
using namespace std;
//******************************************************************************************************
struct Paraa {
	string nazwa;
	double wart;
};
vector<Paraa> paryy;
void wykonaj();
//******************************************************************************************************
double& wartoscc(const string& s)
/*
 * utrzymuj zbiór par:
 * szukaj s; jeśli jest, to przekaż jego wartość, jeśli nie ma,
 * to utwórz nową parę i przekaż domyślną wartość 0
 */
{
	for(unsigned int i = 0; i < paryy.size(); i++)
	{
		if(s == paryy[i].nazwa) return paryy[i].wart;
	}
	Paraa p = { s, 0 };
	paryy.push_back(p); // dodaj parę na końcu
	return paryy[paryy.size() - 1].wart;
}
//******************************************************************************************************
void wykonaj()
{
	string buf;
			while (cin >> buf && buf != "x") wartoscc(buf)++;

			for(vector<Paraa>::const_iterator p = paryy.begin(); p != paryy.end(); ++p)
				cout << p-> nazwa << ": " << p-> wart << endl;
}
