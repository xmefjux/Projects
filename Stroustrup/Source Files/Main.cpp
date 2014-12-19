/*
 * Main.cpp
 *
 *  Created on: 13 gru 2014
 *      Author: xmef
 */
#include <iostream>
#include <stdio.h>

#include <stdlib.h>
using namespace std;
// własności zależne od implementacji można znaleźć w nagłówku <limits>
#include <limits>
enum typ1 { a=0, b=1 };
enum typ2 { c=-10, d=1000 };
enum typ3 { e=20, f=100000000000000000 }; // zakres typu wyliczeniowego to najmniejsze pole bitowe, które może to pomieścić
//******************************************************************************************************
extern void Vector();
//******************************************************************************************************
int main()
{
	try {
		//Vector();
		cout << "Najwieksza liczba zmiennopozycyjna == "
			 << numeric_limits<float>::max() << " , char jest ze znakiem == "
			 << numeric_limits<char>::is_signed << endl;
		// ćw. [1]
		cout << "Hej tam wszyscy!\n";
		// ćw. [3]
		cout << "-----------------------------------------------------------" << endl;
		cout << "Rozmiary typow w bajtach..." << endl;
		cout << "char: " << sizeof(char)
			 << ", int: " << sizeof(int)
			 << ", float: " << sizeof(float)
			 << ", double: " << sizeof(double) << endl
			 << "short int: "<< sizeof(short)
			 << ", long int: "<< ' ' << sizeof(long)
			 << ", long double: "<< ' ' << sizeof(long double) << endl
			 << "char*: "<< sizeof(char*)
			 << ", int*: "<< sizeof(int*)
			 << ", float*: "<< sizeof(float*)
			 << ", double*: "<< sizeof(double*) << endl // rozmiar wskaźnika jest zależny od architektury procesora -> 64bit daje 8 bajtowy wskaźnik
			 << "typ1: "<< sizeof(typ1)
			 << ", typ2: "<< sizeof(typ2)
			 << ", typ3: "<< sizeof(typ3)
			 << endl;
		cout << "-----------------------------------------------------------" << endl;
		// ćw. [4]
		char a = 'a';
		char zero = '0';
		while(a <= 'z')
		{
			cout << "Znak: " << a << " ma wartość: " << hex << uppercase << int(a) << endl;
			a++;
		}
		cout << endl;
		while(zero <= '9')
		{
			cout << "Znak: " << zero << " ma wartość: " << hex << uppercase << int(zero) << endl;
			zero++;
		}
		cout << endl;
		char pierwszy = 0x0;
		while(pierwszy != 0x7F)
		{
			cout << "Znak: " << pierwszy << " ma wartość: " << hex << uppercase << int(pierwszy) << endl;
			pierwszy++;
		}
		// ćw. [5] jakie są najmniejsze i największe wartości typów
		cout << "char min: " << numeric_limits<char>::min() << ", max: " << numeric_limits<char>::max() << endl;
		cout << "short min: " << numeric_limits<short>::min() << ", max: " << numeric_limits<short>::max() << endl;
		cout << "int min: " << numeric_limits<int>::min() << ", max: " << numeric_limits<int>::max() << endl;
		cout << "long min: " << numeric_limits<long>::min() << ", max: " << numeric_limits<long>::max() << endl;
		cout << "float min: " << numeric_limits<float>::min() << ", max: " << numeric_limits<float>::max() << endl;
		cout << "double min: " << numeric_limits<double>::min() << ", max: " << numeric_limits<double>::max() << endl;
		cout << "long double min: " << numeric_limits<long double>::min() << ", max: " << numeric_limits<long double>::max() << endl;
		cout << "unsigned min: " << numeric_limits<unsigned>::min() << ", max: " << numeric_limits<unsigned>::max() << endl;
		// ćw. [6]
		// nie ma ograniczenia co do długości nazwy lokalnej, co do nazwy zewnętrznej zależy to od implementacji
		// może zależy od architektury komputera? słowo nie dłuższe niż 64 bity?
		// ograniczenia na znaki: nie może zaczynać się cyfrą, unikać zaczynania od _ (podkreślenia), bo to jest zerezerwowane dla
		// specjalnych udogodnień dostarczanych przez implementację i środowisko czasu wykonania
		// nie można użyć słów kluczowych języka jako nazwy

	}
	catch (...) {
		cerr << "zgloszono wyjatek" << endl; // cerr standardowy strumień błędów i diagnostyki
	}
}
