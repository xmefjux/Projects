#include <iostream>
#include <stdlib.h>
using namespace std;
//************************************************************************************************
void LXIII();
bool obrot_w_prawo(double x);
bool obrot_w_lewo(double x);
bool obrot_w_gore(double x);
bool obrot_w_dol(double x);
bool obrot_w_przod(double x);
bool obrot_w_tyl(double x);
//************************************************************************************************
void LXIII()
{
	bool (*tab_ptr[6])(double) =  { 
								&obrot_w_prawo, 
								&obrot_w_lewo, 
								&obrot_w_gore, 
								&obrot_w_dol, 
								&obrot_w_przod, 
								&obrot_w_tyl 
							};

	bool (*exec_ptr[20])(double);
	int i = 0;
	int ile_komend = 0;
	double x[20];

	int komenda;
	
		cout << "-------------- Menu -------------" << endl
			 << "\t0 - obrot w prawo" << endl
			 << "\t1 - obrot w lewo" << endl
			 << "\t2 - obrot w gore" << endl
			 << "\t3 - obrot w dol" << endl
			 << "\t4 - obrot w przod" << endl
			 << "\t5 - obrot w tyl" << endl
			 << "\t7 - wykonac" << endl
			 << "\t9 - koniec programu" << endl;
	while(1)
	{
		cout << "Podaj numer zadanej akcji: ";
		cin >> komenda;
		switch(komenda)
		{
		case 0:
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
			if(i < 20)
			{
				cout << "Podaj kat obrotu : "; cin >> x[i];
				exec_ptr[i] = tab_ptr[komenda];
				i++;
				break;
			}
			else 
			{
				cout << "Nie wykonam wiecej niz 20 polecen naraz!" << endl;
				cout << "Wykonuje zapamietane polecenia..." << endl;
				ile_komend = i;
				for(i = 0; i < ile_komend; i++)
				{
					if((*exec_ptr[i])(x[i])) cout << ". Wykonano pomyslnie!" << endl;
				}
				i = 0;
				break;
			}

		case 7:
			if(i)
			{
				cout << "Wykonuje zapamietane polecenia..." << endl;
				ile_komend = i;
				for(i = 0; i < ile_komend; i++)
				{
					if((*exec_ptr[i])(x[i])) cout << ". Wykonano pomyslnie!" << endl;
				}
				i = 0;
				break;
			}
			else 
			{
				cout << "Podaj chociaz jedno polecenie do wykonania!" << endl;
				break;
			}

		case 9:
			exit(0);

		default:
			exit(0);
		}

	}
}
//************************************************************************************************
bool obrot_w_prawo(double x)
{
	cout << "Obrot ramienia w prawo o " << x << " stopni";
	return true;
}
//************************************************************************************************
bool obrot_w_lewo(double x)
{
	cout << "Obrot ramienia w lewo o " << x << " stopni";
	return true;
}
//************************************************************************************************
bool obrot_w_gore(double x)
{
	cout << "Obrot ramienia w gore o " << x << " stopni";
	return true;
}
//************************************************************************************************
bool obrot_w_dol(double x)
{
	cout << "Obrot ramienia w dol o " << x << " stopni";
	return true;
}
//************************************************************************************************
bool obrot_w_przod(double x)
{
	cout << "Obrot ramienia w przod o " << x << " stopni";
	return true;
}
//************************************************************************************************
bool obrot_w_tyl(double x)
{
	cout << "Obrot ramienia w tyl o " << x << " stopni";
	return true;
}
//************************************************************************************************
