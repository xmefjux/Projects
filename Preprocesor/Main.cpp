//#include <iostream>

#define PLIK			<iostream>
#define LOKALNA			"Definicje.h"
#define CW_XXI			"cw_XXI.h"

//#include "Definicje.h"

#include LOKALNA
#include PLIK
#include CW_XXI

using namespace std;

// cw_X
inline double dziel(double a, double b)
{
	return (a) / (b);
}
// cw_XII
inline void czynnik(double a, double b)
{
	cout << 
		((a) / ((a) + (b)));
}


#define DZIEL(a,b) ((a) / (b))

int wystaw_kola();
//*******************************************************************************************
int main()
{
	int a = CZTERY;			// w pliku nag��wkowym Definicje.h jest dyrektywa #define CZTERY 4 - jest to r�wne zapisowi int a = 4;
	int x = 5;
	char w = 't', u = 'f';
	//int p;
	//p = KWADR(x++);
	//cout << "p = " << p << ", x = " << x << endl;		// to mia�o produkowa� b��dy, a wykona�o si� poprawnie
	// jednak na takie zapisy nale�y uwa�a�
	cout << MAX(a, x) << endl;
	cout << MAX(w, u) << endl;

	DDZ(czerwony, ilosc_amunicji) = 5; // to odpowiada zapisowi int zawodnik_czerwony__ilosc_amunicji = 5;
	DDZ(czerwony, biezacy_poziom) = 1;
	DDZ(czerwony, liczba_zlotych_punktow) = 2;

	cout << M(bla blal) << endl;

	//// przyk�adowe zastosowanie
	//odczytaj_z_dysku("status_gry.txt", "ilosc_amunicji", &zawodnik_bialy__ilosc_amunicji);
	//odczytaj_z_dysku("status_gry.txt", "ilosc_amunicji", &zawodnik_bialy__biezacy_poziom);
	//odczytaj_z_dysku("status_gry.txt", "ilosc_amunicji", &zawodnik_bialy__liczba_zlotych_punktow);
	//// poni�sze zapisy s� r�wnowa�ne powy�szym wywo�aniom funkcji
	//OD(czerwony, ilosc_amunicji);
	//OD(czerwony, biezacy_poziom);
	//OD(czerwony, liczba_zlotych_punktow);

	// inny przyk�ad
	int obiekt = 5;
	POKAZ(obiekt);
	POKAZ(obiekt + 7);
	POKAZ(12);
	POKAZ(10 + 2);

	
	/*cout << */wystaw_kola();

	cout << endl;

	cout << "Kompilacja tego pliku: " << __FILE__ << endl
		 << "(linijka "				<< __LINE__ << ")" << endl
		 << "zaczela sie: "			<< __DATE__
		 << ", o godzinie: "		<< __TIME__ << endl;

	// cw_V
	/*const int trzy = 3;
#define DZIESIEC 10
	double s1 = trzy / DZIESIEC;
	double s2 = DZIESIEC + trzy;
	double s3 = DZIESIEC / trzy;

	const int x1 = 20;
	const int x2 = 30;
	const int x3 = x1 + x2;
	cout << (2 * x3) << endl;

	// cw_VIII
#define NNN 10
#define NNN 50
	cout << NNN << endl;

	cout << DZIEL(10, 2) << endl;
	cout << dziel(10, 2) << endl;*/

	//cw_XII
#define CZYNNIK(a,b)		((a) / ((a) + (b)))
	int d = 0;
	while(d < 10)
	{
		cout << "Czynnik = " << CZYNNIK(++d, 2.0);
		cout << ", dla d = " << d << endl;
	}
	cout << endl;
	d = 0;
	while(d < 10)
	{
		cout << "Czynnik = "; 
		czynnik
			(++d, 2.0); // inkrementacja PRZED obliczeniem, obliczy dla d=10
		cout << ", dla d = " << 
			d << endl;
	}

	// cw_XIII
#define MISJA(x)			cout << "Apollo_" << (x) << endl
	MISJA(12);
	MISJA(9);

	// cw_XIV
#define MAKRO(a)			cout << "W linii " << __LINE__ << ", wartosc wyrazenia \"" << #a << "\" = " << (a) << endl
	MAKRO(obiekt);
	MAKRO(obiekt + 7);




	//system("pause");
}
