#include "Persoana.hpp"
#include <iostream>
using namespace std;

int compare(const void* a, const void *b)
{
	Persoana* x = *(Persoana**) a;
	Persoana* y = *(Persoana**) b;

	if (x->GetVenit() > y->GetVenit())
		return 1;
	else if (x->GetVenit() < y->GetVenit())
		return -1;

	return 0;
}

void sortare(Persoana **t, int n)
{
   qsort(t, n, sizeof(Persoana*), compare);
}
