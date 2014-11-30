#include <iostream>

using namespace std;

enum etapy {	nic, scenopis, proba_czytana,
				proba_kamerowa, nagranie = 6,
				montaz, postsynchron };

void stan_realizacji(etapy t[], int ile, int dzien_zdjeciowy);
//************************************************************************************************
void main_Tablica_enum()
{
	const int liczba_scen = 10;
	etapy scena[liczba_scen] = { scenopis, proba_czytana, proba_kamerowa };

	int dzien_realizacji = 1;

	scena[2] = nagranie;
	scena[5] = montaz;
	scena[9] = nagranie;
	scena[4] = proba_kamerowa;
	stan_realizacji(scena, liczba_scen, dzien_realizacji);

	// ---------- nastêpnego dnia praca posunê³a siê dalej -------------
	dzien_realizacji++;

	scena[1] = proba_kamerowa;
	scena[5] = postsynchron;
	scena[0] = scenopis;
	scena[8] = scenopis;
	stan_realizacji(scena, liczba_scen, dzien_realizacji);
}
//************************************************************************************************
void stan_realizacji(etapy s[], int ile, int dzien)
{
	cout << dzien << ", dzien realizacji filmu reklamowego." << endl
		 << "Stan realizacji:" << endl;

	for(int i = 0; i < ile; i++)
	{
		cout << "Scena nr " << i << ", ";
		for(int k = 0; k < s[i]; k++)
		{
			cout << "#";
		}
		cout << endl;
	}

}
