#include <iostream>
#include <string.h>

using namespace std;

// ------------ definicje ---------------------
#define	ILOSC_TYPOW_KOMBINACJI_SYGNALOW		4
#define NAJDLUZSZY_MOZLIWY_SYGNAL			12
#define CZTERY_SYGNALY						12
#define TRZY_SYGNALY						9
#define DWA_SYGNALY							6
#define JEDEN_SYGNAL						3
#define ILOSC_KOMBINACJI					15
#define DLUGOSC_KOMBINACJI					13
#define ILOSC_WYSTAPIEN						16
#define KONIEC_TABLICY						14
#define DLUGOSC_JEDNEGO_SYGNALU				4
#define CZY_OSTATNI_BIT_TO_JEDENKA			1
// ------------ sta�e --------------------------
static const char			spacja[4]		= { " + " }; 
static const int			kombinacje[ILOSC_WYSTAPIEN]	= { 48, 20, 1000, 950, 4, 8, 21, 300,
															720, 540, 7, 1, 120, 200, 56, 532 };
// ----------- funkcje ------------------------
void wygeneruj(char temp[][DLUGOSC_KOMBINACJI]);															// funkcja generuje kombinacje sygna��w (do wy�wietlania, segregowania)
void wstepne_wyswietlenie(char temp[][DLUGOSC_KOMBINACJI]);													// funkcja wy�wietla (i te� tworzy, wywo�uj�c f. sklej) kombinacje (nieposegregowane) sygna��w
// funkcja sklejania z cw_XXIII
void sklej(char cel[], int size_cel, char zrodlo[]);														// funkcja skleja poszczeg�lne (pojedyncze) sygna�y w docelowe kombinacje (tworzy elementy dla temp)
void segreguj(char segr[][DLUGOSC_KOMBINACJI], char temp[][DLUGOSC_KOMBINACJI], int temp_kombinacje[]);		// funkcja segreguje posklejane sygna�y malej�co, zale�nie od ilo�ci kombinacji sygna��w w danym ci�gu
void wyswietl_posegregowane(char segr[][DLUGOSC_KOMBINACJI], int posegr_kombinacje[]);						// funckja wy�wietla posegregowane kombinacje sygna��w
//************************************************************************************************
void main_cw_XXIX()
{
	// (mo�e kiedy� dopisa� kod generuj�cy te kombinacje sygna��w)
	char			temp[ILOSC_KOMBINACJI][DLUGOSC_KOMBINACJI];								// tablica do przechowywania sygna��w
	char			posegregowane[ILOSC_KOMBINACJI][DLUGOSC_KOMBINACJI];					// tablica do przechowywania POSEGREGOWANYCH sygna��w
	int				posegr_kombinacje[ILOSC_WYSTAPIEN];										// tablica posegregowanych ilo�ci kombinacji

	/*
	Kombinacja sygna��w				binarnie				nr elementu tablicy
	DGF HEC GER FRS
	 0	 0	 0	 0					0000					0					-							48 razy
	 0	 0	 0	 1					0001					1					FRS							28 razy
	 0	 0	 1	 0					0010					2					GER							1000 razy
	 0	 0	 1	 1					0011					3					FRS + GER					950 razy

	 0	 1	 0	 0					0100					4					HEC							4 razy
	 0	 1	 0	 1					0101					5					FRS + HEC					8 razy
	 0	 1	 1	 0					0110					6					GER + HEC					21 razy
	 0	 1	 1	 1					0111					7					FRS + GER + HEC				300 razy

	 1	 0	 0	 0					1000					8					DGF							720 razy
	 1	 0	 0	 1					1001					9					FRS + DGF					540 razy
	 1	 0	 1	 0					1010					10					GER + DGF					7 razy
	 1	 0	 1	 1					1011					11					FRS + GER + DGF				1 raz

	 1	 1	 0	 0					1100					12					HEC + DGF					120 razy
	 1	 1	 0	 1					1101					13					FRS + HEC + DGF				200 razy
	 1	 1	 1	 0					1110					14					GER + HEC + DGF				56 razy
	 1	 1	 1	 1					1111					15					FRS + GER + HEC + DGF		532 razy
	*/

	// losowe ci�gi 0 i 1, zczytywa� znak po znaku i przy ka�dym kolejnym zczytaniu dopisywa� odpowiedni sygna�
	// dopisywane sygna�y zapisa� jako... jednowymiarowa d�uga tablica?
	// tablica 16 element�w, 

	// -------- zasadnicze dzia�anie programu -------------
	wygeneruj(temp);												// generujemy sygna�y
	wstepne_wyswietlenie(temp);										// wy�wietlamy te sygna�y oraz ilo�ci ich wyst�pie�
	segreguj(posegregowane, temp, posegr_kombinacje);				// segregujemy je (pocz�wszy od najd�u�szego)
	wyswietl_posegregowane(posegregowane, posegr_kombinacje);		// wy�wietlamy posegregowane sygna�y i ilo�ci ich wyst�pie�
	// ----------------------------------------------------
	cout << endl; // kosmetyka...
	
} // end main local
//************************************************************************************************
void sklej(char t1[], int size, char t2[]) // funkcja sklejaj�ca, parametry: tablica docelowa, rozmiar tablicy docelowej, tablica �r�d�owa
{
	int find_null = 0;

	while(t1[find_null] != 0)
	{
		find_null++;
	}

	//t1[find_null] = ' ';

	for(int i = find_null/* + 1*/, j = 0; i < size; i++, j++)
	{
		t1[i] = t2[j];
		if(i == (size - 1))
		{
			t1[i] = 0;			// je�li sko�czy� si� rozmiar pierwszej tablicy, a dalej mo�na przepisywa�, przerwij p�tle
			break;
		}
		else if((t1[i] == 0))
		{
			break;				// je�li przepisano ca�y drugi string, a w pierwszej tablicy jest jeszcze miejsce, przerwij p�tle
		}
	}

} // end f. sklej
//************************************************************************************************
void segreguj(/*char cel[], char zrodlo[], int indeks, */char segr[][DLUGOSC_KOMBINACJI], char temp[][DLUGOSC_KOMBINACJI], int temp_kombinacje[])
{
	// FOR szukaj od indeksu 0 do ostatniego najwi�kszego rozmiaru stringu
	// je�li znajdziesz umie�� go w tabeli obok w indeksie 0, potem pon�w szukanie najwi�kszego rozmiaru stringu
	// je�li nie znajdziesz zmniejsz rozmiar o "1" i pon�w szukanie
	// kontynuuj szukanie a� rozmiar b�dzie 0
	// funkcja segreguj powinna wywo�ywa� funkcj� kopiuj

	// do segregowania (lub wy�wietlania posegregowanych) doda� do��czanie odpowiedniej ilo�ci wyst�pie� kombinacji ............. UPDATE: done

	int licznik = NAJDLUZSZY_MOZLIWY_SYGNAL; // pozycja znaku null (szukanie zaczyna si� od najd�u�szej kombinacji)
	int indeks = 0; // indeks w posegregowanej tablicy

	for(int i = 0; i < ILOSC_TYPOW_KOMBINACJI_SYGNALOW; i++)
	{
		// segregowanie jest podzielone na 4 etapy, ze wzgl�du na ilo�� kombinacji sygna��w (4 sygna�y, 3 sygna�y, itd.)
		// segregacja zaczyna si� od najd�u�szej kombinacji
		int find_null = 0; // licznik znajduj�cy znak '\0' w tablicy

		for(int k = 0; k < ILOSC_KOMBINACJI; k++)
		{
			// p�tla szuka danej kombinacji w�r�d element�w tablicy (kombinacje sygna��w)
			// sprawdza ka�dy element pod k�tem jego d�ugo�ci
			// je�li znajdzie element o po��danej d�ugo�ci zapisuje go do nowej tablicy

			while(temp[k][find_null] != 0)
			{
				find_null++;
			} // end while(temp[k][find_null] != 0)
			if(find_null == licznik)
			{
				strcpy(segr[indeks], temp[k]);	// k = stary indeks, indeks = nowy indeks (potencjalnie potrzebne do przypisania odpowiednich ilo�ci)
				//cout << segr[indeks] << " " << indeks << endl;
				temp_kombinacje[indeks] = kombinacje[k+1];
				indeks++;
			} // end if(find_null == licznik)
			if(k == KONIEC_TABLICY)
			{
				if(licznik == CZTERY_SYGNALY)
				{
					licznik = TRZY_SYGNALY;
				}
				else if(licznik == TRZY_SYGNALY)
				{
					licznik = DWA_SYGNALY;
				}
				else if(licznik == DWA_SYGNALY)
				{
					licznik = JEDEN_SYGNAL;
				}
				else if(licznik == JEDEN_SYGNAL)
				{
					break;
				}
			} // end if(k == KONIEC_TABLICY)
			find_null = 0;

		} // end for k

	} // end for i

} // end f. segreguj
//************************************************************************************************
void wyswietl_posegregowane(char segr[][DLUGOSC_KOMBINACJI], int posegr_kombinacje[])
{

	cout << "Sygnaly zostaly posegregowane od najdluzszej kombinacji do najkrotszej." << endl;
	cout << "------------------------------------------------------------------------" << endl;

	cout << "Poszczegolne kombinacje wystapily nastepujaca ilosc razy" << endl;

	int find_null = 0;
	
	for(int i = 0; i < ILOSC_KOMBINACJI; i++)
	{
		cout << "Kombinacja: ";

		while(segr[i][find_null] != 0)		// p�tla while, kt�a znajduje koniec C-stringu
		{
			find_null++;
		} // end while(segr[i][find_null] != 0)
		
		for(int j = 0; j < find_null; j++)	// p�tla for, kt�ra wy�wietli sygna�y oddzielone " + "
		{
			if((j % JEDEN_SYGNAL == 0) && (j > 0)) // wstaw " + " za wy�wietlonym sygna�em (j % 3 == 0) oraz je�li zosta� wy�wietlony wi�cej ni� 1 sygna� (j > 0)
																						  // dlatego wy�wietlanie " + " jest PRZED wy�wietleniem sygna�u
			{
				cout << spacja;
			}

			cout << segr[i][j];		// wy�wietl jeden znak z tablicy, w kt�rej jest umieszczony C-string ze sklejonymi sygna�ami
		} // end for j
		
		cout << " -> " << posegr_kombinacje[i] << " razy." << endl;
		
		find_null = 0;

	} // end for i
} // end f. wyswietl_posegregowane
//************************************************************************************************
void wstepne_wyswietlenie(char temp[][DLUGOSC_KOMBINACJI])
{
	cout << "Poszczegolne kombinacje wystapily nastepujaca ilosc razy" << endl;

	for(int i = 0; i < ILOSC_KOMBINACJI; i++)
	{

		cout << "Kombinacja: ";/* << wyswietl << " -> " << kombinacje[i] << " razy." << ile_wywolan << endl;*/

		int find_null = 0;		// zmienna, kt�ra ma znale�� znak '\0' ko�cz�cy C-string

		while(temp[i][find_null] != 0)		// p�tla while, kt�a znajduje koniec C-stringu
		{
			find_null++;
		}

		for(int j = 0; j < find_null; j++)	// p�tla for, kt�ra wy�wietli sygna�y oddzielone " + "
		{
			if((j % JEDEN_SYGNAL == 0) && (j > 0)) // wstaw " + " za wy�wietlonym sygna�em (j % 3 == 0) oraz je�li zosta� wy�wietlony wi�cej ni� 1 sygna� (j > 0)
																						  // dlatego wy�wietlanie " + " jest PRZED wy�wietleniem sygna�u
			{
				cout << spacja;
			}

			cout << temp[i][j];		// wy�wietl jeden znak z tablicy, w kt�rej jest umieszczony C-string ze sklejonymi sygna�ami
		}

		cout << " -> " << kombinacje[i] << " razy." << endl;

		//temp[i][0] = '\0';
	}

	cout << endl;
} // end f. wstepne_wyswietlanie
//************************************************************************************************
void wygeneruj(char temp[][DLUGOSC_KOMBINACJI])
{
	char			DGF[DLUGOSC_JEDNEGO_SYGNALU]	= { "DGF" };								// pojedyncze kombinacje
	char			HEC[DLUGOSC_JEDNEGO_SYGNALU]	= { "HEC" };								// ---------------------
	char			GER[DLUGOSC_JEDNEGO_SYGNALU]	= { "GER" };								// ---------------------
	char			FRS[DLUGOSC_JEDNEGO_SYGNALU]	= { "FRS" };								// ---------------------
	
	char*			sygnaly[4]						= { FRS, GER, HEC, DGF };					// tablica wska�nik�w do poszczeg�lnych tablic z zapisem sygna��w
	char			wyswietl[DLUGOSC_KOMBINACJI]	= { "\0" };									// tablica kt�ra przechowuje sklejony string do wy�wietlenia, z odpowiedni� kombinacj� sygna��w

	for(int i = 1, k = 0; i < ILOSC_WYSTAPIEN; i++, k++)
	{
		int licznik = 0;	// zmienna, kt�ra b�dzie indeksem dla tabeli sygna�y, zagwarantuje pobranie odpowiedniego sygna�u
		int a = i;			// zmienna do przesuwania bitowego w prawo, ma warto�� aktualnego indeksu tabeli z ilo�ciami kombinacji
		// przesuwanie bitowe w prawo w while, przechwyci� 0 lub 1 i if'y dopisuj�ce kolejno sygna�y je�li przesuni�ty bit by� 1 (jak przechwyci� t� przesuni�t� 1)
		// albo wczytaj najmniej znacz�cy bit (sprawd� czy 0 lub 1) i nast�pnie przesu� w prawo
		// kombinacje[i] & 1 == 1, jaki� licznik do 4
		while(a > 0)		// dop�ki a jest wi�ksze od 0 (po przesuwaniu w prawo)
		{
			if((a & CZY_OSTATNI_BIT_TO_JEDENKA) == 1)	// sprawd� czy ostatni (najmniej znacz�cy) bit jest 1 (oznacza to, �e wyst�pi� sygna�)
			{
				// je�li najmniej znacz�cy bit jest 1 to wywo�aj funkcj� sklejaj�c�, w wyniku kt�rej powstan� ci�gi sygna��w (FRS, FRSGER, itd)
				sklej(wyswietl, sizeof(wyswietl), sygnaly[licznik]);		
			}
			licznik++;		// zwi�ksz o 1, �eby pobra� nast�pny w kolejno�ci sygna�
			a = a >> 1;		// przesu� a o 1 miejsce w prawo
		}
		
		// teraz posegregowa� sygna�y w zale�no�ci od wyst�powania
		// wpierw 4 naraz, potem 3, 2, 1

		// w tym miejscu jest sklejony sygna�

		strcpy(temp[k], wyswietl);

		wyswietl[0] = '\0';		// wyzerowanie tablicy, kt�ra przechowuje sklejony string do skopiowania
								// by by�o mo�liwe skopiowanie wszystkich kombinacji sygna��w bez zape�nienia tablicy i utracenia pozosta�ych sygna��w

	} // end for i
} // end f. wygeneruj
//************************************************************************************************
