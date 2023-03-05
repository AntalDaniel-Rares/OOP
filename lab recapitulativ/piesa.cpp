#include "piesa.hpp"

int Piesa_A::getGauri()
{
    return gauri;
}

void Piesa_A::afisare()
{
    cout << "Nr. gauri:" << gauri << endl;
    cout << "Cod:" << cod << endl;
    cout << "Pret:" << pret << endl;
}

void Piesa_B::afisare()
{
    cout << "Culoare:" << culoare << endl;
    cout << "Cod:" << cod << endl;
    cout << "Pret:" << pret << endl;
}