#include <iostream>
#include "nagl.h"

using namespace std;

double y = 8.8;
double x = 1.1; // po poprawce
//****************************************************************************
void fun(int a = 2, double b = 3.5)
{
}
void main_cw_XXV()
{
	int zero = 0;
	//double x = 1.1; // zmienna lokalna nie mo¿e byæ argumentem domniemanym funkcji
	//double a = 1.0;
	fun(1, 6.6);
	fun();
	//fun(2, a);
	{
		void fun(int a = -1, double b = y);
		fun();
		if(2 > zero)
		{
			void fun(int a, double b = x);
			fun(zero);
		}
	}
}
