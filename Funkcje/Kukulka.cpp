#include <iostream>

using namespace std;

int kukulka(int ile);

void pin(...);

//****************************************************************************
void main_kukulka()
{
	
	int m = 20;
	cout << "Zaczynamy" << endl;

	m = kukulka(5);
	cout << endl << "Na koniec m = " << m << endl;

}
//****************************************************************************
int kukulka(int ile){

	for(int i=0; i<ile; i++)
	{
		cout << "Ku-Ku! ";
	}
	return 77;
}
//****************************************************************************