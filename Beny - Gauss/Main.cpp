/*
 * Main.cpp
 *
 *  Created on: 13 sty 2015
 *      Author: xmef
 */
#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;
//************************************************************************************************************
void solution(int a[][20], int var);
//************************************************************************************************************
int main()
{
	// rozwiązywanie układu równań metodą eliminacji Gaussa-Jordana
    int a[20][20];
    int var;
    int i;
    int j;
    char znaki[] = { 'x', 'y', 'z', 'u', 'w' };

    cout << "Wpisz liczbe zmiennych: ";
    cin >> var;

    for (i = 0; i < var; i++)
    {
        cout << "Podaj rownanie " << i+1 << endl;
        for (j = 0; j < var; j++)
        {
            cout << "Podaj wpolczynnik " << znaki[j] << ": ";
            cin >> a[i][j];
        }
        cout << "Podaj stala: ";
        cin >> a[i][var];
    }

    solution(a, var);

    return 0;
}
//************************************************************************************************************
void solution(int a[][20], int var)
{
    int k;
    int i;
    int l;
    int j;
    char znaki[] = { 'x', 'y', 'z', 'u', 'w' };

    for (k = 0; k < var; k++)
    {
        for (i = 0; i <= var; i++)
        {
            l = a[i][k];
            for (j = 0; j <= var; j++)
            {
            	if(i != k) a[i][j] = (a[k][k] * a[i][j]) - (l * a[k][j]);
            }
        }
    }

    cout << "Rozwiazania:" << endl;

    for (i = 0; i < var; i++)
    {
        a[i][i] == 0 ?
        		cout << "Wartosc " << znaki[i] << " = 0" << endl :
				cout << "Wartosc " << znaki[i] << " = " << static_cast<double>(a[i][var]) / static_cast<double>(a[i][i]) << endl;
    }

}
//************************************************************************************************************
