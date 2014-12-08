#include <iostream>

using namespace std;

void typy(){
	
	int x = 230u; // int unsigned
	int a = 50uL; // int unsigned long
	int b = 15;
	b = 0xf; // zapis szesnatkowy 0x
	b = 017; // zapis ósemkowy 0

	register int i; // zapisanie zmiennej i do rejestru, do którego kompilator ma szybki dostêp
					// nie mo¿na zapytaæ o adres w pamiêci takiej zmiennej, bo rejestr go nie ma
					// zapytanie o adres spowoduje umieszczenie jej w zwyk³ej komórce pamiêci

	volatile int temperatura;	// specyfikator (przydomek) volatile oznacza, ¿e stan obiektu jest "ulotny", mo¿e siê zmieniæ bez wiedzy kompilatora
								// kompilator bêdzie zawsze faktycznie sprawdza³ stan obiektu spod jego adresu w pamiêci

	typedef int cena;		// typedef pozwala na nadanie istniej¹cemu typowi innej nazwy, zamiast int bêdzie cena
	cena xxx;					// co odpowiada: int xxx;
	cena aaa, bbb, ccc;			// co odpowiada: int aaa, bbb, ccc;

	// typedef mo¿na stosowaæ do typów z³o¿onych, a nie tylko fundamentalnych
	typedef int		* wskaznik_do_int;
	typedef char	* napis;
	wskaznik_do_int w1; // czyli: int * w1; (wskaŸnik na obiekt typu int)
	napis komunikat;	// czyli char * komunikat; (wskaŸnik na obiekt typu char)

	// mo¿na definiowaæ wiêcej nazw typów
	typedef int calk, * wskc, natur;
	calk ar;		// int ar;
	wskc w;			// int * w;
	natur n;		// int n;

	// typedef nie wprowadza nowego typu, a jedynie synonim dla istniêj¹cego ju¿ typu
	// typedef nie mo¿na redefiniowaæ nazwy, która ju¿ istnieje

	// typ wyliczeniowy enum - enum nazwa_typu { lista wyliczeniowa };

	enum akcja {
		start_pomiaru = 0,
		odczyt_pomiaru = 1,
		zmiana_probki = 54,
		zniszczenie_probki = 55
	};

	akcja co_robic;			// oznacza, ¿e akcja jest zmienn¹, do której mo¿na podstawiæ tylko jedn¹ z okreœlonych na liœcie wyliczeniowej akcja wartoœci
	// czyli:
	co_robic = zmiana_probki;
	co_robic = start_pomiaru;
	// nie dopuszczalne jest:
	// co_robic = 1;
	// co_robic = 4;
	// nic co nie jest na liœcie wyliczeniowej tego typu wyliczeniowego, nie mo¿e zostaæ podstawione do zmiennej typu akcja
	
	// przyk³ad typu wyliczeniowego, gdzie reprezentacje liczbowe s¹ inne
	enum operacja_dyskowa {
		czytaj_blok,								// wyliczenie rozpoczyna siê od 0, czytaj_blok = 0
		pisz_blok,									// do pisz_blok jest zapisana kolejna liczba z wyliczenia czyli 1, pisz_blok = 1
		przeskocz_blok = 5,							// tutaj normalne przypisanie przeskocz_blok = 5
		przeskocz_znacznik,							// znowu nie by³o przypisania, nastêpna liczba z wyliczenia 6
		powrot_do_poczatku,							// kolejna liczba z wyliczenia 7
		przewin = powrot_do_poczatku,				// mo¿na przypisaæ przed chwil¹ zdefiniowan¹ nazwê, czyli znowu 7
		zapisz_naglowek,							// kolejna liczba z wyliczenia, czyli 8
		zapisz_zakonczenie = zapisz_naglowek + 3	// wykorzystanie zdefiniowanej nazwy do przypisania i zwiêkszenie jej o 3: 8 + 3 = 11
	};

	// enum jest typem arytmetycznym czyli mo¿na dodawaæ do niego liczby, obiekt enum ma wartoœæ typu int np. przeskocz_blok + 1000 = 1005

	// typ wyliczeniowy nie musi mieæ nazwy
	// dziêki takiej sk³adni mamy wygodny sposób zdefiniowania kilku sta³ych (ca³kowitych) - w danym zakresie wa¿noœci

	enum {
		pierwsza,
		druga,
	};

	int aa = pierwsza;
	int pp=2;
	//cout << pp;
	//int pp;
	//cout << pp;
	extern int xx;
	extern int xx;

	bool zmienna;
	signed int zmiennaa;

	// strona 79, zadanie XXV
	int		w_int			= 10;		// postaæ int
	long	w_long			= 10;		// postaæ long
	int		w_unsigned_int	= 10u;		// postaæ unsigned int
	int		w_usnigned_long = 10uL;		// postaæ unsigned long
	double	w_double		= 10;		// postaæ double
	float	w_float			= 10;		// postaæ float

	// strona 79, zadanie XXVI
	double	x_double	= 15.6;			// double
	float	x_float		= 15.6f;		// float
	double	x_double_e	= 1.56e1;		// 1.56 * 10^1 = 15.6
	float	x_float_e	= 1.56e1f;		// wyk³adniczo we float

	char znak	= '\x2f';
	char znak2	= '\010';
	char znak_dec	= '47';
	char znak2_dec	= '8';
	char a_hex = '\x61';
	char a_oct = '\0141';
	char a_dec = '\97';
	cout << znak << " x2f " << znak2 << " 010 " << znak_dec << " 47 " << znak2_dec << " 8 teraz ->" << a_hex << a_oct << a_dec << a_dec << endl;

	{
		int k=1;
		{
			int k=5;
			cout << k << endl;
		}
	}

}