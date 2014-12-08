#include <iostream>

using namespace std;

void modulo(){
	for(int i=0; i<64; i=i+1){
		if(i%8)
			cout << "\t";
		else
			cout << "\n";
		cout << i;
	}
}