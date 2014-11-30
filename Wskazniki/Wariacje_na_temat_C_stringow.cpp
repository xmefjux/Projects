#include <iostream>

using namespace std;

void przedzielacz_tabl(const char tab[]);
void przedzielacz_wsk(const char *w);
//-------- Kopiowanie C-string z tablicy do tablicy --------
char * strcp(char *cel, const char *zrodlo);
// ------- Konkatenacja (³¹czenie) C-stringów --------------
char * strcatt(char *cel, const char *zrodlo);

//******************************************************************************************************
void Wariacje_na_temat_C_stringow()
{
	// C-string jest typu const char [] np. "Uwaga: "

	char ostrzezenie[80] = { "Alarm trzeciego stopnia " };

	cout << "wersja tablicowa" << endl;
	przedzielacz_tabl(ostrzezenie);

	cout << endl << "wersja wskaznikowa" << endl;
	przedzielacz_wsk(ostrzezenie);

	cout << endl << endl;
	
	// --------------------------------
	char poziom[] = { "Poziom szumu w normie" };
	char komunikat[80];

	//strcp(komunikat, poziom);
	cout << poziom << endl;
	cout << strcp(komunikat, poziom) << endl;
	
	cout << endl;

	char pierwszy[80] = { "hurra" };
	char drugi[80];
	char trzeci[80];

	strcp(trzeci, strcp(drugi, pierwszy));
	cout << pierwszy << ", " << drugi << ", " << trzeci << endl;

	cout << endl;

	char stara[80] = { "zdanie trzecie" };
	char nowa[80];
	cout << (strcp(nowa, stara+1));

	cout << endl;

	// -------------------------------------
	char co[] = { "urzadzen sterowych" };
	char komunikat1[80] = { "Alarm: " };

	strcatt(komunikat1, co);
	cout << "po dopisaniu = " << komunikat1 << endl;
	cout << strcatt(komunikat1, ", o godz 17:12");

	cout << endl;

}
//******************************************************************************************************
void przedzielacz_tabl(const char tab[])
{
	int i = 0;
	while(tab[i])
	{
		cout << tab[i++] << "-";
	}
	// w wersji tablicowej pozycja w pamiêci jest liczona dwukrotnie
}
//******************************************************************************************************
void przedzielacz_wsk(const char *w)
{
	while(*w)
	{
		cout << *(w++) << "-";
	}
	// w wersji wskaŸnikowej adres nie jest liczony w ogóle, s¹ tylko odczytywane wartoœci stamt¹d gdzie pokazuje wskaŸnik i potem jedynie nastêpuje przesuniêcie wskaŸnika
}
//******************************************************************************************************
char *strcp(char *cel, const char *zrodlo)
{
	char *poczatek = cel;

	while(*(cel++) = *(zrodlo++)); // ciekawa konstrukcja while
	return poczatek;
}
//******************************************************************************************************
char * strcatt(char *cel, const char *zrodlo)
{
	char *poczatek = cel;

	// przesuniêcie napisu na koniec C-stringu
	while(*(cel++));

	// teraz pokazuje o 1 znak za (chyba przed) null
	cel--;

	// to ju¿ braliœmy przy strcp
	while(*(cel++) = *(zrodlo++));

	return poczatek;
}
