#include <iostream>
#include "nagl.h"

using namespace std;
inline int wiekszy(int a, int b)
{
	if(a > b)
		return a;
	else
		return b;
}
//****************************************************************************
void druga()
{
	cout << wieksza(1, 2) << endl;
	cout << wiekszy(80, 50) << endl;
}