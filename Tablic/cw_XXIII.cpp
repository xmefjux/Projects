#include <iostream>

using namespace std;

void /*char**/ dolacz(char cel[], int size_cel, char zrodlo[]);
//************************************************************************************************
void main_cw_XXIII()
{
	char t1[40] = { "pierwszy bardzo dlugi string" };
	char t2[] = { "drugi string" };
	//cout << dolacz(t1, sizeof(t1), t2) << endl;
	dolacz(t1, sizeof(t1), t2);
	cout << t1 << endl;
}
//************************************************************************************************
void /*char**/ dolacz(char t1[], int size, char t2[])
{
	int find_null = 0;

	while(t1[find_null] != 0)
	{
		find_null++;
	}

	t1[find_null] = ' ';

	for(int i = find_null + 1, j = 0; i < size; i++, j++)
	{
		t1[i] = t2[j];
		if(i == (size - 1))
		{
			t1[i] = 0;			// jeœli skoñczy³ siê rozmiar pierwszej tablicy, a dalej mo¿na przepisywaæ, przerwij pêtle
			break;
		}
		else if(t1[i] == 0)
		{
			break;				// jeœli przepisano ca³y drugi string, a w pierwszej tablicy jest jeszcze miejsce, przerwij pêtle
		}
	}

	//return t1;
}
