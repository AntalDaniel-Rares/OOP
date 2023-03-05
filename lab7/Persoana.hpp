#include <stdlib.h>

class Persoana{
public:
virtual void afisare() = 0;
virtual ~Persoana(){}
virtual int GetVenit() = 0;

friend void sortare(Persoana**, int);
friend int compare(const void*, const void*);

};