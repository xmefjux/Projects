#include <iostream>

using namespace std;

void zer(int wart, int &ref);
int multi(int x, double m, int a = 4, double y = 6.55, int k = 10);
//void f(int pierwszy, double drugi);
//void f(int, double);
// te dwa zapisy s� r�wnowa�ne
// je�li pomijamy nazwy argument�w w deklaracjach to argumenty domniemane deklarujemy w ten spos�b:
// void f(int = 1, double = 2.55);
// argumenty domniemane deklarujemy od prawej do lewej (inaczej: umieszczamy je na ko�cu listy)
// np. int x(int a=1, int b, int c=2); nie jest poprawn� deklaracj�

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
	// nie mo�na �adnego argumentu domniemanego pomin�� w wy�owaniu funkcji (w postaci dw�ch przecink�w np. multi (2, ,7);
	// kompilator og�lnie wsz�dzie nie zezwala na dwa przecinki obok siebie
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
// Wniosek: Przes�anie argument�w funkcji przez referencj� pozwala tej funkcji na modyfikowanie zmiennych (nawet lokalnych)
// znajduj�cych si� poza t� funkcj�.
// argumentem funkcji zer by� obiekt b typu int: zer (a, b);
// natomiast do funkcji nie zosta�a przekazana warto�� obiektu b tylko jego referencja (&ref) czyli adres w pami�ci tego obiektu
// czyli na stosie nie zosta�a utworzona kopia obiektu b tylko jego referencja (adres w pami�ci)
// "Dobrze, zatem kom�rce pami�ci o przes�anym mi adresie nadaj� pseudonim (przezwisko) ref"
// Podkre�lmy jasno: ta sama kom�rka, na kt�r� w main m�wi�o si� b, sta�a si� teraz w funkcji zer znana pod przezwiskiem ref. S� to dwie r�ne nazwy, ale okre�laj� ten sam obiekt.
// czyli funkcja zmienia oryginalny obiekt, a zapisuje tylko jego adres i po wykonaniu niszczy tylko jego adres ze stosu
// ten spos�b przesy�ania argument�w do funkcji jest unikany, bo mo�e si� odby� w spos�b niezauwa�ony
// ale u�ywa si� go w sytuacji, gdy zrobienie kopii obiektu mo�e zu�y� zbyt wiele zasob�w (np. kopia bardzo du�ego obiektu)
//************************************************************************************************************************************************************************************
int multi(int x, double m, int a, double y, int k)
{
	return 0;
}
