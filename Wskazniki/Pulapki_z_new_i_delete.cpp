#include <iostream>

using namespace std;
//******************************************************************************************************

// Za pomoc¹ operatora delete (lub delete[]) - powinno siê kasowaæ tylko obiekty stworzone operatorem new (lub new[]).
// Próba skasowania czegokolwiek innego mo¿e siê okazaæ katastrofalna.

//******************************************************************************************************
void Pulapki_z_new_i_delete()
{
	int *wsk;
	wsk = new int;
	*wsk = 15;
	delete wsk;
	wsk = 0;		// czyli NULL
	// ...
	delete wsk;		// skoro wsk ma wartoœæ 0, to tu nie bêdzie tragedii

	int *cze, *zol; // definicja dwóch wskaŸników

	cze = new int;
	zol = new int;

	*cze = 100;		// ³adujemy 100 do obiektu A
	*zol = 200;		// ³adujemy 200 do obiektu B

	cout << "Po wpisaniu: Na czerwonym = " << *cze
		 << " Na zoltym = " << *zol << endl;

	cze = zol;		// niefortunna linijka - cze pokazuje na ten sam obiekt co zol, adres obiektu pokazywanego przez cze jest utracony na zawsze, nie mo¿na go ju¿ skasowaæ

	cout << "Po przelozeniu - Na czerwonym = " << *cze
		 << " Na zoltym = " << *zol << endl;

	*cze = 5;
	*zol = 1;

	cout << "Jakis wpis - Na czerwonym = " << *cze
		 << " Na zoltym = " << *zol << endl;

	delete zol;
	//delete cze;		// Horror!

	// Komentarz do przypisania jednego wskaŸnika do drugiego:
	// Utrata kontaktu z obiektem uniemo¿liwia nam skasowanie go. Jeœli to tylko jeden taki obiekt, to ma³a strata.
	// Jeœli bêdzie sytuacja, ¿e wiele obiektów zostanie utworzonych i nieskasowanych (np. w pêtli), to w koñcu wyczerpiemy przyznany nam zapas pamiêci (free store).
	// Przez co nie bêdziemy mogli ju¿ tworzyæ ¿adnych nowych obiektów.
}
