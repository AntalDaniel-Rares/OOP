#include "baza.hpp"

class Piesa
{
    protected: char cod[4];
                int pret;
};

class Piesa_A: public Piesa
{ 
    int gauri;

    public:

    int getGauri();
    void afisare();
};

class Piesa_B: public Piesa
{
    string culoare;

    public:

    void afisare();
};