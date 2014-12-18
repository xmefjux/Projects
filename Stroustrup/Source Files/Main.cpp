/*
 * Main.cpp
 *
 *  Created on: 13 gru 2014
 *      Author: xmef
 */
#include <iostream>
#include <stdio.h>

#include <stdlib.h>
using namespace std;
// własności zależne od implementacji można znaleźć w nagłówku <limits>
#include <limits>
//******************************************************************************************************
extern void Vector();
//******************************************************************************************************
int main()
{
	try {
		//Vector();
		cout << "Najwieksza liczba zmiennopozycyjna == "
			 << numeric_limits<float>::max() << " , char jest ze znakiem == "
			 << numeric_limits<char>::is_signed << endl;
	}
	catch (...) {
		cerr << "zgloszono wyjatek" << endl; // cerr standardowy strumień błędów i diagnostyki
	}
}
