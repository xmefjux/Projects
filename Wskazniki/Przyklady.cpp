#include <iostream>

using namespace std;
//******************************************************************************************************
void Przyklady()
{
	{
		int zmienna = 9, drugi = 4;
		int* wskaznik;

		wskaznik = &zmienna;

		// prosty wypis na ekran
		cout << "zmienna = " << zmienna << endl
			 << "a odczytana przez wskaznik = " << *wskaznik << endl;

		zmienna = 10;
		cout << "zmienna = " << zmienna << endl
			 <<"a odczytana przez wskaznik = " << *wskaznik << endl;

		*wskaznik = 200;
		cout << "zmienna = " << zmienna << endl
			 << "a odczytana prez wskaznik = " << *wskaznik << endl;

		wskaznik = &drugi;
		cout << "zmienna = " << zmienna << endl
			 << "a odczytana przez wskaznik = " << *wskaznik << endl;
	}

	int			*wsk_int1,
				*wsk_int2;
	double		*wsk_double;

	//wsk_int1 = wsk_int2; // to oznacza: teraz wska�nik wsk_int1 pokazuje na to samo co wsk_int2
	
	//wsk_double = reinterpret_cast<double *>(wsk_int1); // rzutowanie wska�nika typu int na typ double i przypisanie tej warto�ci do wska�nika typu double
	// reinterpret_cast zosta� wymy�lony dla wska�nik�w, operator ten pozwala na konwersj� jednego typu wska�nika na inny typ wska�nika
	
	// reinterpret_cast dodatkowo pozwala na konwersj� mi�dzy wska�nikiem, a typem ca�kowitym (i odwrotnie).
	int *wsk_sygnalu;
	int numeryczny_adres = 0x0f6a2f1;
	//int schowek;

	// ustawienie wska�nika przez za�adowanie do niego adresu b�d�cego liczb� ca�kowit�
	wsk_sygnalu = reinterpret_cast<int*>(numeryczny_adres);
	// odczytanie adresu przechowywanego we wska�niku
	cout << "Wskaznik pokazuje na komorke pamieci numer: "
		 << reinterpret_cast<int*>(wsk_sygnalu)
		 << endl;

	// ----------- Wska�nik typu void -----------
	/*void *wv;

	char *wc;
	int *wi;
	double *wd;

	wv = wd;
	wv = wc;
	wv = wi;

	void *wv_drugi;
	wv_drugi = wv;*/ // mo�na przypisa� wska�nik typu void do innego wska�nika typu void

	// do wska�nika typu void nie mo�na przypisa� tre�ci obiektu z przydomkiem const

	/*
	 Wska�nik ka�dego (niesta�ego) typu mo�na przypisa� wska�nikowi typu void
	 ---- wska�nik void <------ dowolny wska�nik (non-const);
	 (do wska�nika void* nie mo�na przypisa� �adnego wska�nika do funkcji ani wska�nika do sk�adnika klasy)

	 Natomiast nie da si� odwrotnie.
	 Wska�nika typu void nie mo�na przypisa� wska�nikowi "prawdziwiemu". Trzeba si� pos�u�y� operatorem rzutowania.
	 dowolny wska�nik <------ rzutowanie ----- wska�nik void

	 Wiedz� o typie obiektu pokazywanego mo�na ewentualnie niezauwa�enie zapomnie�. Naby� tej wiedzy niezauwa�enie nie mo�na.
	 Trzeba to �wiadomie wyspecyfikowa� operacj� rzutowania.


	 ---- Cztery domeny zastosowania wska�nik�w ----
	
	 - ulepszenie pracy z tablicami
	 - funkcje mog�ce zmienia� warto�� przesy�anych do nich argument�w
	 - dost�p do specjalnych kom�rek pami�ci
	 - rezerwacj� obszar�w pami�ci
	*/

	// Definicje:
	int n = 5;
	int *wskaznik;
	int tablica[10];

	// instrukcja:
	wskaznik = &tablica[n];		// ustawienie wska�nika na n-ty element tablicy (pobranie adresu n-tego elementu)

	// wskaznik = &tablica[0]; jest tym samym co: wskaznik = tablica;

	// Je�li wskaznik jest ustawiony tak:
	wskaznik = &tablica[4];
	// to aby go przesun�� na nastepny element tablicy wystarczy:
	//wskaznik = wskaznik + 1;
	// lub:
	wskaznik++;
	// aby go przesun�� o n element�w
	wskaznik += n;

	// Dodanie do wska�nika jakiej� liczby ca�kowitej powoduje, �e pokazuje on tyle� element�w tablicy dalej. Niezale�nie od tego, jakie (typ) s� te elementy.
	// Poniewa� wska�nik ze swojej definicji (czy jest typu int, double, itd.) b�dzie wiedzia�, jakiego rozmiaru s� elementy i w jaki spos�b ma si� przesun��.
}
//******************************************************************************************************
void Przyklad_przesuwanie_wskaznikow()
{
	// definicje dw�ch tablic: int i double
	int ti[6];
	double td[6];
	// dwa wska�niki do pokazywania na typ int i double
	int *wi;
	double *wd;

	wi = &ti[0];
	wd = &td[0];

	cout << "Oto, jak przy inkrementacji wskaznikow zmieniaja sie ukryte w nich adresy:"
		 << endl;

	for(int i = 0; i < 6; i++, wi++, wd++)
	{
		cout << "i = " << i
			 << ", wi = "
			 << wi
			 << ", wd = "
			 << wd
			 << endl;
	}
	// Wska�nik to nie tylko adres jakiego� miejsca w pami�ci. To tak�e wiedza o tym, na jaki typ obiektu pokazuje. Wiedza ta wykorzystywana jest przy:
	// a) interpretowaniu tego, na co wska�nik pokazuje
	// b) ewentualnym poruszaniu wska�nika

}

