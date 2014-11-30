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

	//wsk_int1 = wsk_int2; // to oznacza: teraz wskaünik wsk_int1 pokazuje na to samo co wsk_int2
	
	//wsk_double = reinterpret_cast<double *>(wsk_int1); // rzutowanie wskaünika typu int na typ double i przypisanie tej wartoúci do wskaünika typu double
	// reinterpret_cast zosta≥ wymyúlony dla wskaünikÛw, operator ten pozwala na konwersjÍ jednego typu wskaünika na inny typ wskaünika
	
	// reinterpret_cast dodatkowo pozwala na konwersjÍ miÍdzy wskaünikiem, a typem ca≥kowitym (i odwrotnie).
	int *wsk_sygnalu;
	int numeryczny_adres = 0x0f6a2f1;
	//int schowek;

	// ustawienie wskaünika przez za≥adowanie do niego adresu bÍdπcego liczbπ ca≥kowitπ
	wsk_sygnalu = reinterpret_cast<int*>(numeryczny_adres);
	// odczytanie adresu przechowywanego we wskaüniku
	cout << "Wskaznik pokazuje na komorke pamieci numer: "
		 << reinterpret_cast<int>(wsk_sygnalu)
		 << endl;

	// ----------- Wskaünik typu void -----------
	/*void *wv;

	char *wc;
	int *wi;
	double *wd;

	wv = wd;
	wv = wc;
	wv = wi;

	void *wv_drugi;
	wv_drugi = wv;*/ // moøna przypisaÊ wskaünik typu void do innego wskaünika typu void

	// do wskaünika typu void nie moøna przypisaÊ treúci obiektu z przydomkiem const

	/*
	 Wskaünik kaødego (niesta≥ego) typu moøna przypisaÊ wskaünikowi typu void
	 ---- wskaünik void <------ dowolny wskaünik (non-const);
	 (do wskaünika void* nie moøna przypisaÊ øadnego wskaünika do funkcji ani wskaünika do sk≥adnika klasy)

	 Natomiast nie da siÍ odwrotnie.
	 Wskaünika typu void nie moøna przypisaÊ wskaünikowi "prawdziwiemu". Trzeba siÍ pos≥uøyÊ operatorem rzutowania.
	 dowolny wskaünik <------ rzutowanie ----- wskaünik void

	 WiedzÍ o typie obiektu pokazywanego moøna ewentualnie niezauwaøenie zapomnieÊ. NabyÊ tej wiedzy niezauwaøenie nie moøna.
	 Trzeba to úwiadomie wyspecyfikowaÊ operacjπ rzutowania.


	 ---- Cztery domeny zastosowania wskaünikÛw ----
	
	 - ulepszenie pracy z tablicami
	 - funkcje mogπce zmieniaÊ wartoúÊ przesy≥anych do nich argumentÛw
	 - dostÍp do specjalnych komÛrek pamiÍci
	 - rezerwacjÍ obszarÛw pamiÍci
	*/

	// Definicje:
	int n = 5;
	int *wskaznik;
	int tablica[10];

	// instrukcja:
	wskaznik = &tablica[n];		// ustawienie wskaünika na n-ty element tablicy (pobranie adresu n-tego elementu)

	// wskaznik = &tablica[0]; jest tym samym co: wskaznik = tablica;

	// Jeúli wskaznik jest ustawiony tak:
	wskaznik = &tablica[4];
	// to aby go przesunπÊ na nastepny element tablicy wystarczy:
	//wskaznik = wskaznik + 1;
	// lub:
	wskaznik++;
	// aby go przesunπÊ o n elementÛw
	wskaznik += n;

	// Dodanie do wskaünika jakiejú liczby ca≥kowitej powoduje, øe pokazuje on tyleø elementÛw tablicy dalej. Niezaleønie od tego, jakie (typ) sπ te elementy.
	// Poniewaø wskaünik ze swojej definicji (czy jest typu int, double, itd.) bÍdzie wiedzia≥, jakiego rozmiaru sπ elementy i w jaki sposÛb ma siÍ przesunπÊ.
}
//******************************************************************************************************
void Przyklad_przesuwanie_wskaznikow()
{
	// definicje dwÛch tablic: int i double
	int ti[6];
	double td[6];
	// dwa wskaüniki do pokazywania na typ int i double
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
			 << reinterpret_cast<unsigned int>(wi)
			 << ", wd = "
			 << reinterpret_cast<unsigned int>(wd)
			 << endl;
	}
	// Wskaünik to nie tylko adres jakiegoú miejsca w pamiÍci. To takøe wiedza o tym, na jaki typ obiektu pokazuje. Wiedza ta wykorzystywana jest przy:
	// a) interpretowaniu tego, na co wskaünik pokazuje
	// b) ewentualnym poruszaniu wskaünika

}

