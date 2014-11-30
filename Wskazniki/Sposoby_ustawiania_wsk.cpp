/* Skoro wska�niki przed ich pierwszym u�yciem powinny by� ustawione - jak to zrobi�?
 
 Najwa�niejsze sposoby ...

 1. Wska�nik mo�na ustawi� tak, bo pokazywa� na jaki� obiekt, wstawiaj�c do niego adres wybranego obiektu

	wsk = &obiekt;

 2. Wska�nik mo�na ustawi� r�wnie� na to samo, co pokazuje ju� inny wska�nik tego samego typu. Jest to zwyk�a operacja przypisania wska�nik�w.

	wsk = inny_wskaznik;

 3. Wska�nik mo�na ustawi� na to samo, na co pokazuje ju� inny wska�nik innego, zupe�nie obcego typu. (Obcego ale nie-const).
	Je�li jeste� przekonany, �e taka operacja ma sens, to mo�esz j� przeprowadzi� za pomoc� rzutowania operatorem reinterpret_cast

	double *wsk = reinterpret_cast<double*>(obcy_wskaznik);

 4. Wska�nik typu void mo�na ustawi� na to samo, co pokazuje inny wska�nik (nie-const). Do tego nie trzeba rzutowania (wiedza, o typie, jest zapominana).

	void *wsk = inny_wsk_nie_const;

 5. Wska�nik ustawia si� na pocz�tek jakiej� tablicy podstawiaj�c do niego jej adres. Skoro wiemy, �e nazwa tablicy jest r�wnocze�nie adresem jej zerowego elementu,
	zatem w zapisie niepotrzebny jest operator &.

	wsk = tablica;

 6. Wska�nik mo�e pokazywa� tak�e na funkcj�. Nazwa funkcji to te� jej adres.

	wskf = funkcja;

 7. Operator new zwraca adres w�a�nie stworzonego nowego obiektu. Taki adres natychmiast wpisujemy do wska�nika. Od tej pory wska�nik pokazuje na ten nowy obiekt.

	double *wsk;
	wsk = new double;

 8. Wska�nik mo�na ustawi� te� tak, by pokazywa� na jakie� konkretne miejsce w pami�ci.

	int *wsk;
	wsk = reinterpret_cast<int*>(0x3007304);

 9. Wska�nik mo�na ustawi� tak, bo pokazywa� na adres zero. Do przypisania warto�ci liczbowej tego specjalnego adresu - nie trzeba przypisania.

	wsk = 0;

 10. Je�li wska�nik ma pokazywa� na ci�g znak�w b�d�c� sta�� dos�own� typu C-string - mo�na ustawi� go w ten spos�b

	const char *wsk;
	wsk = "taki napis";

*/