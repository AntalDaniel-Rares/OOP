#include "piesa.hpp"

class Ansamblu
{
    Piesa_A pa;
    Piesa_B *vec; // are ca nr. de elemente nr. de gauri ale lui pa
    int nr_caracteristici;
    string *caracteristici; //lungimea vectorului e nr_caracteristici

    public:

    Ansamblu();
    Ansamblu(Piesa_A, Piesa_B*, int, string*);
    Ansamblu(Ansamblu&);
    ~Ansamblu();
    
    void afisare();

}; // pretul este dat de suma preturilor pieselor componente

