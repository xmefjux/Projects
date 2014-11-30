#include <iostream>

using namespace std;

void kopiuj(char t1[], char t2[], char t3[], int rozmiar);
//************************************************************************************************
void main_cw_XVIII()
{
	char tab[200] = { "pierwszy drugi trzeci czwarty piaty szosty siodmy osmy dziewiaty dziesiaty jedenascie dwanascie trzynascie czternascie pietnascie szesnascie" };
	char parzyste[200];
	char nieparzyste[200];
	int x = sizeof(tab);
	cout << x << " " << sizeof(tab) << endl;
	kopiuj(tab, nieparzyste, parzyste, sizeof(tab));
}
//************************************************************************************************
void kopiuj(char t1[], char t2[], char t3[], int rozmiar)
{
	for(int i = 0, j = 0, k = 0; i < rozmiar; i++)
	{
		t2[j] = t1[i];
		j++;
		if(t1[i] == ' ')
		{
			if(k == 0)
			{
				i++;
			}
			do{
				t3[k] = t1[i];
				i++; k++;
			}
			while(t1[i] != ' ' && t1[i] != 0);
		}
		else if (t1[i] == 0)
		{
			t3[k] = t1[i]; 
		}
	}

	cout << "t1---->" << t1 << "<----" << endl << "t2---->" << t2 << "<----" << endl << "t2---->" << t3 << "<---" << endl;
	//cout << sizeof(t1) << " " << sizeof(t2) << " " << sizeof(t3) << endl;
}
