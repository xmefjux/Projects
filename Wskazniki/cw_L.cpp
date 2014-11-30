#include <iostream>
using namespace std;
//************************************************************************************************
void sklej(char *t1, int size, char *t2);
//************************************************************************************************
char * L(char * x, int size)
{
	char uwaga[8] = { "UWAGA: " };

	char *tab = new char[size];

	strcpy_s(tab, size, uwaga);

	sklej(tab, size, x);

	strcpy_s(x, size, tab);
	
	delete [] tab;
	
	return x;
}
//************************************************************************************************
void sklej(char *t1, int size, char *t2) // funkcja sklejaj¹ca, parametry: tablica docelowa, rozmiar tablicy docelowej, tablica Ÿród³owa
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
			t1[i] = 0;			// jeœli skoñczy³ siê rozmiar pierwszej tablicy, a dalej mo¿na przepisywaæ, przerwij pêtle
			for(int k = 0; k < 3; k++) 
				t1[--i] = '.';
			break;
		}
		else if((t1[i] == 0))
		{
			break;				// jeœli przepisano ca³y drugi string, a w pierwszej tablicy jest jeszcze miejsce, przerwij pêtle
		}
	}

} // end f. sklej
//************************************************************************************************