#include <iostream>

using namespace std;

// rekurencja bezpo�rednia - kiedy funkcja wykonuje sam� siebie
// rekurencja po�rednia    - kiedy funkcja wywo�uje inn� funkcj�, kt�ra z kolei wywo�uje t� pierwsz�

int sumator(int jeszcze_krokow, int suma_dotychczas = 0);
void dwojkowo(int liczba);
void schodki(int ile, char znak);
//***************************************************************************
void main_rekurencja()
{
	cout << "Ile liczb zsumowac: ";
	int n = 0;
	cin >> n;

	cout << "Suma pierwszych " << n << " liczb naturalnych to = "
		 << sumator(n-1)
		 << endl;
	//----------------------------------------------
	// zupe�nie inny przyk�ad funkcji rekurencyjnej
	//----------------------------------------------
	int liczba = 273;
	cout << endl << liczba << " to dwojkowo ";
	dwojkowo(liczba);
	cout << endl;

	liczba = 432932;
	cout << endl << liczba << " to dwojkowo ";
	dwojkowo(liczba);
	cout << endl;
}
//***************************************************************************
int sumator(int jeszcze_krokow, int suma_dotychczas)
{
	int rezultat = 0;

	static int krok_rekurencji;
	krok_rekurencji++;

	int to_pietro_nr = krok_rekurencji;
	schodki(to_pietro_nr, '>');

	cout << suma_dotychczas << " + " << to_pietro_nr << " = "
		 << (suma_dotychczas + to_pietro_nr)
		 << endl;

	// w�a�ciwa operacja sumowania, kt�ra przesy�a sum� do nast�pnego wywo�ania rekurencji
	suma_dotychczas += to_pietro_nr;

	// warunek zatrzymuj�cy rekurencj� ++++++
	if(jeszcze_krokow)
	{
		// kontynuujemy wywo�ania rekurencyjne
		rezultat = sumator(jeszcze_krokow-1, suma_dotychczas);
	}
	else
	{
		// zatrzymujemy
		cout << ".........to ostatni krok, wracamy.........." << endl;
		rezultat = suma_dotychczas;
	}
	//++++++++++++++++++++++++++++++++++++++++++
	schodki(to_pietro_nr, '<');
	cout << endl;
	krok_rekurencji--;
	return rezultat;
}
//***************************************************************************
// przerobi� to tak, �eby bity grupowa� w czw�rki, cw_XLI
void dwojkowo(int liczba)
{
	int x = 0;					// zmienna do przechwycenia maksymalnej warto�ci licznika

	static int krok;			// liczba wywo�a� rekurencji, licznik
	krok++;						// co wywo�anie licznik +1
	
	int reszta = liczba % 2;	// w�a�ciwe dzia�anie funkcji, obliczanie warto�ci bitowej liczby

	if(liczba > 1)
	{
		dwojkowo(liczba / 2);	// wywo�anie rekurencyjne
	}
	else
	{
		x = krok;				// zachowaj najwy�sz� warto�� kroku, w else s� ostatnie instrukcje rekurencji przed powrotami
	}
	// ---------------- powroty ---------------------
	if(krok % 4 || x == krok)	// zaczynaj� si� powroty, x b�dzie r�wny krokowi tylko przy pierwszym wypisaniu (pierwszym powrocie) to tylko po to, �eby si� pozby� zb�dnej spacji
	{
		cout << reszta;			// wypisz warto�� reszty (bity 0 lub 1)
	}
	else						// gdy krok % 4 = 0, wypisz spacj�			
	{
		cout << " " << reszta;
	}

	krok--;						// zmniejszanie licznika przy powrotach rekurencji
	//return ;
}
//***************************************************************************
void schodki(int ile, char znak)
{
	cout << ile << " pietro: ";
	for(int m = 0; m < ile; m++)
	{
		cout << znak << " ";
	}
}
//***************************************************************************//***************************************************************************
// Drugie wywo�anie (tej samej funkcji poprzez rekurencj�) spowoduje, �e na stosie pojawi� si� nowe zmienne automatyczne -
// b�d�ce w�asno�ci� tego drugiego wywo�ania. Oczywi�cie b�d� to zupe�nie odr�bne zmienne.
// Je�li wewn�trz funkcji rekurencyjnej zdefiniujemy obiekt z przydomkiem static, b�dzie on wsp�lny dla wszystkich rekurencyjnych wywo�a� tej funkcji
// B�dzie mia� tak� sam� warto�� w kolejnym wywo�aniu jak� mia� w poprzednim wywo�aniu
//***************************************************************************//***************************************************************************
// W zasadzie wszystkie instrukcje znajduj�ce si� po warunku zatrzymania rekurencji zostan� wykonane w czasie powrot�w z zagnie�d�e�
// Rekurencja sk�ada si� z wywo�a� i powrot�w, czyli jakby z�o�enie dw�ch p�tli for:
// for(int i = poczatek; i <= koniec; i++) p�tla wst�puj�ca
// for(int i = koniec; i >= poczatek; i--) p�tla powrot�w
// W przypadku rekurencji dany poziom ma sw�j w�asny zestaw zmiennych, kt�rym mo�e nada� jakie� warto�ci obliczone przy wstepowaniu, a skorzysta� z nich w trakcie powrot�w.
// 
