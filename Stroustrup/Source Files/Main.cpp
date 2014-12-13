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
//******************************************************************************************************
extern void Vector();
//******************************************************************************************************
int main()
{
	try {
		//Vector();
	}
	catch (...) {
		cerr << "zgloszono wyjatek" << endl; // cerr standardowy strumień błędów i diagnostyki
	}
}
