#include <iostream>

using namespace std;

void funkcja(int a = 2, int = 6);
//------------------
int kwadrat(int x) { return x * x; }
int globalny1 = 32;

//****************************************************************************
void main_przyklad()
{
	funkcja();

	{
		cout << "---- Jestesmy w zakresie lokalnym" << endl;

		// wywo�ujemy jeszcze "po staremu"
		funkcja();
		int lokalny1 = 2;
		// void funckja(int a = 3, int b);			// b�ad
		// void funkcja(int a, int b = lokalny1);	// b��d

		void funkcja(int a, int b = 8);

		// od tej pory "po staremu" wywo�a� ju� nie mo�na
		// funkcja();			// b��d

		funkcja(7);

		globalny1 = 4 + lokalny1;
		{
		// argumentem mo�e by� skompilowane wyra�enie...
		void funkcja(int a = kwadrat(globalny1), int b = 8);

		funkcja();
		}
	}
	cout << "----- Jestesmy poza zakresem lokalnym" << endl;

	funkcja();
}
//****************************************************************************
void funkcja(int a, int b)
{
	cout << "Naprawde wystapilo wywolanie: funkcja("
		 << a << ", " << b << ")" << endl;
}