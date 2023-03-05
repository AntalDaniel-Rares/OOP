#include "Angajat.hpp"

class Student:virtual public Persoana{

    protected:
    int id_student; //unic pentru fiecare persoana de acest tip
    int n; //nr. note pe baza carora se calculeaza media
    int *note; //vectorul in care se stocheaza cele n note

    public:
    Student();
    Student(const int, const int, int*);
    ~Student();
    Student operator=(Student&);
    Student(Student&);
    
    void afisare(); 
    int GetVenit();
}; //media studentului e suma notelor/n; daca media>8.5 si nu are note<5 atunci are bursa
// venitul unui student pe luna e bursa (=700) sau 0 daca nu are bursa
