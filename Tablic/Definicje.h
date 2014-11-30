// Tablice to typ pochodny. Bierzemy jakiœ typ i budujemy z niego tablicê.

// Tablice mo¿na tworzyæ z:
// - typów fundamentalnych (z wyj¹tkiem void)
// - typów wyliczeniowych (enum)
// - wskaŸników
// - innych tablic;
// oraz:
// - z obiektów typu zdefiniowanego przez u¿ytkownika (czyli klasy)
// - ze wskaŸników do pokazywania na sk³adniki klasy.

// ----- jakiego typu jest tablica? --------
// int tabl[n];
// tabl jest typem tablica n elementów (z których ka¿dy jest) typu int
// tabl[5];
// jest to wyra¿enie oznaczaj¹ce jeden element (5-ty) tej tablicy, który jest typu int, ca³e wyra¿enie jest typu int

// ------ trzeba pamiêtaæ o paru rzeczach -------
// By nie umieœciæ czegoœ w elemencie, który nie istnieje (nie przekroczyæ rozmiaru tablicy).
// Tablica ma sta³y rozmiar i nie mo¿emy go powiêkszyæ w dowolnej chwili.

// Inicjalizacja tablicy
int t1[4] = { 17, 5, 4, 200 };
// mo¿liwa jest te¿ taka inicjalizacja int t1[4] = { 17, 5 }; --- pierwsze dwa elementy zostan¹ zainicjalizowane 17 i 5, pozosta³e zerami
// w przypadku inicjalizacji tablicy nie trzeba podawaæ jej rozmiaru
int r[] = { 2, 10, 15, 16, 3 };

// ---- Inicjazizacja obiektów sta³ych ----
// Jeœli mamy zdefiniowaæ tablicê obiektów sta³ych, to inicjalizacja zbiorcza jest jedyn¹ szans¹ umieszczenia w niej wartoœci.
const int dni_w_miesiacach[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };	// musi byæ podany rozmiar tablicy



// wywo³anie funkcji z tablic¹ jako argument
//funkcja(tablica); // NAZWA TABLICY jest równoczeœnie ZDRESEM ZEROWOEGO JEJ ELEMENTU

// wywo³anie: funkcja(tablica + 3); zwróci element tablica[3] (z indeksem 3) -- adresem tego elementu jest &tablica[3]
// zatem: tablica + 3 i &tablica[3] s¹ równowa¿ne

// -------- Wys³anie tylko jednego argumentu ----------
//void fff(int x) {}
//
//int m;
//int tabl[100];
//fff(m);				// wys³anie do funkcji zwyk³ej zmiennej
//fff(tabl[38]);		// wys³anie do funkcji elementu nr 38


// ---------- komentarz do tablic znakowych -----------------
// C-string to po prostu znaki ustawione jeden za drugim, a na ich koñcu jest null, czyli bajt zerowy.
// Nazwa tego stringu (nazwa tablicy, gdzie on tkwi) jest równoczeœnie adresem tego miejsca w pamiêci, gdzie ten C-string siê zaczyna.

// ---------- komentarz tablice wielowymiarowe --------------
// po³o¿enie w pamiêci elementu w tablicy wielowymiarowej to: (i * j) + j w tablicy t[i][j]
// Wymiar znajduj¹cy siê najbardziej z lewej nie jest kompilatorowi potrzebny do obliczenia adresu elementów tablicy.
// -----------> W C++ nie ma tablic wielowymiarowych, s¹ tylko tablice tablic. <----------- 

// ttt[15][3];
/*
		Wyra¿enie		Opis							Typ tego wyra¿enia
		ttt				Tablica ttt						Tablica 15-elementowa, elementów bêd¹cych tablicami 3-elementowymi obiektów typu int.
		ttt[i]			i-ty rz¹d tablicy ttt			Tablica 3-elementowa obiektów typu int.
		ttt[i][j]		Jeden element tablicy ttt		Obiekt typu int.	
*/

// wyra¿enie ttt[7, 2] kompilator zrozumie jako: ttt[2].
// przecinek sprawia, ¿e wartoœci¹ tego wyra¿enia jest argument znajduj¹cy siê po prawej stronie przecinka

// --------- Przesy³anie tablic wielowymiarowych do funkcji -----------
// Po pierwsze musi byæ znany typ argumentu
// Po drugie musi byc znana iloœæ kolumn tej tablicy

int asd = 10;