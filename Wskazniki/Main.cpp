#include <iostream>
//�w. XXXVII
#include <new>
#include <math.h>
#include <stdlib.h>
//kot
using namespace std;

void Przyklad_przesuwanie_wskaznikow();
void wskaznik_z_tablica();
void arytmetyka_wskaznikow();
void porownywanie_wskaznikow();
void zastosowanie_wsk_w_arg_funkcji();
void odbieranie_tablicy();
void Argument_formalny_do_const();
void New_i_Delete();
void Umiejscawiajacy_operator_new();
void Pulapki_z_new_i_delete();
void Zapas_pamieci();
void Const_cast();
void Tablice_wskaznikow();
void Wariacje_na_temat_C_stringow();
void Wskazniki_do_funkcji();
void Cwiczenia_z_definiowania_wskaznikow_do_funkcji();
void Tablica_wskaznikow_do_funkcji();

// zmienna globalna i
static int i;

// �w. XXIX
void zerowanie(int *wsk);
// �w. XXX
void dodaj(int x[], int i);
// �w. XXXI
void wypisz(const double *x, int k);
// �w. XXXIII
void multi_tabs(double *ptr1, double *ptr2, double *ptr3, int size);
// �w. XXXIV
double* kreator_tablicy(int size);
// �w. XXXVII

// �w. XLVIII
void XLVIII();
// �w. IL
void * IL(char x[], double *(*y[]));
// �w. L
char * L(char * x, int size);
// �w. LII
void * (*w)(char*);
// �w. LIII
bool fun(bool (*wx)(double, double), char (*wy)(double));
// �w. LIV
int a(); int b();  int c();
int F(int (*w)());
// �w. LVI
double * o();
// �w. LIX
void u(int = 4);
// �w. LXII
void lxii(void (*w)(int)); // nie mo�e mie� warto�ci domniemanej
// �w. LXIII
void LXIII();


// WSKA�NIK ZAWSZE POKAZUJE NA CO�

//******************************************************************************************************
// wys�anie parametr�w do funkcji
// argc - argument counter - m�wi ILE argument�w zosta�o wys�anych do programu, jest zawsze conajmniej 1 argument: nazwa programu,
// argv - argument vector, wska�nik do tablicy z C-stringami: argumentami wys�anymi do funkcji
// uruchomienie programu Wskazniki.exe param1 77.2 wy�le do programu 3 argumenty
int main(int argc, char* argv[])
{
	//cout << "Wydruk parametrow wywolania:" << endl;

	//for(int i = 0; i < argc; i++)
	//{
	//	cout << "Parametr nr " << i << " to C-string: " << argv[i] << endl;
	//}
	///*------zamienimy C-string na liczb�-------*/
	//float x;
	//x = atof(argv[2]);
	//x = x + 4;
	//cout << "x = " << x << endl;


	//Przyklad_przesuwanie_wskaznikow();
	//wskaznik_z_tablica();
	//arytmetyka_wskaznikow();
	//porownywanie_wskaznikow();
	//zastosowanie_wsk_w_arg_funkcji();
	//odbieranie_tablicy();
	//Argument_formalny_do_const();
	//New_i_Delete();
	//Umiejscawiajacy_operator_new();
	//Pulapki_z_new_i_delete();
	//Zapas_pamieci();
	//Const_cast();
	//Tablice_wskaznikow();
	//Wariacje_na_temat_C_stringow();
	//Wskazniki_do_funkcji();
	//Cwiczenia_z_definiowania_wskaznikow_do_funkcji();
	//Tablica_wskaznikow_do_funkcji();
#if 0
	//--- �w. II ---------------
	char obj;
	char *ptr = &obj;
	*ptr = 'x';
	cout << *ptr << endl;
	//----- cw. IV ---------------
	char *wsk = 0;
	char *wsk2 = wsk;
	char &ref = obj;
	*ptr = ref;
	cout << *ptr << endl;
	// ---- �w. IX ----------
	char *wch1, *wch2;
	double *wd;
	wch1 = &obj;
	wch2 = wch1;
	wd = (double *)wch2;
	wd = reinterpret_cast<double *>(wch2);
	// ----- �w. X --------
	int *wski = reinterpret_cast<int *>(0xa2ff4);
	cout << wski << endl;
	wski = 0;
	// wska�nik mo�na por�wna� z adresem zerowym, nie trzeba wykonywa� rzutowania
	//----  �w. XII -------------
	char cc;
	void *wv = &cc;
	char *wc = reinterpret_cast<char *>(wv);
	// ------ �w. XIV -----------
	char tab[25] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'R', 'Q', 'R', 'S', 'T', 'U', 'W', 'V', 'Z'  };
	char *p = tab + 1; // &tab[1]
	i = 0;
	while(reinterpret_cast<int *>(*p) <= reinterpret_cast<int *>('Z'))
	{
		cout << *p << endl;
		p = p + 4;
	}
	// ---- �w. XV, XVI -------
	static char tab2[90];
	char *xv = &tab2[25];
	xv = xv - 30;
	xv = xv + 6;
	xv = xv + 100;
	// jest mo�liwe takie przesuni�cie, ale wska�nik b�dzie pokazywa� na nie wiadomo co i to spowoduje b��d
	// kompilator nie zaprotestuje, b��d pojawi si� kiedy b�dziemy chcieli wykorzysta� te dane i nie b�d� tym czym chcieli�my
	// --- �w. XVII ----------------
	char tC[10];
	long tL[10];
	char *pC = tC;
	long *pL = tL;
	pC = pC + 4;
	pL = pL + 4;
	// --- �w. XVIII ---------
	int kalibracja[10];
	// nazwa tablicy jest zarazem adresem jej zerowego elementu (pocz�tku tablicy)
	cout << kalibracja << endl;
	// ----- �w. XX -------
	double tabD[50];
	double *wskA = &tabD[10];
	double *wskB = &tabD[40];
	cout << wskB - wskA << " " << wskA - wskB << endl;
	// wynikiem jest liczba b�d�ca r�nic� dw�ch adres�w pokazywanch element�w
	// -------- �w. XXIX
	int jkl[9] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	for(int i = 0; i < 8; i++) cout << jkl[i] << " ";
	cout << endl;
	zerowanie(jkl); zerowanie(jkl+3); zerowanie(jkl+4); zerowanie(jkl+7);
	for(int i = 0; i < 8; i++) cout << jkl[i] << " ";
	cout << endl;
	// ------ �w. XXX ------------
	static int xxx[20];
	dodaj(xxx, 20);
	dodaj(xxx, 5);
	// ---- �w. XXXI -----------
	static const double dbl[5] = { 1.4565, 2.42, 533, 34.23453};
	cout << dbl[0] << endl;
	const double pi = 3.14;
	cout << pi << endl;
	wypisz(dbl, 5);
	cout << sizeof(dbl) << endl;
	// ---- �w. XXXIII, XXXIV ---------
	/*double *tdbl1 = new double[20];
	double *tdbl2 = new double[20];
	double *tdbl3 = new double[20];*/
	double *tdbl1 = kreator_tablicy(20);
	double *tdbl2 = kreator_tablicy(20);
	double *tdbl3 = kreator_tablicy(20);
	
	for(int i = 0; i < 20; i++) *(tdbl1 + i) = i+1;
	for(int i = 0; i < 20; i++) *(tdbl2 + i) = pow(i+1, 2);
	
	multi_tabs(tdbl1, tdbl2, tdbl3, 20);
	
	for(int i = 0; i < 20; i++) cout << *(tdbl1 + i) << " "; cout << endl;
	for(int i = 0; i < 20; i++) cout << *(tdbl2 + i) << " "; cout << endl;
	for(int i = 0; i < 20; i++) cout << *(tdbl3 + i) << " "; cout << endl;
	
	delete [] tdbl1; delete [] tdbl2; delete [] tdbl3;
	// ------ �w. XXXVII
	//cout << static_cast<int>('F') << " " << static_cast<int>('A') << " " << static_cast<int>('a') << static_cast<int>('0') << endl;
	//cout << static_cast<int>('F'-'@') << endl;
	//-------- �w. XLIII ---------
	//int *const wa = new int;
	//const int *wb = new int(8);
	//int m = 4;
	//wa = 10; // przede wszystkim brakuje reinterpret_cast i to jest sta�y wska�nik, kt�rego nie mo�na przesuwa�, w dodatku do tego wska�nika nie wolno niczego przypisywa�
	//wb = 10; // brakuje reinterpret_cast, wska�nik do sta�ej mo�na przesuwa�, przypisa� mu inny adres
	//*wa = 10; // wska�nik pokazuje na jedno miejsce i mo�na tam przypisa� inn� warto��
	//*wb = 10; // wska�nik uwa�a pokazywany obiekt za sta�y, nie mo�na przypisa� mu innej warto�ci
	//wa = &m; // nie mo�na przypisa� niczego do sta�ego wska�nika
	//wb = &m; // od teraz wb uwa�a obiekt m za sta�y (mo�e to jest ryzykowne poniewa� bezpowrotnie tracimy adres obiektu utworzonego operatorem new)
	//delete wa;
	//delete wb;
	// ---- �w. XLIV ---------
	//int *wsk; 
	//*wsk = 0; // deklarujemy wska�nik wsk i wpisujemy do niego warto�� 0, jest to b��dne poniewa� wska�nik pokazuje na niewiadome miejsce w pami�ci
	//int *wsk = 0; // inicjalizujemy wska�nik adresem 0, poprawne
	// ---- �w. XLV ----------
	const char *wskc = "Napis"; // wska�nik do sta�ej typu char o warto�ci "Napis", kt�ra jest gdzie� w pami�ci
	// ----- �w. XLVI ----------
	//int obiekt = 100;
	//int *intw;
	//const int *Cintw;
	//int * const intCw = &obiekt;
	//const int * const CintCw = &obiekt;

	//intw = Cintw; // kompilator nie pozwoli na pokazywanie na obiekt, kt�ry jest uwa�any za sta�y, przez zwyk�y wska�nik, odwrotnie jak najbardziej
	//intw = intCw; // zwyk�y wska�nik pokazuje w to samo miejsce, co nieruchomy wska�nik
	//intw = CintCw; // niejawne przypisanie zwyk�ego wska�nika do obiektu uwa�anego za sta�y
	//Cintw = intw; // od tej pory wska�nik do obiektu sta�ego pokazuje w to samo miejsce co zwyk�y wska�nik
	//Cintw = intCw; // ta sama sytuacja co wy�ej, przepisanie adresu nieruchomego wska�nika do innego wska�nika
	//Cintw = CintCw; // przepisanie adresu ze sta�ego wska�nika do obiektu sta�ego do wska�nika do obiektu sta�ego
	//CintCw = intw; // nie mo�na przypisa� do sta�ego wska�nika czegokolwiek (jedynie mo�na go zainicjalizowa�)
	//CintCw = Cintw; // ------- || --------
	//CintCw = intCw; // ------- || --------
	// -------- �w. XLVII ------------
	unsigned char *uct[100];
	// ----- �w. XLVIII --------
	XLVIII();
	// ----- �w. L ----------
	char napis[35] = { "jakis dlugi napis cos tam bla bla" };
	char *wsk_do_napis = napis;
	cout << napis << endl;
	cout << L(wsk_do_napis, 35) << endl;
	// ----- �w. LIV -----
	cout << F(c) << endl;
	// ----- �w. LV
	int (*wF)(int (*w)()) = &F;
	//cout << F << endl;
	cout << (*wF)(b) << endl;
	// ----- �w. LVI ------
	double * (*wo)() = &o;
	cout << (*wo)() << " (*wo)" << endl;
	// ----- �w. LIX ------
	void (*r)(int) = u; // musi by� int w argumencie
	(*r)(1);
	u();
#endif
	// ----- �w. LXIII -------
	LXIII();
	// ----- �w. LXV ---------
	/*cout << "Wydruk parametrow wywolania:" << endl;
	cout << "Parametr nr " << 0 << " to C-string: \"" << argv[0] << "\" oraz nazwa programu. " << endl;

	for(int i = 1; i < argc; i++)
	{
		cout << "Parametr nr " << i << " to C-string: " << argv[i] << endl;
	}
	*/

	system("pause");
}
//******************************************************************************************************
void u(int m)
{
	cout << m << endl;
}
//******************************************************************************************************
double * o()
{
	double *w = reinterpret_cast<double *>(2345878);
	return w;
}
//******************************************************************************************************

