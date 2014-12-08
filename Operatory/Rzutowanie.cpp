#include <iostream>
#include "my_file.h"

#define mmio32(x)	(*(volatile unsigned long *)(x))

using namespace std;

// tradycyjne (nie zalecane) rzutowanie:
// (nazwa_innego_typu)wyra¿enie
// nazwa_innego_typu(wyra¿enie)

void rzut()
{
	//int duzy = 0xffff;
	//char maly;
	//maly = (char) duzy;
	// duzy = 1111 1111 1111 1111 = 2 bajty zostan¹ zapisane do char o rozmiarze 1 bajta
	// informacja zostanie okrojona do mniej znacz¹cych bitów (8 bitów)

	// nowe operatory rzutowania:
	// static_cast<nazwa_innego_typu> (wyrazenie)
	// const_cast<nazwa_innego_typu> (wyrazenie)
	// dynamic_cast<nazwa_innego_typu> (wyrazenie)
	// reinterpret_cast<nazwa_innego_typu> (wyrazenie)

	double pi = 3.14;
	int m;
	
	// rzutowanie static_cast jest rzutowaniem jawnym
	// zapewniamy w ten sposób kompilator, ¿e wiemy jakiego typu bêdzie w danym miejscu obiekt i bierzemy za to odpowiedzialnoœæ
	// u¿ywaj¹c tego rzutowania mówimy, ¿e w tym miejscu takie rzutowanie ma sens

	m = static_cast<int>(pi);

	cout << "obcieta do czesci calkowitej wartosc pi = "
		 << static_cast<int>(pi) << endl
		 << "oryginalna wartosc pi = " << pi << endl;

	volatile int x_vol;
	int x_int;

	x_int = static_cast<int>(x_vol);

	const int szesc = 6;
	const int *wsk_c = &szesc;
	int *wsk_norm;
	wsk_norm = const_cast<int*>(wsk_c);

	int *addr = (int*)0x28ff44;

	unsigned long registerValue = mmio32(SFR_1);
	mmio32(SFR_2) = 0x543654353;


	// rzutowanie const_cast
	// const_cast<typ_bez_const> (wyrazenie o typie z const)
	// tego rzutowania najczêœciej uzywa siê wobec wskaŸników
	// ten operator mo¿e s³u¿yæ jedynie do nadania lub pozbycia siê przydomka const
	// ten operator s³u¿y te¿ do usuwania/dodawania przydomka volatile

	// dynamic_cast
	// operator dynamic_cast zrobi rzutowanie tylko pod warunkiem, ¿e w danej konkretnej chwili ma to sens.
	// Jeœli nie jest mo¿liwe - poinformuje nas o tym (ju¿ w trakcie wykonywania programu).
	// static_cast sprawdza w trakcie pracy kompilatora, dynamic_cast w trakcie pracy programu

	// operator reinterpret_cast
	// ten operator pozwala na rzutowanie jednego typu wskaŸnika na drugi
	// np. adr_char przechowuje adres obiektu typu char, a obiekt adr_walec nadaje siê tylko do przechowywania adresów obiektów typu walec_drogowy
	// niedopuszczalne jest: adr_walec = adr_char;
	// mo¿na (podobnie jak w static_cast) na w³asn¹ odpowiedzialnoœæ: adr_walec = reinterpret_cast<walec_drogowy*>(adr_char);
	// nie ró¿ni siê to niczym od tradycyjnego (ryzykownego) rzutowania, poza sposobem zapisu, który jest ³atwiejszy do wychwycenia

	// operator przecinek
	// Jeœli kilka wyra¿eñ stoi obok siebie oddzielone przecinkiem, to ta ca³oœæ jest tak¿e wyra¿eniem, którego wartoœci¹ jest wartoœæ wyra¿enia bêd¹cego najbardziej
	// z prawej. Np. (2 + 4, a * 4, 3 < 6, 77 + 2) ma wartoœæ 79. Poszczególne wyra¿enia s¹ obliczane od lewej do prawej. Wyra¿enie po prawej stronie przecinka
	// mo¿e ju¿ korzystaæ z wyniku wyra¿enia po lewej stronie przecinka.
	// Nie myliæ tego przecinka z przecinkiem oddzielaj¹cym argumenty funkcji.

	// ³¹cznoœæ operatorów
	// operatory jednoargumentowe s¹ prawostronnie ³¹czne np. !x
	// operatory dwuargumentowe s¹ lewostronnie ³¹czne (operator przypisania jest prawostronnie ³¹czny)
	
	int x;
	double y;

	int * wsk_int = &x;
	double * wsk_double = &y;

	wsk_double = reinterpret_cast<double*>(wsk_int);




}