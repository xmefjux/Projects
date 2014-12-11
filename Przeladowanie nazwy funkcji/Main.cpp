/*
 * Main.cpp
 *
 *  Created on: 6 gru 2014
 *      Author: xmef
 */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
//******************************************************************************************************
extern void Przyklad_1();
extern void Przeladowanie_a_zakres_waznosci();
extern void Wysylanie_do_funkcji_adresu_innej_przeladowanej_funkcji();

double * f(char*);
double g(int, double);
char * h(char*);
//char * (*x)char* z(double *(*y)(char*), double (*w)(int, double));

//******************************************************************************************************
int main()
{
	//Przyklad_1();
	//Przeladowanie_a_zakres_waznosci();
	Wysylanie_do_funkcji_adresu_innej_przeladowanej_funkcji();
}
//******************************************************************************************************
// ćw. XII
// p jest funkcją wywoływaną z dwoma argumentami:
// pierwszy będący wskaźnikiem do funkcji wywoływanej z jednym argumentem typu char *, a zwracającej wskaźnik do typu char
// drugi będący wskaźnikiem do funkcji wywoływanej z dwoma argumentami typu int i double, a zwracającej wskaźnik do typu double
// a funkcja p zwraca: wskaźnik do funkcji wywoływanej z jednym argumentem typu char *, a zwracającej wskaźnik do typu char.
char (* ( *p (double (* (*x)(char*)), double (*y)(int, double)) ) (char*))
{
	return 0;
}
//******************************************************************************************************
