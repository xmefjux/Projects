#include <iostream>

void funkcja();
void cwiczenie();
void cwiczenie2();

#ifdef __cplusplus
#define TAK		"jest cep"
#endif // __cplusplus


int main()
{
	std::cout << "Witamy \nna pokladzie";
	std::cout << "Lecimy na " << "wysokosci 3500 stop";
	std::cout << "\n" 
		<< "Plik programu: " << __FILE__
		<< ", linia: "		 << __LINE__
		<< ", data: "		 << __DATE__
		<< ", czas: "		 << __TIME__
		<< ", czy cplus: "	 << TAK
		<< "\n";
	//funkcja();
	//cwiczenie();
	//cwiczenie2();
	// wysokosc = 660; // proba nieudana
}
