#include <iostream>

using namespace std;

void inc_dec(){
	int a = 5,
		b = 5,
		c = 5,
		d = 5;

	cout	<< "A oto wartosc poszczegolnych wyrazen " << endl
			<< "(nie mylic ze zmiennymi" << endl;

	cout	<< "++a = " << ++a		<< endl
			<< "b++ = " << b++		<< endl
			<< "--c = " << --c		<< endl
			<< "d-- = " << d--		<< endl;

	// teraz sprawdzamy, co jest w tych zmiennych

	cout	<< "Po obliczeniu tych wyrazen, same zmienne maja inne wartosci" << endl
			<< "a = " << a << endl
			<< "b = " << b << endl
			<< "c = " << c << endl
			<< "d = " << d << endl;

	// operator & zwraca adres w pamiêci oraz typ obiektu

	int x;
	cout << "1 lub 0" << endl
		 << "podaj : ";
	cin >> a;
	cout << "Odp: "
		 << (a ? "Tak" : "Nie" )
		 << ", prawda?" << endl;
}