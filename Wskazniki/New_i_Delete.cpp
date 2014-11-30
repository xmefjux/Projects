#include <iostream>

using namespace std;
//******************************************************************************************************
char *producent();
//******************************************************************************************************
void New_i_Delete()
{
	// Wa�ne cztery sprawy na temat new i delete.

	// ----- 1 -----
	// Obiekty tak utworzone istniej� od momentu, gdy je utworzymy operatorem new, do momentu, gdy je skasujemy operatorem delete.
	// Inaczej m�wi�c - to my decydujemy o czasie ich �ycia.
	// ----- 2 -----
	// Obiekt tak utworzony nie ma nazwy. Mo�na nim operowa� tylko za pomoc� wska�nik�w.
	// ----- 3 -----
	// Skoro obiekty takie nie maj� nazw - Obiekt�w tych (ich nazw) nie obowi�zuj� zwyk�e zasady o zakresie wa�no�ci.
	// (Zasady te okre�la�yby to, w kt�rych miejscach programu obiekty te s� widzialne, a w kt�rych niewidzialne (mimo, �e istniej�).
	// Je�li tylko jest w danym momencie dost�pny cho�by jeden wska�nik, kt�ry na taki obiekt pokazuje,
	// to mamy dost�p do takiego obiektu.
	// ----- 4 -----
	// Tylko statyczne obiekty wst�pnie inicjalizowane s� zerami (o ile nie okre�lili�my inaczej).
	// Natomiast obiekty tworzone operatorem new nie s� statyczne (wr�cz przeciwnie - s� dynamiczne!)
	// dlatego zaraz po utworzeniu tkwi� w nich jeszcze �mieci. Musimy sami zadba� o zapisanie tam sensownych warto�ci.
	// ---------------------------------------------
	// WARTO�CI� WYRA�ENIA "NEW typ" JEST ADRES OBIEKTU
	// Operator new wywo�uje r�wnie� konstruktor, natomiast delete destruktor.

	char *w1, *w2, *w3, *w4;		// definicje wska�nik�w

	// tworzenie obiekt�w
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

	// *w1 = 'F'; // by�aby tragedia, bo obiekt ju� nie istnieje!!!

	int *wsk;
	wsk = new int(32); // inicjalizacja nowego obiektu warto�ci� 32 typu int
	const double *wsk_pi;
	wsk_pi = new const double(3.1416); // const u�yte po new jak i przy definicji wska�nika
	delete wsk, wsk_pi; // da si� po przecinkach delete?

	// Do tworzenia tablic s�u�y operator new[]. Nie jest to inna sk�adnia new, tylko odr�bny operator.
	int *tabptr;
	int x;
	cout << "Ile elementow ma miec tablica? :";
	cin >> x;
	tabptr = new int[x];

	// ----- praca z tablic� -----
	*tabptr = 44;				// wpisanie do zerowego elementu
	tabptr[0] = 44;				// to samo inaczej

	*(tabptr + 3) = 100;		// wpisanie do elementu o indeksie 3
	tabptr[3] = 100;			// to samo inaczej

	delete [] tabptr;			// brat bli�niak operatora delete
								// wynik dzia�ania operatora delete jest typu void

	// tablice wielowymiarowe tworzone operatorem new
	cout << "Podaj rozmiar: ";
	int ile; cin >> ile;
	
	// ----- rezerwacja tablicy wielowymiarowej ----
	int (*tablica)[7][4] = new int[ile][7][4];		// nawias w tym miejscu jest potrzebny, bo bez nawias�w zdefiniowana zosta�aby tablica wska�nik�w, zamiast wska�nik do tablicy
	
	// ----- tak tego u�ywamy ----
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
	// Operator new jest wywo�any wewn�trz funkcji. Jednak obiekt w ten spos�b utworzony nie ginie (nie jest tworzony na stosie).
	// Obiekt utworzony za pomoc� operatora new jest tworzony w "wolnym obszarze pami�ci" ("free store"), kt�ry jest przyznawany programowi.
	// Obiekt b�dzie istnia� dop�ki nie skasujemy go operatorem delete.
}
