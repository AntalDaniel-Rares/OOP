#include <iostream>
#include <string.h>

using namespace std;

class Garantie
{
  int nr_luni;  //durata garantie
  char* service; //cine asigura service-ul

  public:

  Garantie();
  Garantie(const int, const char*);
  Garantie(Garantie&);
  Garantie operator=(Garantie&);
  ~Garantie();
  int GetTime();
  char* GetService();

  friend istream& operator>>(istream&, Garantie&);
  friend ostream& operator<<(ostream&, Garantie&);
};