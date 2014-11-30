#include <iostream>
#include "nagl.h"

using namespace std;
//****************************************************************************
void f1(int n)
{
	n++;
}
//****************************************************************************
void f2(int &n)
{
	n++;
}
//****************************************************************************
void g()
{
	int liczba = 10;
	f1(liczba);
	cout << "Liczba = " << liczba << endl;

	f2(liczba);
	cout << "Liczba = " << liczba << endl;
}