#include "Garantie.h"
#include <cstdlib>

class Produs{
   int pret; //ex: 45
   char* marca; //”LG”
   Garantie g;   

   public:

   Produs();
   Produs(const int, const char*, Garantie&);
   Produs(Produs&);
   Produs operator=(Produs&);
   ~Produs();
   int& operator[](int);
   void garantie12luni(int);
   void service(int);

   friend istream& operator>>(istream&, Produs&);
   friend ostream& operator<<(ostream&, Produs&);
   friend void sortare(Produs*, int);
   friend int compare(const void*, const void*);
};