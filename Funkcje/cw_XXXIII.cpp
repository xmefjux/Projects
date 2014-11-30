#include <iostream>

using namespace std;
//****************************************************************************
void f()
{
	static int licznik = 1;
	cout << licznik;
	if(!(licznik % 12))
		cout << " Nowy tuzin";
	licznik++;
	cout << endl;
}