/*
 * Main.cpp
 *
 *  Created on: 9 sty 2015
 *      Author: xmef
 */
#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;
//************************************************************************************************************
void write_result(int* result, int N, int multi); // funkcja zapisująca wynik mnożenia do pliku
//************************************************************************************************************
int main()
{
	// sprawdź czy zmienna mniejsza od L, jeśli równa to zwiększ indeks o L
	// wykonuj mnożenia od 0 do N - i
// -------------------------------------------------------------------------------------------------------------------------
	// deklaracje zmiennych
	static int N; 				// zmienna N, rozmiar macierzy A
	static int L; 				// zmienna L, co ile kolumn są "zera"
	int *A;						// wskaźnik na obszar z macierzą A
	int *W;						// wskaźnik na obszar z wektorem W
	int *result;				// wskaźnik na obszar z macierzą wynikową
	static int multi;			// zmienna na liczbę mnożeń
	static int index;			// zmienna na indeks macierzy, ponieważ tablica 2-wymiarowa jest przechowywana jako 1-wymiarowa
	static int jump;			// zmienna pomocnicza, do przeskakiwania "zer" w macierzy
// -------------------------------------------------------------------------------------------------------------------------
	// pobieranie danych z pliku
	ifstream myfile ("dane.txt");
	if(myfile.is_open())
	{
		myfile >> N;
		A = new int[(N*N)];
		W = new int[N];
		result = new int[N];
		myfile >> L;
		for(int i = 0; i < (N*N); i++)
		{
			myfile >> A[i];
		}
		for(int i = 0; i < N; i++)
		{
			myfile >> W[i];
		}
	}
	myfile.close();
// -------------------------------------------------------------------------------------------------------------------------
	// nadanie wartości początkowych obszarowi z tablicą wynikową - by uniknąć ewentualnego wyświetlenia śmieci
	for(int i = 0; i < N; i++)
	{
		result[i] = 0;
	}
// -------------------------------------------------------------------------------------------------------------------------
	// wykonywanie mnożeń
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < (N - i);) // warunek N - i - pomijamy zera, wynikające z macierzy trójkątnej
		{
			if(jump < L) // w tym miejscu wykonuj mnozenia jeśli jump < L, czyli w miejscach niezerowych
			{
				result[i] += A[index] * W[j];
				index++;
				jump++;
				j++;
				multi++;
			}
			else // przeskakujemy w macierzy o L, pomijamy zera
			{
				j += L;
				index += L;
				jump = 0;
			}

		}
		//cout << result[i] << endl;
		jump = 0;
		index = (i+1) * N;
	}
// -------------------------------------------------------------------------------------------------------------------------
	// zapis wyniku mnożenia macierzy przez wektor do pliku
	//cout << "Liczba mnozen >>" << multi << "<<" << endl;
	write_result(result, N, multi);
// -------------------------------------------------------------------------------------------------------------------------
	// niszczenie zarezerwowanych obszarów pamięci
	delete [] A;
	delete [] W;
	delete [] result;

}
//************************************************************************************************************
void write_result(int* result, int N, int multi)
{
	// zapisanie wyniku mnożenia do pliku
	ofstream myfile;
	myfile.open ("wynik.txt");
	for(int i = 0; i < N; i++)
	{
		myfile << *(result++) << endl;
	}
	myfile << "Liczba mnozen >>" << multi << "<<";
	myfile.close();
}
//************************************************************************************************************
