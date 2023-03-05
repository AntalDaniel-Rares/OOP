#include "Angajat.h"

Angajat::Angajat(void)
{
    nume = new char[15];
    nume = NULL;

    strcpy(CNP, "0000000000000");

    salariu = 0;
    
}

Angajat::Angajat(char* nume, char CNP[], int salariu)
{
    this->nume = new char[15];
    strcpy(this->nume, nume);
    
    strcpy(this->CNP, CNP);

    this->salariu = salariu;
}

void Angajat::afisare() const
{

    if(nume != NULL)
        cout<<"Nume: "<<nume<<endl;
    else cout<<"Nume: N/A"<<endl;

    cout<<"CNP: ";

    for (int i = 0; i < 13; i++)
    {
        cout<<CNP[i];
    }

    cout<<endl;

    cout<<"Salariu: "<<salariu<<endl;
    

}

Angajat::~Angajat(void)
{
    delete[] nume;
}

Angajat::Angajat(const Angajat& old)
{
    salariu = old.salariu;

    nume = new char[15];
    strcpy(nume, old.nume);

    strcpy(CNP, old.CNP);

    cout<<"const de copiere"<<endl;
}

void Angajat::modificare(const Angajat& ang)
{
    if (ang.nume != NULL) 
    {
        nume = new char[strlen(ang.nume) + 1];
        strcpy(nume, ang.nume);
    }
    else nume = NULL;

    strcpy(CNP, ang.CNP);

    salariu = ang.salariu;
}

int Angajat::getSalariu() const
{
    return this->salariu;
}

bool Angajat::eFemeie() const
{
    if (CNP[0] == '2' || CNP[0] == '6')
    {
        return true;
    }
    else return false;
    
}

void Angajat::gen(const int n)
{
    int femei = 0, barbati = 0;

    for (int i = 0; i < n; i++)
    {
        if (this[i].eFemeie() == true)
        {
            femei++;
        }
        else barbati++;
    }

    cout<<"Printre angajati se numara "<<barbati<<" barbati si "<<femei<<" femei."<<endl;
    
}

void Angajat::afisare_tot(const int n)
{
    for (int i = 0; i < n; i++)
    {
        this[i].afisare();
        cout<<endl;
    }
    
}

void Angajat::sortare(const int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (strcmp(this[i].nume, this[j].nume) > 0)
            {
                
                Angajat aux;
                aux.modificare(this[i]);
                this[i].modificare(this[j]);
                this[j].modificare(aux);
            }
        }
    }
}

void Angajat::bogati(const int n)
{
    cout<<endl<<"Angajatii cu salariul peste 3000 lei: "<<endl;

    for (int i = 0; i < n - 1; i++)
    {
        if (this[i].salariu > 3000)
        {
            this[i].afisare();
        }
        
    }
}
