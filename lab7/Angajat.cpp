#include "Student_Angajat.hpp"

Angajat::Angajat()
{
    id_angajat = 0;
    salariu = 0;
}

Angajat::Angajat(const int id, const int sal)
{
    id_angajat = id;
    salariu = sal;
}

Angajat Angajat::operator=(Angajat &a)
{
    id_angajat = a.id_angajat;
    salariu = a.salariu;

    return *this;
}

void Angajat::afisare()
{
    cout << endl;
    cout << "ID angajat: " << id_angajat << endl;
    cout << "Salariu angajat: " << salariu << endl;
}

int Angajat::GetVenit()
{
    return salariu;
}