#include <iostream>

using namespace std;
//******************************************************************************************************
void arytmetyka_wskaznikow()
{
	// Mo�na dodawa� i odejmowa� liczby ca�kowite do wska�nik�w
	// i w ten spos�b przesuwa� te wska�niki po wskazywanej tablicy.
	// -----------------------------------------------------------
	// ------ Nie jest sprawdzana legalno�� takiej operacji ------
	// -----------------------------------------------------------

	// Czyli je�li tablica ma tylko 10 element�w, a my wska�nik aktualnie pokazuj�cy na element tablica[5]
	// przesuniemy o 80 element�w dalej, to wska�nik b�dzie pokazywa� na nieistniej�cy element tablica[85].
	// Inaczej: b�dzie pokazywa� na miejsce w pami�ci, kt�re by zajmowa� element tablica[85], gdyby tylko by�a zdefiniowana tak du�a tablica.
	 
	// Kompilator nie wychwyci tego jako b��d, po prostu nadpiszemy inne dane. Wykrycie takiego b��du jest trudne, bo mo�e si� ujawni� dopiero wtedy,
	// gdy b�dziemy z tej danej korzysta�.
	// Rada: je�li program zawiesza si�, nie dzia�a poprawnie z niewiadomych przyczyn, to nale�y zastanowi� si� nad wska�nikami.
	// By� mo�e wska�nik pokazuje na b��dne miejsce lub nie zosta� zainicjalizowany sensown� warto�ci�.

	// --- Odejmowanie wska�nik�w ---
	// Odj�cie od siebie dw�ch wska�nik�w pokazuj�cych na r�ne elementy tej samej tablicy daje w rezultacie liczb� dziel�cych
	// je element�w tablicy. Liczba ta mo�e by� ze znakiem ujemnym lub dodatnim.
	// (Rezultat ten jest jakiego� typu ca�kowitego (ze znakiem). Typ ten nazywa si� ptrdiff_t (pointer difference)).

	int tablica[15];
	int *wsk_a, *wsk_b, *wsk_c;

	wsk_a = &tablica[5]; // (tablica + 5)
	wsk_b = &tablica[10];
	wsk_c = &tablica[11];

	cout << "(wsk_b - wsk_a) = " << (wsk_b - wsk_a) << endl
		 << "(wsk_c - wsk_b) = " << (wsk_c - wsk_b) << endl
		 << "(wsk_a - wsk_c) = " << (wsk_a - wsk_c) << endl
		 << "(wsk_c - wsk_a) = " << (wsk_c - wsk_a) << endl;		// *wsk_a to warto�� danego elementu tablicy, wsk_a to indeks danego elementu

	// Odejmowanie ma sens jedynie gdy odejmujemy wska�niki pokazuj�ce na elementy tej samej tablicy.

	// Dozwolone operacje arytmetyczne na wska�nikach to:
	// 1) dodawanie i odejmowanie od nich liczb naturalnych - daje to przesuwanie wska�nik�w
	// 2) odejmowanie dw�ch wska�nik�w pokazuj�cych na t� sam� tablic�.
}
