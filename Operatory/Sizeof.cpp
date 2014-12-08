#include <iostream>

using namespace std;

// operator sizeof (sizeof(nazwa_typu), sizeof(nazwa_obiektu)) zwraca rozmiar obiektu danego typu w bajtach

void _sizeof()
{
	int mm;

	cout << "Godzina prawdy. W tym komputerze poszczegolne typy" << endl
		 << "maja nastepujace rozmiary w bajtach: " << endl;

	cout << "typ char: \t"			<< sizeof(char)			<< endl;
	cout << "typ int: \t"			<< sizeof(int)			<< endl;
	cout << "typ short: \t"			<< sizeof(short)		<< endl;
	cout << "typ long: \t"			<< sizeof(long)			<< endl;
	cout << "typ float: \t"			<< sizeof(float)		<< endl;
	cout << "typ double: \t"		<< sizeof(double)		<< endl;
	cout << "typ long double: \t"	<< sizeof(long double)	<< endl;

	cout << "Obiekt lokalny mm ma rozmiar:  \t"		<< sizeof(mm)	<< endl;
}