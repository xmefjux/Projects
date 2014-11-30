#include <iostream>

using namespace std;

//************************************************************************************************
void main_cw_XVII()
{
	char t1[20] = { "instytut" };
	char t2[20];
	for(int i = 0, j = 0; i < 21; i+=2, j++)
	{
		t2[j] = t1[i];
	}

	cout << t2 << endl;

}
