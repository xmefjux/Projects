#include <iostream>

using namespace std;

int k = 33;

void lokalne(){
	
	cout << "Jestem w main, k = " << k << endl;

	{ // otwarcie lokalnego bloku
		int k = 10;
		cout	<< "po lokalnej definicji k = " << k << endl
				<< "ale obiekt globalny k = " << ::k << endl; // :: (podw�jny dwukropek) to operator zakresu
	} // zamkni�cie lokalnego bloku
	
	cout << "Poza blokiem k = " << k << endl;

}