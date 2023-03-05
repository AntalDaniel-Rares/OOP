#include "Student.hpp"

class Student_Angajat:public Student, public Angajat{

    public:

    Student_Angajat();
    Student_Angajat(const int, const int, int*, const int, const int);
    Student_Angajat(Student_Angajat&);
    Student_Angajat operator=(Student_Angajat&);

    void afisare();
    int GetVenit();

}; //venitul unui student angajat pe luna e salariul + bursa (=5000) sau 0 daca nu are bursa
