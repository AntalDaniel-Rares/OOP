#include "Student.hpp"

Student::Student()
{
    id_student = 0;
    n = 0;
    note = NULL;
}

Student::Student(const int id, const int nr, int* vector)
{
    id_student = id;
    n = nr;

    if (vector != NULL && nr >= 0)
    {
        note = new int[nr];

        for (int i = 0; i < n; i++)
            note[i] = vector[i];
    }
    else note = NULL;
}

Student::~Student()
{
    delete[] note;
}

Student Student::operator=(Student &s)
{
    id_student = s.id_student;
    n = s.n;

    if (note != NULL)
    {
        delete[] note;
    }
    
    if (n != 0)
        note = new int[n];
    else note = NULL;

    for (int i = 0; i < n; i++)
    {
        note[i] = s.note[i];
    }

    return *this;
}

Student::Student(Student &s)
{
    id_student = s.id_student;
    n = s.n;

    if (n != 0)
        note = new int[n]; 
    else note = NULL;
    
    for (int i = 0; i < n; i++)
    {
        note[i] = s.note[i];
    }
    
}

void Student::afisare()
{
    cout << endl;
    cout << "ID student: " << id_student << endl;
    cout << "Numar note: " << n << endl;

    cout << "Note: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << note[i] << " ";
    }  

    cout << endl;
}

int Student::GetVenit()
{
    double media; 
    int suma = 0;

    for (int i = 0; i < n; i++)
    {
        suma += note[i];
    }
    
    media = (double)suma/n;

    if (media > 8.5)
    {
        return 700;
    }

    return 0;
}
