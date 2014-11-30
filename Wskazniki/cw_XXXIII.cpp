#include <iostream>
using namespace std;

void multi_tabs(double *ptr1, double *ptr2, double *ptr3, int size);

void multi_tabs(double *ptr1, double *ptr2, double *ptr3, int size)
{
	for(int i = 0; i < size; i++)
	{
		(*(ptr3 + i)) = (*(ptr1 + i)) * (*(ptr2 + i));
	}
}