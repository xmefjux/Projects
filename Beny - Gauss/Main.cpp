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
void solution(int a[][6], int var);
//************************************************************************************************************
int main()
{
	// rozwiązywanie układu równań metodą eliminacji Gaussa-Jordana
    int a[6][6];
    int var;
    int i;
    int j;
    char znaki[] = { 'x', 'y', 'z', 'u', 'w' };

    cout << "Podaj rownania, wspolczynniki przy zmiennych musza byc rozne od zera." << endl;
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

    cout << endl;

    for (i = 0; i < var; i++)
    {
        for (j = 0; j < var; j++)
        {
        	if(a[i][j] != 1 && a[i][j] != (-1))
        		a[i][j] > 0 ? cout << a[i][j] << znaki[j] : cout << a[i][j]*(-1) << znaki[j];
        	else
        		cout << znaki[j];
            if(j < var-1)
            	a[i][j+1] > 0 ? cout << " + " : cout << " - ";
        }
        cout << " = " << a[i][var] << endl;
    }

    cout << endl;

    cout << "Program bedzie dazyl do utworzenia macierzy jednostkowej na podstawie wspolczynnikow oraz wyrazow wolnych." << endl;

    solution(a, var);

    return 0;
}
//************************************************************************************************************
void solution(int a[][6], int var)
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
            cout << l << endl;
            for (j = 0; j <= var; j++)
            {
            	if(i != k) a[i][j] = (a[k][k] * a[i][j]) - (l * a[k][j]);
            	cout << a[i][j];
            }
            cout << endl;
        }
    }

    cout << "Rozwiazania:" << endl;

    for (i = 0; i < var; i++)
    {
        a[i][i] == 0 ?
        		cout << znaki[i] << " = 0" << endl :
				cout << znaki[i] << " = " << static_cast<double>(a[i][var]) / static_cast<double>(a[i][i]) << endl;
    }

}
//************************************************************************************************************
