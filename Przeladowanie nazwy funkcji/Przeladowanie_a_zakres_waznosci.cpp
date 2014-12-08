/*
 * Przeladowanie_a_zakres_waznosci.cpp
 *
 *  Created on: 8 gru 2014
 *      Author: xmef
 */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
//******************************************************************************************************
extern void dzwiek(int a);
//******************************************************************************************************
void Przeladowanie_a_zakres_waznosci()
{
	dzwiek(1);
	{
		// w tym miejscu nie dochodzi do przeładowania, a do zasłonięcia nazwy
		extern void dzwiek(double);
		dzwiek(2);
		dzwiek(3.14);
	}
	dzwiek(5);
	dzwiek(6.28);
}
//******************************************************************************************************
// Aby rzeczywiście mieć obie funkcje o tej samej nazwie (przeładowane) muszą one mieć identyczny zakres ważności.
