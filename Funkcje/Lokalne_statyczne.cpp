#include <iostream>

using namespace std;

extern int a; // zmienna a z pliku Main.cpp, s�owo kluczowe extern umo�liwia korzystanie ze zmiennej globalnej z innych plik�w

/*------------------------ deklaracje funkcji -----------------------------*/
void czerwona(void);
void biala(void);
//****************************************************************************
void main_lokalne_stat()
{
	czerwona();
	czerwona();
	biala();
	czerwona();
	biala();
}
//****************************************************************************
void czerwona(void)
{
	static int ktory_raz;
	ktory_raz++;
	cout << "Funkcja czerwona wywolana " << ktory_raz << " raz" << endl;
}
//****************************************************************************
void biala()
{
	static int ktory_raz = 100;
	ktory_raz = ktory_raz + 1;
	cout << "Funkcja biala wywolana " << ktory_raz << " raz" << endl;
}
//****************************************************************************
// gdy chcemy, by zmienna lokalna (obiekt automatyczny funkcji) mia� �ywotno�� obiektu globalnego, do jego deklaracji dopisujemy s�owo kluczowe static (specyfikator, modyfikator)
// wtedy zmienna lokalna nie jest zapisywana na stosie, tylko w pami�ci i jest inicjalizowana warto�ci� zerow�