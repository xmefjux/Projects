#include <iostream>

using std::cout; // deklaracja using std::cout; dzi�ki niej mo�na u�ywa� samego cout
using std::cin;

// dyrektywa using namespace std; pozwoli na u�ycie wszystkich nazw z przestrzeni nazw std bez std::

void cw1();
void cw2();
void cw3();
void cw4();
void cw5();
void cw6();
void cw7();
void cw8();
void lokalne();
void typy();

int main()
{
	//cw1();
	//cw2();
	//cw3();
	//cw4();
	//cw5();
	//cw6();
	//cw7();
	//cw8();

	//lokalne();

	typy();

	int m;
	cin >> m;
	switch(m){
	case 1:
		cout << "1\a\a\a\a\a\a\a\a\a\a\a\a\a \x61";
		break;
	default:
		cout << "def";
	case 5-2:
		cout << "3";
		break;
	case 5-3:
		cout << "2";
	}

}
