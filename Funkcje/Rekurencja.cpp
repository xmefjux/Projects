#include <iostream>

using namespace std;

// rekurencja bezpoœrednia - kiedy funkcja wykonuje sam¹ siebie
// rekurencja poœrednia    - kiedy funkcja wywo³uje inn¹ funkcjê, która z kolei wywo³uje t¹ pierwsz¹

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
	// zupe³nie inny przyk³ad funkcji rekurencyjnej
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

	// w³aœciwa operacja sumowania, która przesy³a sumê do nastêpnego wywo³ania rekurencji
	suma_dotychczas += to_pietro_nr;

	// warunek zatrzymuj¹cy rekurencjê ++++++
	if(jeszcze_krokow)
	{
		// kontynuujemy wywo³ania rekurencyjne
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
// przerobiæ to tak, ¿eby bity grupowaæ w czwórki, cw_XLI
void dwojkowo(int liczba)
{
	int x = 0;					// zmienna do przechwycenia maksymalnej wartoœci licznika

	static int krok;			// liczba wywo³añ rekurencji, licznik
	krok++;						// co wywo³anie licznik +1
	
	int reszta = liczba % 2;	// w³aœciwe dzia³anie funkcji, obliczanie wartoœci bitowej liczby

	if(liczba > 1)
	{
		dwojkowo(liczba / 2);	// wywo³anie rekurencyjne
	}
	else
	{
		x = krok;				// zachowaj najwy¿sz¹ wartoœæ kroku, w else s¹ ostatnie instrukcje rekurencji przed powrotami
	}
	// ---------------- powroty ---------------------
	if(krok % 4 || x == krok)	// zaczynaj¹ siê powroty, x bêdzie równy krokowi tylko przy pierwszym wypisaniu (pierwszym powrocie) to tylko po to, ¿eby siê pozbyæ zbêdnej spacji
	{
		cout << reszta;			// wypisz wartoœæ reszty (bity 0 lub 1)
	}
	else						// gdy krok % 4 = 0, wypisz spacjê			
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
// Drugie wywo³anie (tej samej funkcji poprzez rekurencjê) spowoduje, ¿e na stosie pojawi¹ siê nowe zmienne automatyczne -
// bêd¹ce w³asnoœci¹ tego drugiego wywo³ania. Oczywiœcie bêd¹ to zupe³nie odrêbne zmienne.
// Jeœli wewn¹trz funkcji rekurencyjnej zdefiniujemy obiekt z przydomkiem static, bêdzie on wspólny dla wszystkich rekurencyjnych wywo³añ tej funkcji
// Bêdzie mia³ tak¹ sam¹ wartoœæ w kolejnym wywo³aniu jak¹ mia³ w poprzednim wywo³aniu
//***************************************************************************//***************************************************************************
// W zasadzie wszystkie instrukcje znajduj¹ce siê po warunku zatrzymania rekurencji zostan¹ wykonane w czasie powrotów z zagnie¿d¿eñ
// Rekurencja sk³ada siê z wywo³añ i powrotów, czyli jakby z³o¿enie dwóch pêtli for:
// for(int i = poczatek; i <= koniec; i++) pêtla wstêpuj¹ca
// for(int i = koniec; i >= poczatek; i--) pêtla powrotów
// W przypadku rekurencji dany poziom ma swój w³asny zestaw zmiennych, którym mo¿e nadaæ jakieœ wartoœci obliczone przy wstepowaniu, a skorzystaæ z nich w trakcie powrotów.
// 
