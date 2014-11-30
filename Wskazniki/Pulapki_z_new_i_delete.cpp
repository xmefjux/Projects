#include <iostream>

using namespace std;
//******************************************************************************************************

// Za pomoc� operatora delete (lub delete[]) - powinno si� kasowa� tylko obiekty stworzone operatorem new (lub new[]).
// Pr�ba skasowania czegokolwiek innego mo�e si� okaza� katastrofalna.

//******************************************************************************************************
void Pulapki_z_new_i_delete()
{
	int *wsk;
	wsk = new int;
	*wsk = 15;
	delete wsk;
	wsk = 0;		// czyli NULL
	// ...
	delete wsk;		// skoro wsk ma warto�� 0, to tu nie b�dzie tragedii

	int *cze, *zol; // definicja dw�ch wska�nik�w

	cze = new int;
	zol = new int;

	*cze = 100;		// �adujemy 100 do obiektu A
	*zol = 200;		// �adujemy 200 do obiektu B

	cout << "Po wpisaniu: Na czerwonym = " << *cze
		 << " Na zoltym = " << *zol << endl;

	cze = zol;		// niefortunna linijka - cze pokazuje na ten sam obiekt co zol, adres obiektu pokazywanego przez cze jest utracony na zawsze, nie mo�na go ju� skasowa�

	cout << "Po przelozeniu - Na czerwonym = " << *cze
		 << " Na zoltym = " << *zol << endl;

	*cze = 5;
	*zol = 1;

	cout << "Jakis wpis - Na czerwonym = " << *cze
		 << " Na zoltym = " << *zol << endl;

	delete zol;
	//delete cze;		// Horror!

	// Komentarz do przypisania jednego wska�nika do drugiego:
	// Utrata kontaktu z obiektem uniemo�liwia nam skasowanie go. Je�li to tylko jeden taki obiekt, to ma�a strata.
	// Je�li b�dzie sytuacja, �e wiele obiekt�w zostanie utworzonych i nieskasowanych (np. w p�tli), to w ko�cu wyczerpiemy przyznany nam zapas pami�ci (free store).
	// Przez co nie b�dziemy mogli ju� tworzy� �adnych nowych obiekt�w.
}
