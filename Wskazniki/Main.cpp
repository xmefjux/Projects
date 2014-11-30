#include <iostream>
//Êw. XXXVII
#include <new>

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

// Êw. XXIX
void zerowanie(int *wsk);
// Êw. XXX
void dodaj(int x[], int i);
// Êw. XXXI
void wypisz(const double *x, int k);
// Êw. XXXIII
void multi_tabs(double *ptr1, double *ptr2, double *ptr3, int size);
// Êw. XXXIV
double* kreator_tablicy(int size);
// Êw. XXXVII

// Êw. XLVIII
void XLVIII();
// Êw. IL
void * IL(char x[], double *(*y[]));
// Êw. L
char * L(char * x, int size);
// Êw. LII
void * (*w)(char*);
// Êw. LIII
bool fun(bool (*wx)(double, double), char (*wy)(double));
// Êw. LIV
int a(); int b();  int c();
int F(int (*w)());
// Êw. LVI
double * o();
// Êw. LIX
void u(int = 4);
// Êw. LXII
void lxii(void (*w)(int)); // nie moøe mieÊ wartoúci domniemanej
// Êw. LXIII
void LXIII();


// WSKAèNIK ZAWSZE POKAZUJE NA COå

//******************************************************************************************************
// wys≥anie parametrÛw do funkcji
// argc - argument counter - mÛwi ILE argumentÛw zosta≥o wys≥anych do programu, jest zawsze conajmniej 1 argument: nazwa programu,
// argv - argument vector, wskaünik do tablicy z C-stringami: argumentami wys≥anymi do funkcji
// uruchomienie programu Wskazniki.exe param1 77.2 wyúle do programu 3 argumenty
int main(int argc, char* argv[])
{
	//cout << "Wydruk parametrow wywolania:" << endl;

	//for(int i = 0; i < argc; i++)
	//{
	//	cout << "Parametr nr " << i << " to C-string: " << argv[i] << endl;
	//}
	///*------zamienimy C-string na liczbÍ-------*/
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

	//--- Êw. II ---------------
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
	// ---- Êw. IX ----------
	char *wch1, *wch2;
	double *wd;
	wch1 = &obj;
	wch2 = wch1;
	wd = (double *)wch2;
	wd = reinterpret_cast<double *>(wch2);
	// ----- Êw. X --------
	int *wski = reinterpret_cast<int *>(0xa2ff4);
	cout << wski << endl;
	wski = 0;
	// wskaünik moøna porÛwnaÊ z adresem zerowym, nie trzeba wykonywaÊ rzutowania
	//----  Êw. XII -------------
	char cc;
	void *wv = &cc;
	char *wc = reinterpret_cast<char *>(wv);
	// ------ Êw. XIV -----------
	char tab[25] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'R', 'Q', 'R', 'S', 'T', 'U', 'W', 'V', 'Z'  };
	char *p = tab + 1; // &tab[1]
	i = 0;
	while(reinterpret_cast<int *>(*p) <= reinterpret_cast<int *>('Z'))
	{
		cout << *p << endl;
		p = p + 4;
	}
	// ---- Êw. XV, XVI -------
	static char tab2[90];
	char *xv = &tab2[25];
	xv = xv - 30;
	xv = xv + 6;
	xv = xv + 100;
	// jest moøliwe takie przesuniÍcie, ale wskaünik bÍdzie pokazywa≥ na nie wiadomo co i to spowoduje b≥πd
	// kompilator nie zaprotestuje, b≥πd pojawi siÍ kiedy bÍdziemy chcieli wykorzystaÊ te dane i nie bÍdπ tym czym chcieliúmy
	// --- Êw. XVII ----------------
	char tC[10];
	long tL[10];
	char *pC = tC;
	long *pL = tL;
	pC = pC + 4;
	pL = pL + 4;
	// --- Êw. XVIII ---------
	int kalibracja[10];
	// nazwa tablicy jest zarazem adresem jej zerowego elementu (poczπtku tablicy)
	cout << kalibracja << endl;
	// ----- Êw. XX -------
	double tabD[50];
	double *wskA = &tabD[10];
	double *wskB = &tabD[40];
	cout << wskB - wskA << " " << wskA - wskB << endl;
	// wynikiem jest liczba bÍdπca rÛønicπ dwÛch adresÛw pokazywanch elementÛw
	// -------- Êw. XXIX
	int jkl[9] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	for(int i = 0; i < 8; i++) cout << jkl[i] << " ";
	cout << endl;
	zerowanie(jkl); zerowanie(jkl+3); zerowanie(jkl+4); zerowanie(jkl+7);
	for(int i = 0; i < 8; i++) cout << jkl[i] << " ";
	cout << endl;
	// ------ Êw. XXX ------------
	static int xxx[20];
	dodaj(xxx, 20);
	dodaj(xxx, 5);
	// ---- Êw. XXXI -----------
	static const double dbl[5] = { 1.4565, 2.42, 533, 34.23453};
	cout << dbl[0] << endl;
	const double pi = 3.14;
	cout << pi << endl;
	wypisz(dbl, 5);
	cout << sizeof(dbl) << endl;
	// ---- Êw. XXXIII, XXXIV ---------
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
	// ------ Êw. XXXVII
	//cout << static_cast<int>('F') << " " << static_cast<int>('A') << " " << static_cast<int>('a') << static_cast<int>('0') << endl;
	//cout << static_cast<int>('F'-'@') << endl;
	//-------- Êw. XLIII ---------
	//int *const wa = new int;
	//const int *wb = new int(8);
	//int m = 4;
	//wa = 10; // przede wszystkim brakuje reinterpret_cast i to jest sta≥y wskaünik, ktÛrego nie moøna przesuwaÊ, w dodatku do tego wskaünika nie wolno niczego przypisywaÊ
	//wb = 10; // brakuje reinterpret_cast, wskaünik do sta≥ej moøna przesuwaÊ, przypisaÊ mu inny adres
	//*wa = 10; // wskaünik pokazuje na jedno miejsce i moøna tam przypisaÊ innπ wartoúÊ
	//*wb = 10; // wskaünik uwaøa pokazywany obiekt za sta≥y, nie moøna przypisaÊ mu innej wartoúci
	//wa = &m; // nie moøna przypisaÊ niczego do sta≥ego wskaünika
	//wb = &m; // od teraz wb uwaøa obiekt m za sta≥y (moøe to jest ryzykowne poniewaø bezpowrotnie tracimy adres obiektu utworzonego operatorem new)
	//delete wa;
	//delete wb;
	// ---- Êw. XLIV ---------
	//int *wsk; 
	//*wsk = 0; // deklarujemy wskaünik wsk i wpisujemy do niego wartoúÊ 0, jest to b≥Ídne poniewaø wskaünik pokazuje na niewiadome miejsce w pamiÍci
	//int *wsk = 0; // inicjalizujemy wskaünik adresem 0, poprawne
	// ---- Êw. XLV ----------
	const char *wskc = "Napis"; // wskaünik do sta≥ej typu char o wartoúci "Napis", ktÛra jest gdzieú w pamiÍci
	// ----- Êw. XLVI ----------
	//int obiekt = 100;
	//int *intw;
	//const int *Cintw;
	//int * const intCw = &obiekt;
	//const int * const CintCw = &obiekt;

	//intw = Cintw; // kompilator nie pozwoli na pokazywanie na obiekt, ktÛry jest uwaøany za sta≥y, przez zwyk≥y wskaünik, odwrotnie jak najbardziej
	//intw = intCw; // zwyk≥y wskaünik pokazuje w to samo miejsce, co nieruchomy wskaünik
	//intw = CintCw; // niejawne przypisanie zwyk≥ego wskaünika do obiektu uwaøanego za sta≥y
	//Cintw = intw; // od tej pory wskaünik do obiektu sta≥ego pokazuje w to samo miejsce co zwyk≥y wskaünik
	//Cintw = intCw; // ta sama sytuacja co wyøej, przepisanie adresu nieruchomego wskaünika do innego wskaünika
	//Cintw = CintCw; // przepisanie adresu ze sta≥ego wskaünika do obiektu sta≥ego do wskaünika do obiektu sta≥ego
	//CintCw = intw; // nie moøna przypisaÊ do sta≥ego wskaünika czegokolwiek (jedynie moøna go zainicjalizowaÊ)
	//CintCw = Cintw; // ------- || --------
	//CintCw = intCw; // ------- || --------
	// -------- Êw. XLVII ------------
	unsigned char *uct[100];
	// ----- Êw. XLVIII --------
	XLVIII();
	// ----- Êw. L ----------
	char napis[35] = { "jakis dlugi napis cos tam bla bla" };
	char *wsk_do_napis = napis;
	cout << napis << endl;
	cout << L(wsk_do_napis, 35) << endl;
	// ----- Êw. LIV -----
	cout << F(c) << endl;
	// ----- Êw. LV
	int (*wF)(int (*w)()) = &F;
	//cout << F << endl;
	cout << (*wF)(b) << endl;
	// ----- Êw. LVI ------
	double * (*wo)() = &o;
	cout << (*wo)() << " (*wo)" << endl;
	// ----- Êw. LIX ------
	void (*r)(int) = u; // musi byÊ int w argumencie
	(*r)(1);
	u();
	// ----- Êw. LXIII -------
	//LXIII();
	// ----- Êw. LXV ---------
	cout << "Wydruk parametrow wywolania:" << endl;
	cout << "Parametr nr " << 0 << " to C-string: \"" << argv[0] << "\" oraz nazwa programu. " << endl;

	for(int i = 1; i < argc; i++)
	{
		cout << "Parametr nr " << i << " to C-string: " << argv[i] << endl;
	}


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

