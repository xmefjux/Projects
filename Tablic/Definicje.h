// Tablice to typ pochodny. Bierzemy jaki� typ i budujemy z niego tablic�.

// Tablice mo�na tworzy� z:
// - typ�w fundamentalnych (z wyj�tkiem void)
// - typ�w wyliczeniowych (enum)
// - wska�nik�w
// - innych tablic;
// oraz:
// - z obiekt�w typu zdefiniowanego przez u�ytkownika (czyli klasy)
// - ze wska�nik�w do pokazywania na sk�adniki klasy.

// ----- jakiego typu jest tablica? --------
// int tabl[n];
// tabl jest typem tablica n element�w (z kt�rych ka�dy jest) typu int
// tabl[5];
// jest to wyra�enie oznaczaj�ce jeden element (5-ty) tej tablicy, kt�ry jest typu int, ca�e wyra�enie jest typu int

// ------ trzeba pami�ta� o paru rzeczach -------
// By nie umie�ci� czego� w elemencie, kt�ry nie istnieje (nie przekroczy� rozmiaru tablicy).
// Tablica ma sta�y rozmiar i nie mo�emy go powi�kszy� w dowolnej chwili.

// Inicjalizacja tablicy
int t1[4] = { 17, 5, 4, 200 };
// mo�liwa jest te� taka inicjalizacja int t1[4] = { 17, 5 }; --- pierwsze dwa elementy zostan� zainicjalizowane 17 i 5, pozosta�e zerami
// w przypadku inicjalizacji tablicy nie trzeba podawa� jej rozmiaru
int r[] = { 2, 10, 15, 16, 3 };

// ---- Inicjazizacja obiekt�w sta�ych ----
// Je�li mamy zdefiniowa� tablic� obiekt�w sta�ych, to inicjalizacja zbiorcza jest jedyn� szans� umieszczenia w niej warto�ci.
const int dni_w_miesiacach[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };	// musi by� podany rozmiar tablicy



// wywo�anie funkcji z tablic� jako argument
//funkcja(tablica); // NAZWA TABLICY jest r�wnocze�nie ZDRESEM ZEROWOEGO JEJ ELEMENTU

// wywo�anie: funkcja(tablica + 3); zwr�ci element tablica[3] (z indeksem 3) -- adresem tego elementu jest &tablica[3]
// zatem: tablica + 3 i &tablica[3] s� r�wnowa�ne

// -------- Wys�anie tylko jednego argumentu ----------
//void fff(int x) {}
//
//int m;
//int tabl[100];
//fff(m);				// wys�anie do funkcji zwyk�ej zmiennej
//fff(tabl[38]);		// wys�anie do funkcji elementu nr 38


// ---------- komentarz do tablic znakowych -----------------
// C-string to po prostu znaki ustawione jeden za drugim, a na ich ko�cu jest null, czyli bajt zerowy.
// Nazwa tego stringu (nazwa tablicy, gdzie on tkwi) jest r�wnocze�nie adresem tego miejsca w pami�ci, gdzie ten C-string si� zaczyna.

// ---------- komentarz tablice wielowymiarowe --------------
// po�o�enie w pami�ci elementu w tablicy wielowymiarowej to: (i * j) + j w tablicy t[i][j]
// Wymiar znajduj�cy si� najbardziej z lewej nie jest kompilatorowi potrzebny do obliczenia adresu element�w tablicy.
// -----------> W C++ nie ma tablic wielowymiarowych, s� tylko tablice tablic. <----------- 

// ttt[15][3];
/*
		Wyra�enie		Opis							Typ tego wyra�enia
		ttt				Tablica ttt						Tablica 15-elementowa, element�w b�d�cych tablicami 3-elementowymi obiekt�w typu int.
		ttt[i]			i-ty rz�d tablicy ttt			Tablica 3-elementowa obiekt�w typu int.
		ttt[i][j]		Jeden element tablicy ttt		Obiekt typu int.	
*/

// wyra�enie ttt[7, 2] kompilator zrozumie jako: ttt[2].
// przecinek sprawia, �e warto�ci� tego wyra�enia jest argument znajduj�cy si� po prawej stronie przecinka

// --------- Przesy�anie tablic wielowymiarowych do funkcji -----------
// Po pierwsze musi by� znany typ argumentu
// Po drugie musi byc znana ilo�� kolumn tej tablicy

int asd = 10;