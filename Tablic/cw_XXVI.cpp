#include <iostream>

using namespace std;

#define WIERSZE 10
#define KOLUMNY 3

//************************************************************************************************
void main_cw_XXVI()
{
	int t[WIERSZE][KOLUMNY];
	for(int i = 0; i < WIERSZE; i++)
	{
		for(int j = 0; j < KOLUMNY; j++)
		{
			if(j == 0)
			{
				t[i][j] = (i + 1);
				cout << t[i][j] << " ";
			}
			else if(j == 1)
			{
				t[i][j] = (i + 1) * (i + 1);
				cout << t[i][j] << " ";
			}
			else /*if(j == 2)*/
			{
				t[i][j] = (i + 1) * (i + 1) * (i + 1);
				cout << t[i][j];
			}
		}
		cout << endl;
	}
}
