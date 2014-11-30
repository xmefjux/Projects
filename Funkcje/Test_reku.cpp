#include <iostream>

using namespace std;

void f(int kroki);
double ff();
//***************************************************************************

void main_test_reku()
{
	int x;
	cin >> x;
	f(x);
	cout << ff() << endl;
}
//***************************************************************************
void f(int kroki)
{
	if(kroki)
	{
		cout << "Krok w srodku nr: " << kroki << endl;
		f(kroki-1);
	}
	else
	{
		cout << "Ostatni krok" << endl;
	}
	cout << "Poza ifem krok nr: " << kroki << endl;
}
double ff()
{
	return 4.5;
}