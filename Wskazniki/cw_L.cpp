#include <iostream>
#include <string.h>
using namespace std;
//************************************************************************************************
void sklej(char *t1, int size, char *t2);
//************************************************************************************************
char * L(char * x, int size)
{
	char uwaga[8] = { "UWAGA: " };

	char *tab = new char[size];

	strncpy(tab, uwaga, size);

	sklej(tab, size, x);

	strncpy(x, tab, size);
	
	delete [] tab;
	
	return x;
}
//************************************************************************************************
void sklej(char *t1, int size, char *t2) // funkcja sklejaj�ca, parametry: tablica docelowa, rozmiar tablicy docelowej, tablica �r�d�owa
{
	int find_null = 0;

	while(t1[find_null] != 0)
	{
		find_null++;
	}

	//t1[find_null] = ' ';

	for(int i = find_null/* + 1*/, j = 0; i < size; i++, j++)
	{
		t1[i] = t2[j];
		if(i == (size - 1))
		{
			t1[i] = 0;			// je�li sko�czy� si� rozmiar pierwszej tablicy, a dalej mo�na przepisywa�, przerwij p�tle
			for(int k = 0; k < 3; k++) 
				t1[--i] = '.';
			break;
		}
		else if((t1[i] == 0))
		{
			break;				// je�li przepisano ca�y drugi string, a w pierwszej tablicy jest jeszcze miejsce, przerwij p�tle
		}
	}

} // end f. sklej
//************************************************************************************************
