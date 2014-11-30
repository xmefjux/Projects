#include <iostream>
using namespace std;
#include <new>

void XLVIII();

void XLVIII()
{
	//char chuj[80] = { "asd" };
	//char *linijka[10];
	//linijka[0] = chuj;
	//cout << *linijka << endl;
	//for(int i = 0; i < 10; i++) (linijka[i]) = new char[80];
	//for(int i = 0; i < 10; i++) linijka[i] = { "asd" };
	//for(int i = 0; i < 10; i++) cout << *(linijka++) << endl;

	
	//*cos = chuj;
	//cout << *cos << endl;

	char x[11] = "0123456789";
	char y[20];

	strcpy_s(y, x);

	cout << y << endl;

	char *(*linijka) = new char*[10];

	for(int i = 0; i < 10; i++)
	{
		(linijka[i]) = new char[80];
	}
	// wygl¹da na to, ¿e wskaŸnik przesuwa siê ci¹gle dalej, nie wiem jak go spowrotem ustawiæ na pozycji 0
	for(int i = 0; i < 10; i++)
	{
		//strcpy_s(linijka[i], 80, "to jest linijka nr ");
		//strcat_s(linijka[i], 1, );
		//strcat_s(linijka[i], x);
		sprintf_s(linijka[i], 80,  "to jest linijka nr %d", i);
	}

	for(int i = 0; i < 10; i++)
	{
		cout << (linijka[i]) << endl;
	}

	char *temp = linijka[5];

	linijka[5] = linijka[2];

	linijka[2] = temp;

	cout << endl;

	for(int i = 0; i < 10; i++)
	{
		cout << (linijka[i]) << endl;
	}

	for(int i = 0; i < 10; i++) 
	{
		delete [] linijka[i];
	}

	delete [] linijka;

	//int abc;

	// czy na funkcjê z argumentem domniemanym
	
	// mo¿na pokazaæ wskaŸnikiem void(*w)();

	//void(*w)(int) = &f;
	//w();
}
