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
using namespace std;
// własności zależne od implementacji można znaleźć w nagłówku <limits>
#include <limits>
//******************************************************************************************************
extern void Vector();
// -------------------------------------------------
extern void Deklaracje();
extern void Wskazniki();
//******************************************************************************************************
int main()
{
	try {
		//Vector();
		Deklaracje();
		Wskazniki();
	}
	catch (...) {
		cerr << "zgloszono wyjatek" << endl; // cerr standardowy strumień błędów i diagnostyki
	}
}
