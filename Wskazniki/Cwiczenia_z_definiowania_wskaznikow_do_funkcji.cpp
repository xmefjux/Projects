#include <iostream>

using namespace std;
//******************************************************************************************************
/*
WyobraŸmy sobie, ¿e mamy gdzieœ funkcjê
	int muzyka();
która odgyrwa melodyjkê. Chcemy teraz zdefiniowaæ wskaŸnik mog¹cy pokazywaæ na tak¹ funkcjê. WskaŸnik ma siê nazywaæ na przyk³ad www.
Piszemy wiêc na œrodku nazwê www i bêdziemy j¹ obudowywaæ dooko³a.
Mówimy wiêc www
	www
jest wskaŸnikiem
	(*www)
s³u¿¹cym do pokazywania na funkcjê
	(*www)()
zwracaj¹c¹ wartoœæ typu int
	int (*www)();
Gotowe! (czyli triumfalny œrednik na koñcu).
Jeœli siê ju¿ taki wskaŸnik ma, to na nasz¹ funkcjê muzyka ustawia siê go choæby tak¹ prost¹ instrukcj¹:
	www = &muzyka;
*/
//******************************************************************************************************
/*
A teraz inny wskaŸnik. Ma siê on nadawaæ do pokazywania na funkcjê
	double dzielenie(int, int);
Funkcja ta na przyk³ad dzieli dwie liczby ca³kowite i zwraca nam rezultat dzielenia. Zbudujmy wiêc wskaŸnik do niej.
Niech siê on nazywa ddd. Zatem mówimy ddd i zapisujemy
	ddd
jest wskaŸnkiem
	(*ddd)
do funkcji wywo³ywanej z dwoma argumentami typu int
	(*ddd)(int, int)
a zwracaj¹cej wartoœæ typu double
	double (*ddd)(int, int);
Gotowe!
*/
//******************************************************************************************************
/*
Inny sposób na zapisanie definicji wskaŸnika do funkcji
	nazwa_funkcji --> (*nazwa_wskaŸnika)

	double funkcyjka(int, char); --> double (*wskaŸnik)(int, char);
*/
//******************************************************************************************************
/*
int ( * (*fw)(int, char *) )[2];
Zatem
	fw
w prawo siê ju¿ nie da, wiêc w lewo
	*fw
---jest wskaŸnikiem---
w lewo siê ju¿ nie da, wiêc wychodzimy na zewn¹trz nawiasu i czytamy z prawej
	(*fw)(int, char *)
---do funkcji wywo³ywanej z 2 argumentami: typu int i typu char*, a zwracaj¹cej---
( * (*fw)(int, char *))
dalej w prawo siê ju¿ nie da, bo jest nawias, próbujemy w lewo, a tam jest * czyli czytamy
---wskaŸnik do---
wychodzimy na zewn¹trz nawiasu i czytamy z prawej
( * (*fw)(int, char *) )[2]
---dwuelementowej tablicy---
w prawo siê ju¿ nie da wiêc w lewo, a tam stoi tylko int
int ( * (*fw)(int, char *) )[2]
---obiektów typu int.---
*/
//******************************************************************************************************
/*
WskaŸnik do pokazywania na funkcje jednego typu, nie mo¿e byæ u¿ywany do pokazywania na funkcje innego typu.
*/
//******************************************************************************************************
/*
Kiedy tak naprawdê wskaŸnik do funkcji mo¿e siê przydaæ?
- Przy przesy³aniu argumentów do funkcji. Adres innej funkcji mo¿na te¿ wys³aæ jako argument.
To tak, jakbyœmy powiedzieli funkcji: tu masz takie argumenty, a dodatkowo tu jeszcze adres funkcji, któr¹ masz u siebie wykonaæ.
- Do tworzenia tablic ze wskaŸników do funkcji; w takiej tablicy mamy jakby listê dzia³añ i odt¹d mo¿emy mówiæ: "a teraz wykonajmy funkcjê numer 5".
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