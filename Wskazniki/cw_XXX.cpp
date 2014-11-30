#include <iostream>
using namespace std;

void dodaj(int x[], int i);

void dodaj(int x[], int i)
{
	for(int k = 0; k < i; k++) x[k] += 44;
}
