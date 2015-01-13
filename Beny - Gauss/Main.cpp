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
int main()
{
/*
//------------------------------------------------------------------------------------------------------------
	// rozwiązywanie układu równań metodą Gaussa
	// jedynie układy oznaczone, ilość niewiadomych = ilość równań
	static int N = 3;						// ilość niewiadomych
	double *macierz_wspolcz;			// wskaźnik na obszar z macierzą współczynników
	double *macierz_wyr_woln;			// macierz wyrazów wolnych
	double *result;
	static double ratio;
//------------------------------------------------------------------------------------------------------------
	// pobieranie danych z pliku
	ifstream myfile ("dane.txt");
	if(myfile.is_open())
	{
		myfile >> N;
		macierz_wspolcz = new double[(N*N)];
		macierz_wyr_woln = new double[N];
		result = new double[N];
		for(int i = 0; i < (N*N); i++)
		{
			myfile >> macierz_wspolcz[i];
		}
		for(int i = 0; i < N; i++)
		{
			myfile >> macierz_wyr_woln[i];
		}
	}
	myfile.close();
*/

	int i,j,k,n;
	    float A[20][20],c,x[10],sum=0.0;
	    printf("\nEnter the order of matrix: ");
	    scanf("%d",&n);
	    printf("\nEnter the elements of augmented matrix row-wise:\n\n");
	    for(i=1; i<=n; i++)
	    {
	        for(j=1; j<=(n+1); j++)
	        {
	            printf("A[%d][%d] : ", i,j);
	            scanf("%f",&A[i][j]);
	        }
	    }
	    for(j=1; j<=n; j++) /* loop for the generation of upper triangular matrix*/
	    {
	        for(i=1; i<=n; i++)
	        {
	            if(i>j)
	            {
	                A[j][j] == 0 ? c = 0 : c = A[i][j] / A[j][j];
	                for(k=1; k<=n+1; k++)
	                {
	                    A[i][k] = A[i][k] - (c * A[j][k]);
	                }
	            }
	        }
	    }
	    A[n][n] == 0 ? x[n] = 0 : x[n] = A[n][n+1] / A[n][n];
	    /* this loop is for backward substitution*/
	    for(i=n-1; i>=1; i--)
	    {
	        sum=0;
	        for(j=i+1; j<=n; j++)
	        {
	            sum = sum + A[i][j] * x[j];
	        }
	        A[i][i] == 0 ? x[i] = 0 : x[i] = (A[i][n+1] - sum) / A[i][i];
	    }
	    printf("\nThe solution is: \n");
	    for(i=1; i<=n; i++)
	    {
	        printf("\nx%d=%f\t",i,x[i]); /* x1, x2, x3 are the required solutions*/
	    }
	    return(0);
}
//************************************************************************************************************
