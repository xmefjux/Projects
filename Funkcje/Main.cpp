#include <iostream>
#include "nagl.h"
#include "cw_XXXVI.h"

using namespace std;

void main_kukulka();
void main_potegi();
void main_referencje();
void main_przyklad();
void main_inline();
void main_globalny();
void main_automatyczne();
void main_lokalne_stat();
void main_afryka();
void main_rekurencja();
void main_test_reku();
void g();


double fff(int x);
double druga(char z, int k);
bool fx(char = 'g', double = 12.5);

// przy deklaracji funkcji spoza pliku s�owo extern jest domniemane

void pin(...);

//cw_XXIX
void druga();
//cw_XXXIII
void f();
// cw_XL
int silnia(int n, int wynik = 1);

//****************************************************************************
int main()
{
	
	//main_kukulka();
	//main_potegi();
	//main_referencje();
	//main_przyklad();
	//main_inline();
	//main_globalny();
	//main_automatyczne();
	//main_lokalne_stat();
	//main_afryka();
	main_rekurencja();
	//main_test_reku();
	
	//static int y = 5;
	//y--;
	//cout << fff(y) << endl;
	
	//double r = druga('h', 7);


	//g();

	//cw_XXIX
	//cout << wieksza(5, 4) << endl;
	//druga();

	// cw_XXXIII
	/*for(int i = 0; i < 100; i++)
	{
		f();
	}*/

	// cw_XXXVI
	/*f1_a();
	f2_a();
	f1_b();
	f2_b();*/

	// cw_XL
	/*int podaj = 0;
	cin >> podaj;
	cout << silnia(podaj) << endl;*/

	//system("pause");
}
//****************************************************************************
double fff(int x)
{
	int m = 6 + 3;
	if(x)
	{
		cout << "Zaraz wywolam main znowu" << endl;
	main();
	x = x - 1;
	}
	return 0.5 + m;
}
