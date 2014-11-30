#include <iostream>
using namespace std;

void wypisz(const double *x, int k);

void wypisz(const double *x, int k)
{
	for(int i = 0; i < k; i++, x++) cout << *x << " ";
	cout << endl;
}
