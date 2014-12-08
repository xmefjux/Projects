#include <iostream>

using namespace std;

void cw()
{
	// zadanie II
	{
		for(int i=1; i<=100; i++)
		{
			cout << i << " ";
			if(!(i%10))
				cout << " zakonczona dziesiatka" << endl;
		}
	}
	// zadanie III
	{
		char litera = 'A';
		for(int i=1; i<9; i++, litera++)
		{
			cout << litera << " ";
			if(!(i%2))
				cout << endl;
		}
		int x;
		cout << "Podaj krok: ";
		cin >> x;
		for(int i=1; i<19; i++, litera++)
		{
			cout << litera << " ";
			if(!(i%x))
				cout << endl;
		}
	}
	int a=4;
	cout << (a=7) << endl;
	bool jh = false;
	!!!jh;
	int sd = sizeof(double) +2;

}