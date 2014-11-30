#include <iostream>

using namespace std;
//******************************************************************************************************
void arytmetyka_wskaznikow()
{
	// Mo¿na dodawaæ i odejmowaæ liczby ca³kowite do wskaŸników
	// i w ten sposób przesuwaæ te wskaŸniki po wskazywanej tablicy.
	// -----------------------------------------------------------
	// ------ Nie jest sprawdzana legalnoœæ takiej operacji ------
	// -----------------------------------------------------------

	// Czyli jeœli tablica ma tylko 10 elementów, a my wskaŸnik aktualnie pokazuj¹cy na element tablica[5]
	// przesuniemy o 80 elementów dalej, to wskaŸnik bêdzie pokazywa³ na nieistniej¹cy element tablica[85].
	// Inaczej: bêdzie pokazywa³ na miejsce w pamiêci, które by zajmowa³ element tablica[85], gdyby tylko by³a zdefiniowana tak du¿a tablica.
	 
	// Kompilator nie wychwyci tego jako b³¹d, po prostu nadpiszemy inne dane. Wykrycie takiego b³êdu jest trudne, bo mo¿e siê ujawniæ dopiero wtedy,
	// gdy bêdziemy z tej danej korzystaæ.
	// Rada: jeœli program zawiesza siê, nie dzia³a poprawnie z niewiadomych przyczyn, to nale¿y zastanowiæ siê nad wskaŸnikami.
	// Byæ mo¿e wskaŸnik pokazuje na b³êdne miejsce lub nie zosta³ zainicjalizowany sensown¹ wartoœci¹.

	// --- Odejmowanie wskaŸników ---
	// Odjêcie od siebie dwóch wskaŸników pokazuj¹cych na ró¿ne elementy tej samej tablicy daje w rezultacie liczbê dziel¹cych
	// je elementów tablicy. Liczba ta mo¿e byæ ze znakiem ujemnym lub dodatnim.
	// (Rezultat ten jest jakiegoœ typu ca³kowitego (ze znakiem). Typ ten nazywa siê ptrdiff_t (pointer difference)).

	int tablica[15];
	int *wsk_a, *wsk_b, *wsk_c;

	wsk_a = &tablica[5]; // (tablica + 5)
	wsk_b = &tablica[10];
	wsk_c = &tablica[11];

	cout << "(wsk_b - wsk_a) = " << (wsk_b - wsk_a) << endl
		 << "(wsk_c - wsk_b) = " << (wsk_c - wsk_b) << endl
		 << "(wsk_a - wsk_c) = " << (wsk_a - wsk_c) << endl
		 << "(wsk_c - wsk_a) = " << (wsk_c - wsk_a) << endl;		// *wsk_a to wartoœæ danego elementu tablicy, wsk_a to indeks danego elementu

	// Odejmowanie ma sens jedynie gdy odejmujemy wskaŸniki pokazuj¹ce na elementy tej samej tablicy.

	// Dozwolone operacje arytmetyczne na wskaŸnikach to:
	// 1) dodawanie i odejmowanie od nich liczb naturalnych - daje to przesuwanie wskaŸników
	// 2) odejmowanie dwóch wskaŸników pokazuj¹cych na t¹ sam¹ tablicê.
}
