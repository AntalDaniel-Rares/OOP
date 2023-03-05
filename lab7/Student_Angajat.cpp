#include "Student_Angajat.hpp"

Student_Angajat::Student_Angajat():Student(), Angajat()
{

}

Student_Angajat::Student_Angajat(const int ids, const int nr, int* note, const int ida, const int sal):Angajat(ida, sal), Student(ids, nr, note)
{

}

Student_Angajat::Student_Angajat(Student_Angajat &s):Student(s.id_student, s.n, s.note), Angajat(s.id_angajat, s.salariu)
{

}

Student_Angajat Student_Angajat::operator=(Student_Angajat &sa)
{
    id_angajat = sa.id_angajat;
    salariu = sa.salariu;

    id_student = sa.id_student;
    n = sa.n;

    if (note != NULL)
    {
        delete[] note;
    }
    
    if (n >= 0)
        note = new int[n];
    else note = NULL;

    for (int i = 0; i < n; i++)
    {
        note[i] = sa.note[i];
    }

    return *this;
}

void Student_Angajat::afisare()
{
    Student::afisare();
    Angajat::afisare();
}

int Student_Angajat::GetVenit()
{
    int bursa = Student::GetVenit();

    return salariu + bursa;
}