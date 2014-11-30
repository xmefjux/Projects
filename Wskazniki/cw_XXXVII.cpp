#include <iostream>
using namespace std;

//void umiesc(

void szachownica()
{
	// rezerwacja obszaru pamiêci
	char *szachownica = new char[8*8*sizeof(long)];
	// ustawienie wskaŸnika na ten obszar
	long *ptr_long = new (szachownica) long;
	// tablica figury
	//long *figury[]

	cout << "Na jakim polu szachownicy mam umieœciæ nowy obiekt typu long? Podaj symbol literowy: ";
	getchar();
	cout << "Podaj symbol cyfrowy: "; getchar();

}
