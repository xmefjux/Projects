/* Skoro wskaŸniki przed ich pierwszym u¿yciem powinny byæ ustawione - jak to zrobiæ?
 
 Najwa¿niejsze sposoby ...

 1. WskaŸnik mo¿na ustawiæ tak, bo pokazywa³ na jakiœ obiekt, wstawiaj¹c do niego adres wybranego obiektu

	wsk = &obiekt;

 2. WskaŸnik mo¿na ustawiæ równie¿ na to samo, co pokazuje ju¿ inny wskaŸnik tego samego typu. Jest to zwyk³a operacja przypisania wskaŸników.

	wsk = inny_wskaznik;

 3. WskaŸnik mo¿na ustawiæ na to samo, na co pokazuje ju¿ inny wskaŸnik innego, zupe³nie obcego typu. (Obcego ale nie-const).
	Jeœli jesteœ przekonany, ¿e taka operacja ma sens, to mo¿esz j¹ przeprowadziæ za pomoc¹ rzutowania operatorem reinterpret_cast

	double *wsk = reinterpret_cast<double*>(obcy_wskaznik);

 4. WskaŸnik typu void mo¿na ustawiæ na to samo, co pokazuje inny wskaŸnik (nie-const). Do tego nie trzeba rzutowania (wiedza, o typie, jest zapominana).

	void *wsk = inny_wsk_nie_const;

 5. WskaŸnik ustawia siê na pocz¹tek jakiejœ tablicy podstawiaj¹c do niego jej adres. Skoro wiemy, ¿e nazwa tablicy jest równoczeœnie adresem jej zerowego elementu,
	zatem w zapisie niepotrzebny jest operator &.

	wsk = tablica;

 6. WskaŸnik mo¿e pokazywaæ tak¿e na funkcjê. Nazwa funkcji to te¿ jej adres.

	wskf = funkcja;

 7. Operator new zwraca adres w³aœnie stworzonego nowego obiektu. Taki adres natychmiast wpisujemy do wskaŸnika. Od tej pory wskaŸnik pokazuje na ten nowy obiekt.

	double *wsk;
	wsk = new double;

 8. WskaŸnik mo¿na ustawiæ te¿ tak, by pokazywa³ na jakieœ konkretne miejsce w pamiêci.

	int *wsk;
	wsk = reinterpret_cast<int*>(0x3007304);

 9. WskaŸnik mo¿na ustawiæ tak, bo pokazywa³ na adres zero. Do przypisania wartoœci liczbowej tego specjalnego adresu - nie trzeba przypisania.

	wsk = 0;

 10. Jeœli wskaŸnik ma pokazywaæ na ci¹g znaków bêd¹c¹ sta³¹ dos³own¹ typu C-string - mo¿na ustawiæ go w ten sposób

	const char *wsk;
	wsk = "taki napis";

*/