#include <iostream>
#include "Persoana.hpp"
using namespace std;

class Angajat:virtual public Persoana{

    protected:
    int id_angajat; //unic pentru fiecare persoana de acest tip
    int salariu;

    public:

    Angajat();
    Angajat(const int, const int);

    Angajat operator=(Angajat&);
    void afisare();
    int GetVenit();

}; // venitul unui angajat pe luna e salariul
