/*
 * Wskazniki.cpp
 *
 *  Created on: 19 gru 2014
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
using namespace std;
//******************************************************************************************************
struct Para {
	string nazwa;
	double wart;
};
vector<Para> pary;
//******************************************************************************************************
double& wartosc(const string& s)
{
	for(unsigned int i = 0; i < pary.size(); i++)
	{
		if(s == pary[i].nazwa) return pary[i].wart;
	}
	Para p = { s, 0 };
	pary.push_back(p); // dodaj parę na końcu

	return pary[pary.size() - 1].wart;
}
//******************************************************************************************************
void Wskazniki()
{
		string buf = "1";
		while (buf != "0")
		{
			cin >> buf;
			wartosc(buf)++;
		}

		for(vector<Para>::const_iterator p = pary.begin(); p != pary.end(); ++p)
		{
			cout << p->nazwa << ": " << p->wart << endl;
		}
}
