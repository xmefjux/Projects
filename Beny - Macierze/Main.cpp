/*
 * Main.cpp
 *
 *  Created on: 9 sty 2015
 *      Author: xmef
 */
#include <iostream>
#include <fstream>
#include <string>
#include "math.h"
#include <stdlib.h>
#include <vector>
using namespace std;
//************************************************************************************************************
int read_N();
int read_L();
void write_wynik(int* wynik, int N);
//************************************************************************************************************
int main()
{
	// sprawdź czy zmienna mniejsza od L, jeśli równa to zwiększ i o L
	// wykonuj mnożenia od 0 do N - (i + 1)
	//
	/*
	 * for(int i = 0; i < N; i++)
	 * {
	 * 		if(x < L) x=0
	 * 		{
	 * 			for(j = 0; j < (N - (i + 1)); j++)
	 * 			{
	 * 				mnożenia
	 * 			}
	 * 			x++;
	 * 		}
	 * 		else
	 * 		{
	 * 			i += L;
	 * 			x = 0;
	 * 			if(i == N) break;
	 * 		}
	 * }
	 */
	/*int L;
	int N;
	static int A[8][8] = {
			{1, 2, 11, 3,  0, 0,  0, 0},
			{2, 2, 12, 3,  0, 0,  0, 0},
			{3, 2, 13, 3,  0, 0,  0, 0},
			{4, 2, 14, 3,  0, 0,  0, 0},
			{5, 2, 15, 0,  0, 0,  0, 0},
			{6, 2,  0, 0,  0, 0,  0, 0},
			{7, 0,  0, 0,  0, 0,  0, 0},
			{0, 0,  0, 0,  0, 0,  0, 0} };

	static int W[8];
	static int wynik[8];
	static int wynikprim[8];

	static int x;
	int mnozenia = 0;

	L = 4;
	N = 8;*/
	/*// wygenerowanie i wypisanie macierzy
	cout << "Macierz A" << endl;
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			//A[i][j] = rand() % 2 + 1;
			cout << A[i][j] << "(" << i << ", " << j << ") ";
			//cout << A[j][i] << "(" << i << ", " << j << ") ";
		}
		cout << endl;
	}
	cout << endl << "Macierz W" << endl;
	for(int i = 0; i < N; i++)
	{
		W[i] = i+1;
		cout << W[i] << endl;
	}
	// mnożenie macierzy
	cout << endl << "Macierz wynikowa" << endl;
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < (N - (i + 1)); j++) // warunek N - (i + 1) - pomijamy zera, wynikające z macierzy trójkątnej
		{
			if(x<L) // w tym miejscu wykonuj mnozenia
			{
				wynik[i] += A[i][j] * W[j];
				x++;
				mnozenia++;
			}
			else // przeskakujemy w macierzy o L, pomijamy zera
			{
				j += (L - 1);
				x = 0;
			}

		}
		cout << wynik[i] << endl;
		x = 0;
	}
	cout << "Mnozenia >>" << mnozenia << "<<" << endl;

	mnozenia = 0;
	cout << endl << "Macierz wynikowa" << endl;
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++) // warunek N - (i + 1) - pomijamy zera, wynikające z macierzy trójkątnej
		{
				wynikprim[i] += A[i][j] * W[j];
				mnozenia++;
		}
		cout << wynikprim[i] << endl;
	}
	cout << "Mnozenia >>" << mnozenia << "<<" << endl;*/

	/*ifstream myfile ("dane.txt");
	string jedna_linia_A;
	mnozenia = 0;
	if (myfile.is_open())
	{
		for(int i = 0; i < 2; i++)
		{
			getjedna_linia_A(myfile, jedna_linia_A);
		}
		while(getjedna_linia_A(myfile, jedna_linia_A))
		{
			cout << jedna_linia_A << endl;
			mnozenia++;
		}
	}
	cout << mnozenia << endl;*/

/*	int a = 2;
	int b = 3;
	//cin >> a >> b;
	int tab[5][4];
	for(int i = 0; i < 5; i++)
			for(int j = 0; j < 4; j++)
			{
				tab[i][j] = 1;
			}
	for(int i = 0; i < 5; i++)
	{
			for(int j = 0; j < 5; j++)
			{
				cout << tab[i][j];
			}
		cout << endl;
	}*/

	// odczytanie macierzy z pliku

	vector<string> macierz_A;
	ifstream myfile ("dane.txt");
	string jedna_linia_A;
	string macierz_W;
	if(myfile.is_open())
	{
		getline(myfile, jedna_linia_A);
		getline(myfile, jedna_linia_A);
		for(int i = 0; i < read_N(); i++)
		{
			getline(myfile, jedna_linia_A);
			macierz_A.push_back(jedna_linia_A);
		}
		getline(myfile, jedna_linia_A);
		getline(myfile, macierz_W);
	}
	myfile.close();

	int liczba_A_int;
	int liczba_W_int;
	string jedna_liczba_A_string;
	string jedna_liczba_W_string;

	int *wynik = new int[read_N()];
	for(int i = 0; i < read_N(); i++) wynik[i] = 0;

	static int warunek;
	static int mnozenia;

	int N = read_N();
	int L = read_L();

	for(int i = 0; i < read_N(); i++)
	{
		jedna_linia_A = macierz_A[i];

		for(int j = 0, k = 0; j < read_N() - (i + 1); j++, k+=2)
		{
			if(warunek < read_L())
			{
				jedna_liczba_A_string = jedna_linia_A[k];
				liczba_A_int = atoi(jedna_liczba_A_string.c_str());
				jedna_liczba_W_string = macierz_W[k];
				liczba_W_int = atoi(jedna_liczba_W_string.c_str());

				*(wynik + i) += liczba_A_int * liczba_W_int;
				mnozenia++;
				warunek++;
			}
			else
			{
				j += (read_L() - 1);
				warunek = 0;
			}
		}
		warunek = 0;
		cout << *(wynik + i) << endl;
	}
	cout << "Mnozenia >>" << mnozenia << "<<" << endl;

	write_wynik(wynik, read_N());

	/*string someText;
	cin>>someText;
	cout << "Standard output " << someText << endl;
	cerr << "Standard error output " << someText << endl;
*/
}
//************************************************************************************************************
int read_N()
{
	ifstream myfile ("dane.txt");
	int N;
	if (myfile.is_open())
	{
		myfile >> N;
		myfile.close();
	}
	else cout << "Unable to open file";

	return N;
}
//************************************************************************************************************
int read_L()
{
	ifstream myfile ("dane.txt");
	int L;
	if (myfile.is_open())
	{
		for(int i = 0; i < 2; i++) myfile >> L;
		myfile.close();
	}
	else cout << "Unable to open file";

	return L;
}
//************************************************************************************************************

//************************************************************************************************************
void write_wynik(int* wynik, int N)
{
		ofstream myfile;
		myfile.open ("wynik.txt");
		for(int i = 0; i < N; i++)
		{
			myfile << *(wynik++) << " ";
		}
		myfile.close();
}
//************************************************************************************************************
/*double read_x()
{
	double a;

	ifstream myfile ("zmienne.txt");
	if (myfile.is_open())
	{
		myfile >> a;
		myfile.close();
	}
	else cout << "Unable to open file";

	return a;

}*/
//************************************************************************************************************
