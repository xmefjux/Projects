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

	if(var > 1)
	{
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

		cout << "Program bedzie dazyl do utworzenia macierzy jednostkowej na podstawie wspolczynnikow oraz wyrazow wolnych." << endl << endl;

		solution(a, var);

		if(var == 2)
		{
			cout << "1 0 | ";
			a[0][0] == 0 ?
        			cout << znaki[0] << " = 0" << endl :
					cout << znaki[0] << " = " << static_cast<double>(a[0][var]) / static_cast<double>(a[0][0]) << endl;
			cout << "0 1 | ";
			a[1][1] == 0 ?
        			cout << znaki[1] << " = 0" << endl :
					cout << znaki[1] << " = " << static_cast<double>(a[1][var]) / static_cast<double>(a[1][1]) << endl;
		} 
		else if(var == 3)
		{
			cout << "1 0 0 | ";
			a[0][0] == 0 ?
        			cout << "0 = " << znaki[0] << endl :
					cout << static_cast<double>(a[0][var]) / static_cast<double>(a[0][0]) << " = " << znaki[0] << endl;
			cout << "0 1 0 | ";
			a[1][1] == 0 ?
        			cout << "0 = " << znaki[1] << endl :
					cout << static_cast<double>(a[1][var]) / static_cast<double>(a[1][1]) << " = " << znaki[1] << endl;
			cout << "0 0 1 | ";
			a[1][1] == 0 ?
        			cout << "0 = " << znaki[2] << endl :
					cout << static_cast<double>(a[2][var]) / static_cast<double>(a[2][2]) << " = " << znaki[2] << endl;
		}

	}// end if (var > 1)
	else
		cout << "Podaj wiecej niz 1 zmienna!" << endl;

	system("pause");
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
            for (j = 0; j <= var; j++)
            {
            	if(i != k) a[i][j] = (a[k][k] * a[i][j]) - (l * a[k][j]);
            }
        }
    }

    cout << "Rozwiazania:" << endl;

	/*
    for (i = 0; i < var; i++)
    {
        a[i][i] == 0 ?
        		cout << znaki[i] << " = 0" << endl :
				cout << znaki[i] << " = " << static_cast<double>(a[i][var]) / static_cast<double>(a[i][i]) << endl;
    }
	*/

}
//************************************************************************************************************
