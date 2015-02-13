/*
 * Main.cpp
 *
 *  Created on: 13 gru 2014
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
// własności zależne od implementacji można znaleźć w nagłówku <limits>
#include <limits>
//******************************************************************************************************
extern void Vector();
// -------------------------------------------------
extern void Deklaracje();
extern void Wskazniki();
extern double& wartoscc(const string& s);
extern void wykonaj();

//******************************************************************************************************
int main()
{
	string t[] = { "napis1", "napis2" };
	string *ps = t;
	cout << ps[0] << endl;
	try {
		//Vector();
		//Deklaracje();
		//Wskazniki();
		//wykonaj();
	}
	catch (...) {
		cerr << "zgloszono wyjatek" << endl; // cerr standardowy strumień błędów i diagnostyki
	}
}

