#include <iostream>

using namespace std;

#define PODWOZIE_707		1
#define PODWOZIE_747		2
#define PODWOZIE_DC11		3
#define PODWOZIE_LIL		4


#define TYP_PODWOZIA		PODWOZIE_747
//---------------------
int wystaw_kola()
{
#if (TYP_PODWOZIA == PODWOZIE_707)
	cout << "Tak jest kapitanie, wystawiam 707" << endl;
#elif (TYP_PODWOZIA == PODWOZIE_747)
	cout << "Tak jest kapitanie, wystawiam 707" << endl;
#elif (TYP_PODWOZIA == PODWOZIE_DC11)
	cout << "Tak jest kapitanie, wystawiam 707" << endl;
#elif (TYP_PODWOZIA == PODWOZIE_LIL)
	cout << "Tak jest kapitanie, wystawiam 707" << endl;
#else
	cout << "To nigdy sie nie powinno zdarzyc!" << endl;
	#error "zle zdefiniowana wersja programu!!!!"
#endif // TYP_PODWOZIA
	return 1;
}
