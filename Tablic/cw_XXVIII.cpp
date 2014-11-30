#include <iostream>

using namespace std;

//************************************************************************************************
void main_cw_XXVIII(double t[][5][30], int a, int b, int c)
{
	for(int i = 0; i < a; i++)
	{
		for(int j = 0; j < b; j++)
		{
			for(int k = 0; k < c; k++)
			{
				t[i][j][k] = 0;
				cout << t[i][j][k] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
}
