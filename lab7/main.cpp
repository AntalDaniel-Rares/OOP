#include "Student_Angajat.hpp"

int main ()
{
    Angajat a(10, 1500), b;

    //a = b;

    //a.afisare();

    int *array = new int[2];
    array[0] = 10;
    array[1] = 9;

    Student s(1, 2, array);

    //s.afisare();

    Student_Angajat sa(1, 2, array, 4, 3000), sb;

    Student_Angajat sc = sb;
    
    //sc.afisare();

    Persoana **vec = new Persoana*[4];

    vec[0] = &s;
    vec[1] = &a;
    vec[2] = &sa;
    vec[3] = new Angajat(11, 1000);

    cout << "AFISARE SIR NEORDONAT:\n";

    for (int i = 0; i < 4; i++)
    {
        vec[i]->afisare();
    }
    
    cout << "====================================\n";
    cout << "AFISARE SIR ORDONAT:\n";

    //cout << vec[0]->GetVenit();

    sortare(vec, 4);

    for (int i = 0; i < 4; i++)
    {
        vec[i]->afisare();
    }

    return 0;
}