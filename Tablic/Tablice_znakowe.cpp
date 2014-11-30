#include <iostream>
#include <string.h>

using namespace std;

void strcpyy(char cel[], char zrodlo[]);
//************************************************************************************************
void main_Tablice_znakowe()
{
	char zdanie[80] = { "lot" };		// char zdanie[80] = { 'l', 'o', 't' };
	// dzi�ki temu, �e inicjalowali�my tablic� znakiem ograniczonym cudzys�owem to po znaku 't' jest znak null
	// w rzeczywisto�ci tablica sk�ada si� z 4 element�w: 'l', 'o', 't', null
	// przy wywo�aniu funkcji puts (put string) do wypisania C-stringa b�dzie ona wypisywa�a dop�ki nie natrafi na znak null
	//puts(zdanie);
	// przy definicji: char zdanie[] = { 'l', 'o', 't' };, kompilator nie doda na ko�cu znaku null, poniewa� nie uzna�, �e to ma by� C-string
	
	char napis1[] = { "Nocny lot" };
	char napis2[] = { 'N', 'o', 'c', 'n', 'y', ' ', 'l', 'o', 't' };
	cout << "rozmiar tablicy pierwszej: " << sizeof(napis1) << endl;
	cout << "rozmiar tablicy drugiej: " << sizeof(napis2) << endl;

	//char t1[1] = { "a" };	// b��d, kt�ry z reszt� �rodowisko wychwytuje od razu
	//char t1[1] = { 'a' };

	char start[] = { "taki sobie zwykly tekst" };
	char meta[80];
	strcpy(meta, start);
	cout << meta << endl;

	char tekst[] = { "Uwaga, tarcza zostala przepalona!" };
	char komunikat[120];
	strcpyy(komunikat, tekst);
	cout << komunikat << endl;
	strncpy(komunikat, "1234567890abcdef", 9);
	cout << komunikat << endl;
	strcpyy(komunikat, "--A ku ku --!");
	cout << "Na koniec: " << komunikat << endl;

}
//************************************************************************************************
// dzia�anie strcpy_s
void strcpyy(char cel[], char zrodlo[])
{
	int i = 0;
	while ((cel[i] = zrodlo[i]))
	{
		i++;
	}

}
