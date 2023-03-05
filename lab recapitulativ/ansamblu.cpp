#include "ansamblu.hpp"

Ansamblu::Ansamblu()
{
    Piesa_A pa = *(new Piesa_A());

    vec = NULL;

    nr_caracteristici = 0;

    caracteristici = NULL;
}

void Ansamblu::afisare()
{
    pa.afisare();
    
    for (int i = 0; i < pa.getGauri(); i++)
    {
        vec[i].afisare();
    }

    cout << "Nr. caracteristici:" << nr_caracteristici << endl;
    
    for (int i = 0; i < nr_caracteristici; i++)
    {
        cout << caracteristici[i] << endl;
    }
    
}

Ansamblu::~Ansamblu()
{
    delete[] vec;
    delete[] caracteristici;
}