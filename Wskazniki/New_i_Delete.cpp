#include <iostream>

using namespace std;
//******************************************************************************************************
char *producent();
//******************************************************************************************************
void New_i_Delete()
{
	// Wa¿ne cztery sprawy na temat new i delete.

	// ----- 1 -----
	// Obiekty tak utworzone istniej¹ od momentu, gdy je utworzymy operatorem new, do momentu, gdy je skasujemy operatorem delete.
	// Inaczej mówi¹c - to my decydujemy o czasie ich ¿ycia.
	// ----- 2 -----
	// Obiekt tak utworzony nie ma nazwy. Mo¿na nim operowaæ tylko za pomoc¹ wskaŸników.
	// ----- 3 -----
	// Skoro obiekty takie nie maj¹ nazw - Obiektów tych (ich nazw) nie obowi¹zuj¹ zwyk³e zasady o zakresie wa¿noœci.
	// (Zasady te okreœla³yby to, w których miejscach programu obiekty te s¹ widzialne, a w których niewidzialne (mimo, ¿e istniej¹).
	// Jeœli tylko jest w danym momencie dostêpny choæby jeden wskaŸnik, który na taki obiekt pokazuje,
	// to mamy dostêp do takiego obiektu.
	// ----- 4 -----
	// Tylko statyczne obiekty wstêpnie inicjalizowane s¹ zerami (o ile nie okreœliliœmy inaczej).
	// Natomiast obiekty tworzone operatorem new nie s¹ statyczne (wrêcz przeciwnie - s¹ dynamiczne!)
	// dlatego zaraz po utworzeniu tkwi¹ w nich jeszcze œmieci. Musimy sami zadbaæ o zapisanie tam sensownych wartoœci.
	// ---------------------------------------------
	// WARTOŒCI¥ WYRA¯ENIA "NEW typ" JEST ADRES OBIEKTU
	// Operator new wywo³uje równie¿ konstruktor, natomiast delete destruktor.

	char *w1, *w2, *w3, *w4;		// definicje wskaŸników

	// tworzenie obiektów
	w1 = producent();
	w2 = producent();
	w3 = producent();
	w4 = producent();

	*w1 = 'H';
	*w2 = 'M';
	*w3 = 'I';

	cout << "Oto 3 znaki: " << *w1 << *w2 << *w3 << endl
		 << "Oraz smiec w czwartym: " << *w4 << endl;

	delete w1;
	delete w2;
	delete w3;

	// *w1 = 'F'; // by³aby tragedia, bo obiekt ju¿ nie istnieje!!!

	int *wsk;
	wsk = new int(32); // inicjalizacja nowego obiektu wartoœci¹ 32 typu int
	const double *wsk_pi;
	wsk_pi = new const double(3.1416); // const u¿yte po new jak i przy definicji wskaŸnika
	delete wsk, wsk_pi; // da siê po przecinkach delete?

	// Do tworzenia tablic s³u¿y operator new[]. Nie jest to inna sk³adnia new, tylko odrêbny operator.
	int *tabptr;
	int x;
	cout << "Ile elementow ma miec tablica? :";
	cin >> x;
	tabptr = new int[x];

	// ----- praca z tablic¹ -----
	*tabptr = 44;				// wpisanie do zerowego elementu
	tabptr[0] = 44;				// to samo inaczej

	*(tabptr + 3) = 100;		// wpisanie do elementu o indeksie 3
	tabptr[3] = 100;			// to samo inaczej

	delete [] tabptr;			// brat bliŸniak operatora delete
								// wynik dzia³ania operatora delete jest typu void

	// tablice wielowymiarowe tworzone operatorem new
	cout << "Podaj rozmiar: ";
	int ile; cin >> ile;
	
	// ----- rezerwacja tablicy wielowymiarowej ----
	int (*tablica)[7][4] = new int[ile][7][4];		// nawias w tym miejscu jest potrzebny, bo bez nawiasów zdefiniowana zosta³aby tablica wskaŸników, zamiast wskaŸnik do tablicy
	
	// ----- tak tego u¿ywamy ----
	tablica[2][4][3] = 1000;
	cout << tablica[2][3][4] << endl;

	// a tak likwidujemy
	delete [] tablica;

}
//******************************************************************************************************
char *producent()
{
	char *w;
	cout << "Wlasnie produkuje obiekt" << endl;
	w = new char;
	return w;
	// Operator new jest wywo³any wewn¹trz funkcji. Jednak obiekt w ten sposób utworzony nie ginie (nie jest tworzony na stosie).
	// Obiekt utworzony za pomoc¹ operatora new jest tworzony w "wolnym obszarze pamiêci" ("free store"), który jest przyznawany programowi.
	// Obiekt bêdzie istnia³ dopóki nie skasujemy go operatorem delete.
}
