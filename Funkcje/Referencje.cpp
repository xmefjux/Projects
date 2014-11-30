#include <iostream>

using namespace std;

void zer(int wart, int &ref);
int multi(int x, double m, int a = 4, double y = 6.55, int k = 10);
//void f(int pierwszy, double drugi);
//void f(int, double);
// te dwa zapisy s¹ równowa¿ne
// jeœli pomijamy nazwy argumentów w deklaracjach to argumenty domniemane deklarujemy w ten sposób:
// void f(int = 1, double = 2.55);
// argumenty domniemane deklarujemy od prawej do lewej (inaczej: umieszczamy je na koñcu listy)
// np. int x(int a=1, int b, int c=2); nie jest poprawn¹ deklaracj¹

//****************************************************************************
void main_referencje()
{
	int a = 44, b = 77;

	cout << "Przed wywolaniem funkcji: zer " << endl;
	cout << "a = " << a << ", b = " << b << endl;

	zer(a, b);

	cout << "Po powrocie z funkcji: zer " << endl;
	cout << "a = " << a << ", b = " << b << endl;

	// argumenty domniemane funkcji
	// nie mo¿na ¿adnego argumentu domniemanego pomin¹æ w wy³owaniu funkcji (w postaci dwóch przecinków np. multi (2, ,7);
	// kompilator ogólnie wszêdzie nie zezwala na dwa przecinki obok siebie
	multi(2, 3.14);					// a = 4, y = 6.55, k = 10
	multi(2, 3.14, 7);				// a = 7, y = 6.55, k = 10
	multi(2, 3.14, 7, 0.3);			// a = 7, y = 0.33, k = 10
	multi(2, 3.14, 7, 0.3, 5);		// a = 7, y = 0.33, k = 5
}
//****************************************************************************
void zer(int wart, int &ref)
{
	cout << "\tW funkcji zer przed zerowaniem " << endl;
	cout << "\twart = " << wart << ", ref = " << ref << endl;

	wart = 0;
	ref = 0;

	cout << "\tW funkcji zer po zerowaniu " << endl;
	cout << "\twart = " << wart << ", ref = " << ref << endl;
}
//***********************************************************************************************************************************************************************************
// komentarz
// Wniosek: Przes³anie argumentów funkcji przez referencjê pozwala tej funkcji na modyfikowanie zmiennych (nawet lokalnych)
// znajduj¹cych siê poza t¹ funkcj¹.
// argumentem funkcji zer by³ obiekt b typu int: zer (a, b);
// natomiast do funkcji nie zosta³a przekazana wartoœæ obiektu b tylko jego referencja (&ref) czyli adres w pamiêci tego obiektu
// czyli na stosie nie zosta³a utworzona kopia obiektu b tylko jego referencja (adres w pamiêci)
// "Dobrze, zatem komórce pamiêci o przes³anym mi adresie nadajê pseudonim (przezwisko) ref"
// Podkreœlmy jasno: ta sama komórka, na któr¹ w main mówi³o siê b, sta³a siê teraz w funkcji zer znana pod przezwiskiem ref. S¹ to dwie ró¿ne nazwy, ale okreœlaj¹ ten sam obiekt.
// czyli funkcja zmienia oryginalny obiekt, a zapisuje tylko jego adres i po wykonaniu niszczy tylko jego adres ze stosu
// ten sposób przesy³ania argumentów do funkcji jest unikany, bo mo¿e siê odbyæ w sposób niezauwa¿ony
// ale u¿ywa siê go w sytuacji, gdy zrobienie kopii obiektu mo¿e zu¿yæ zbyt wiele zasobów (np. kopia bardzo du¿ego obiektu)
//************************************************************************************************************************************************************************************
int multi(int x, double m, int a, double y, int k)
{
	return 0;
}
