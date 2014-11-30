#include <iostream>

using namespace std;
//******************************************************************************************************
/*
Wyobra�my sobie, �e mamy gdzie� funkcj�
	int muzyka();
kt�ra odgyrwa melodyjk�. Chcemy teraz zdefiniowa� wska�nik mog�cy pokazywa� na tak� funkcj�. Wska�nik ma si� nazywa� na przyk�ad www.
Piszemy wi�c na �rodku nazw� www i b�dziemy j� obudowywa� dooko�a.
M�wimy wi�c www
	www
jest wska�nikiem
	(*www)
s�u��cym do pokazywania na funkcj�
	(*www)()
zwracaj�c� warto�� typu int
	int (*www)();
Gotowe! (czyli triumfalny �rednik na ko�cu).
Je�li si� ju� taki wska�nik ma, to na nasz� funkcj� muzyka ustawia si� go cho�by tak� prost� instrukcj�:
	www = &muzyka;
*/
//******************************************************************************************************
/*
A teraz inny wska�nik. Ma si� on nadawa� do pokazywania na funkcj�
	double dzielenie(int, int);
Funkcja ta na przyk�ad dzieli dwie liczby ca�kowite i zwraca nam rezultat dzielenia. Zbudujmy wi�c wska�nik do niej.
Niech si� on nazywa ddd. Zatem m�wimy ddd i zapisujemy
	ddd
jest wska�nkiem
	(*ddd)
do funkcji wywo�ywanej z dwoma argumentami typu int
	(*ddd)(int, int)
a zwracaj�cej warto�� typu double
	double (*ddd)(int, int);
Gotowe!
*/
//******************************************************************************************************
/*
Inny spos�b na zapisanie definicji wska�nika do funkcji
	nazwa_funkcji --> (*nazwa_wska�nika)

	double funkcyjka(int, char); --> double (*wska�nik)(int, char);
*/
//******************************************************************************************************
/*
int ( * (*fw)(int, char *) )[2];
Zatem
	fw
w prawo si� ju� nie da, wi�c w lewo
	*fw
---jest wska�nikiem---
w lewo si� ju� nie da, wi�c wychodzimy na zewn�trz nawiasu i czytamy z prawej
	(*fw)(int, char *)
---do funkcji wywo�ywanej z 2 argumentami: typu int i typu char*, a zwracaj�cej---
( * (*fw)(int, char *))
dalej w prawo si� ju� nie da, bo jest nawias, pr�bujemy w lewo, a tam jest * czyli czytamy
---wska�nik do---
wychodzimy na zewn�trz nawiasu i czytamy z prawej
( * (*fw)(int, char *) )[2]
---dwuelementowej tablicy---
w prawo si� ju� nie da wi�c w lewo, a tam stoi tylko int
int ( * (*fw)(int, char *) )[2]
---obiekt�w typu int.---
*/
//******************************************************************************************************
/*
Wska�nik do pokazywania na funkcje jednego typu, nie mo�e by� u�ywany do pokazywania na funkcje innego typu.
*/
//******************************************************************************************************
/*
Kiedy tak naprawd� wska�nik do funkcji mo�e si� przyda�?
- Przy przesy�aniu argument�w do funkcji. Adres innej funkcji mo�na te� wys�a� jako argument.
To tak, jakby�my powiedzieli funkcji: tu masz takie argumenty, a dodatkowo tu jeszcze adres funkcji, kt�r� masz u siebie wykona�.
- Do tworzenia tablic ze wska�nik�w do funkcji; w takiej tablicy mamy jakby list� dzia�a� i odt�d mo�emy m�wi�: "a teraz wykonajmy funkcj� numer 5".
*/
//******************************************************************************************************
int okno_dialogowe(		const char * opis,
						const char * pyt,
						bool (*wsk_fun_zatwierdz)(int) = 0	);
bool czy_parzysta(int liczba);
bool czy_dozwolona_dla_detektora(int liczba);
//******************************************************************************************************
void Cwiczenia_z_definiowania_wskaznikow_do_funkcji()
{
	int odp;
	// ...

	odp = okno_dialogowe (
		"Pomiar widma promieniowania zakonczony\n# Mozemy "
		"przystapic do fitowania tla",
		"Podaj liczbe znacznikow tla? : ",
		&czy_parzysta);

	cout << "Dokonujemy fitowania tla w zaznaczonych " << odp/2 << " obszarach\n\n\n";
	
	//--------------------------------------------------

	odp = okno_dialogowe(
		"Ustawienie temperatury chlodzenia detektora",
		"Podaj docelowa temperature: ",
		&czy_dozwolona_dla_detektora);

	cout << "Otwieram zawory z cieklym azotem \naz do chwili osiagnieca temperatury "
		 << odp << " stopni\n\n\n";

	//--------------------------------------------------

	odp = okno_dialogowe(
		"Dialog bez koniecznosci sprawdzania",
		"Podaj jakakolwiek liczbe: "/*, 0*/);

	cout << "Otrzymana liczba to " << odp << " stopni\n";
}
//******************************************************************************************************
int okno_dialogowe(		const char * opis,
						const char * pyt,
						bool (*wsk_fun_zatwierdz)(int)	)
{
	cout
		<< "################# OKNO DIALOGOWE ####################\n# "
		<< opis
		<< "\n##--------------------------------##\n# ";

	int odpowiedz_uzytkownika;
	bool zatwierdzone = true;

	do
	{
		cout << pyt;
		cin >> odpowiedz_uzytkownika;

		if(wsk_fun_zatwierdz)
		{
			zatwierdzone = wsk_fun_zatwierdz(odpowiedz_uzytkownika);
		}
		else
		{
			zatwierdzone = true;
		}

	}while(!zatwierdzone);

	cout << "###########################################\n\n";

	return odpowiedz_uzytkownika;

}
//******************************************************************************************************
bool czy_parzysta(int liczba)
{
	if(liczba % 2)
	{
		cout 
			<< "# BLAD!!!\n# Podales liczbe " << liczba
			<< ", a to nie jest liczba parzysta" << endl
			<< "# Ponawiamy probe" << endl << "# >>> ";
		return false;
	}
	else
	{
		return true;
	}

}
//******************************************************************************************************
bool czy_dozwolona_dla_detektora(int liczba)
{
	if(liczba >= -70)
	{
		cout 
			<< "# BLAD!!!\n# Podales liczbe " << liczba
			<< ", a detektor powyzej\n# temperatury -70 stopni ulegnie uszkodzeniu" << endl
			<< "# Ponawiamy probe" << endl << "# >>> ";
		return false;
	}
	else
	{
		return true;
	}

}
//******************************************************************************************************