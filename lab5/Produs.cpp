#include "Produs.h"

Produs::Produs()
{
    pret = 0;
    marca = NULL;
}

Produs::Produs(const int p, const char *brand, Garantie &garant) : g(garant)
{
    pret = p;

    if (brand != NULL)
    {
        marca = new char[strlen(brand) + 1];
        strcpy(marca, brand);
    }
    else
        marca = NULL;

    //g = garant;
}

Produs::Produs(Produs &p)
{
    pret = p.pret;

    if (p.marca != NULL)
    {
        marca = new char[strlen(p.marca) + 1];
        strcpy(marca, p.marca);
    }
    else
        marca = NULL;

    g = p.g;
}

Produs Produs::operator=(Produs &p)
{
    pret = p.pret;

    if (marca != NULL)
    {
        delete[] marca;
    }

    if (p.marca != NULL)
    {
        marca = new char[strlen(p.marca) + 1];
        strcpy(marca, p.marca);
    }
    else
        marca = NULL;

    g = p.g;

    return *this;
}

Produs::~Produs()
{
    delete[] marca;
}

ostream& operator<<(ostream &dev, Produs &p)
{   
    if (p.marca != NULL)
    {
        dev << "Produsul apartine de brandul " << p.marca << "." << endl;
    }
    else
        dev << "Brandul este necunoscut." << endl;
    
    dev << "Pretul produsului este " << p.pret << " RON" << "." << endl;

    dev << p.g;

    dev << "====================================" << endl;

    return dev;
}

istream &operator>>(istream &dev, Produs &p)
{
    cout << "Brand: ";

    if (p.marca != NULL)
    {
        delete[] p.marca;
    }

    p.marca = new char[20];
    
    dev.ignore(100, '\n');
    dev.getline(p.marca, 21);
    
    cout << "Pret(RON): ";
    dev >> p.pret;

    dev >> p.g;

    return dev;
}

int compare(const void* a, const void *b)
{
	const Produs* x = (Produs*) a;
	const Produs* y = (Produs*) b;

	if (x->pret > y->pret)
		return 1;
	else if (x->pret < y->pret)
		return -1;

	return 0;
}

void sortare(Produs *produse, int n)
{
   qsort(produse, n, sizeof(Produs), compare);
}

void Produs::garantie12luni(int n)
{
    cout << endl << "PRODUSE CU PESTE 12 LUNI GARANTIE:" << endl;

    for (int i = 0; i < n; i++)
    {
        if (this[i].g.GetTime() > 12)
        {
            cout << this[i];
        }
    }

    cout << endl;
}

void Produs::service(int n)
{
    cout << endl << "PRODUSE ASIGURATE DE SerVice:" << endl;

    for (int i = 0; i < n; i++)
    {
        if (!strcmp(this[i].g.GetService(), "SerVice"))
        {
            cout << this[i];
        }
    }

    cout << endl;
}

