// #define wyraz ci�g znak�w
#define CZTERY 4
/*
float tablica[CZTERY];
i = CZTERY + 2 * CZTERY;
funkcja(CZTERY - 0.3);
cout << "Mowilem ci to CZTERY razy";
\\\\\\\\\\\\\\\\//////////////////
float tablica[4];
i = 4 + 2 * 4;
funkcja(4 - 0.3);
cout << "Mowilem ci to CZTERY razy";
*/

#define MAX_LICZ_PASAZER	250
#define LICZB_STEWARD		8
#define PASAZ_NA_STEWD		(MAX_LICZ_PASAZER / LICZB_STEWARD)
// dyrektywy mog� korzysta� z wcze�niej zdefiniowanych dyrektyw

#define ZEGAREK				(while(!zajety) czas(); )
// mo�na definiowa� dowolny ci�g znak�w
/*
funkcja_a();
i = 15 * czynnik;
ZEGAREK;
x = 15 * log(17);
\\\\\\\////////
funkcja_a();
i = 15 * czynnik;
(while(!zajety) czas(); );
x = 15 * log(17);
*/

// zwyczajowo definiowan� nazw� ci�gu znak�w pisze si� wielkimi literami

//#undef CZTERY
// #undef wyraz
// zwalnia to definicj� danego wyrazu

//----------------------------------------------------- Makrodefinicje ---------------------------------------------------
#define KWADR(a)			((a) * (a))
// to zamieni wszelkie wyst�pienie w tek�cie KWADR(parametr) na ( (parametr) * (parametr) )
/*
a = KWADR(c) + KWADR(x);
cout << KWADR(m+5.4);
\\\\\\\\\///////////
a = ((c) * (c)) + ((x) * (x));
cout << ((m+5.4) * (m+5.4));
*/

// mo�e by� te� wi�cej parametr�w
#define ILOCZYN(a,b,c) ( (a) * (b) * (c) )
// w wyrazie nie mo�e by� bia�ychznak�w

// makrodefinicja przypomina dyrektyw� inline, ale nie do ko�ca
// jest g�upsza od inline
// makrodefinicja nie sprawdza typ�w parametr�w, nie ma sprawdzania wa�no�ci zakresu u�ytych nazw
// makrodefinicja nie mo�e mie� wywo�a� rekurencyjnych i jej nazwa nie mo�e by� prze�adowywana
// makrodefinicji u�ywamy w przypadku kiedy chcemy "oszuka�" kompilator, na przyk�ad kiedy chcemy by w�a�nie nie sprawdza� typ�w argument�w
#define MAX(a,b)			( ((a) > (b)) ? (a) : (b) )
// to nam por�wna a i b i wska�e wi�ksz� warto�� niezale�nie od typu argument�w a i b
// wszelkie nawiasy wok� zmiennych nie s� wymagane, s� tylko dla bezpiecze�stwa

//---------------------------------------- Sklejacz nazw, czyli operator ## -----------------------------------------------
#define ST(co,jaki)			co ## jaki
// w programie zapis:
// int ST(statecznik,Poziomy);
// zostanie zamieniony na:
// int statecznikPoziomy;

// mamy definicje obiekt�w typu int
int zawodnik_bialy__ilosc_amunicji;
int zawodnik_bialy__biezacy_poziom;
int zawodnik_bialy__liczba_zlotych_punktow;
// je�li tych danych i zawodnik�w jest du�o, to mo�emy sobie upro�ci� pisanie tych definicji za pomoc� takiej makrodefinicji:
#define DDZ(kolor,dana)		int zawodnik_ ## kolor ## __ ## dana

//------------------------------------ Zamiana parametru aktualnego makrodefinicji na string -------------------------------
// Je�li w makrodefinicji, w rozwini�ciu jej, u�yjemy parametru poprzedzonego znakiem #, to tym samym otrzymamy string b�d�cy kopi� tego
// co tam - jako parametr aktualny - napiszemy.
#define M(z)				#z

// przyk�adowe zastosowanie
void odczytaj_z_dysku(char *nazwa_pliku, char *nazwa_wartosci, int *gdzie_zaladowac);
// upro�cimy wywo�ywanie funkcji za pomoc� makrodefinicji
#define OD(kolor, co) \
	odczytaj_z_dysku("status_gry.txt", #co, & zawodnik_ ## kolor ## __ ## co)

// inny przyk�ad
#define POKAZ(x)			cout << #x << " = " << (x) << endl // w tym �rodowisku ; na ko�cu nie wywali b��du (podw�jny �rednik)

//------------------------------------ Dyrektywy kompilacji warunkowej -------------------------------------------
// Polega to na tym, i� w zale�no�ci od spe�nienia pewnych warunk�w, okre�lone linie programu s� kompilowane lub nie.
// dyrektywa #if
//#if warunek
//		linie kompilowane warunkowo
//endif
// przyk�ady warunk�w
//#if NAZWA == NAZWA2
//#if NAZWA > 2
//#if (NAZWA_A == 2 || NAZWA_B > 10)
//#if NAZWA == 6 && defined(WERSJA_ROBOCZA)

// defined nazwa ------ lub ------ defined(nazwa)
// defined da true je�li dana nazwa by�a zdefiniowana #define nazwa lub nie odwo�ana #undef nazwa

// je�li chcemy si� upewni�, �e co� NIE zosta�o zdefiniowane, mo�emy po prostu poprzedzi� ten operator wykrzyknikiem
// #if NAZWA == 6 && !defined(WERSJA_ROBOCZA)

// Warunek #ifdef
#ifdef NAZWA		// if defined nazwa
	// instrukcje ...
#endif // NAZWA

// Warunek #ifndef
#ifndef NAZWA2		// if NOT defined nazwa2
	// instrukcje ...
#endif // NAZWA2

// zagnie�d�anie dyrektywy warunkowej

#define WERSJA		2 // gdy zmienimy t� warto�� na inn� ni� 1 lub 2 od raz #error ni�ej zostanie podkre�lony jako b��d
#define SZYBKOSC	1

#if (WERSJA == 1)
	#if (SZYBKOSC == 1)
		// instrukcje (1)
	#else
		// instrukcje (2)
	#endif // SZYBKOSC
#else
	#if (SZYBKOSC == 1)
		// instrukcje (3)
	#else
		// instrukcje (4)
	#endif // SZYBKOSC
#endif // WERSJA

// ---------------------- Dyrektywa #error --------------------
// Dyrektywa ma form�
//#error "tekst"
// Ta dyrektywa przerywa kompilacje je�li nie s� spe�nione warunki, w tym �rodowisku od razu wywala b��d przed kompilacj�

#if (WERSJA == 1)
	// ...
#elif (WERSJA == 2)
	// ...
#else
	#error "Musi byc wersja 1 lub wersja 2!"
#endif

// ---------------- Dyrektywa #line --------------------
// Posta�:
// #line sta�a "nazwa_pliku"
#line 128 "fikcja.cpp"
// od tej pory kompilator uzna, �e jest to linijka 128 programu - mimo, �e napawd� jest to linijka inna
// dodatkowo kompilator b�dzie my�la�, �e kompiluje plik o nazwie "fikcja.cpp". W�a�ciw� nazw� w tym momencie zapomina.

// --------------- Wstawianie tre�ci plik�w w tekst kompilowanego w�a�nie pliku ------------
// zasada jest taka:
// #include "header.h" ---- ten plik nag��wkowy napisali�my sami i jest szukany w bie��cym katalogu je�li nie zostanie tam znaleziony zostanie potraktowany jak <>
// #include <header.h> ---- ten plik nag��wkowy jest szukany w standardowym miejscu, gdzie znajduj� si� pliki w��czane (np. biblioteczne)

// Gwarancja jednokrotnego w��czenia danego pliku
#ifndef PLIK_X
#define PLIK_X
	// tre�� pliku
	// w ten spos�b ten plik zostanie skompilowany tylko raz
#endif // PLIK_X

// ciekawostka
// dyrektywa #include mo�e mie� bardziej og�ln� form�
// #include nazwa_zrobiona_preprocesorem
// Za pomoc� preprocesora mo�na konstruowa� nazw� pliku, kt�ry ma zosta� w��czony dyrektyw� #include

/*
#define SCIEZ_DO_PROJEKTU		/home/xmef/git/Projects
#define PODKATAL_NAGLOWKI		Preprocesor
#define SCIEZKA_DO_NAGLOW		SCIEZ_DO_PROJEKTU/PODKATAL_NAGLOWKI

#define NAGL(x)					<SCIEZKA_DO_NAGLOW##/lotn_##x##.h>

#include NAGL(odprawa)
*/

// ----------- Dyrektywa pusta # ----------
#
// to nie ma �adnego dzia�ania, jest po prostu ignorowane

// --------- Dyrektywy zale�ne od implementacji
//#pragma komenda
// Dzi�ki temu, wprowadzona zostaje mo�liwo�� u�ywania dyrektyw w�a�ciwych dla danego kompilatora, zatem szczeg�owego opisu tych dyrektyw trzeba szuka�
// w opisie kompilatora, kt�rym si� pos�ugujemy.
// Gdy komenda jest nieznana to kompilator j� zignoruje.


// cw_XV
#define GRUDZIEN_2007				1
#define SIERPIEN_2005				2

#define WERSJA_EKSPERYMENTU			GRUDZIEN_2007

#if (WERSJA_EKSPERYMENTU == GRUDZIEN_2007)
// ...
	#define TYP_SPREZARKI			2050
#elif (WERSJA_EKSPERYMENTU == SIERPIEN_2005)
// ...
	#define TYP_SPREZARKI			2050
#else 
	#error "Nie okreslony zostal typ eksperymentu"
#endif // (WERSJA_EKSPERYMENTU == GRUDZIEN_2007)




