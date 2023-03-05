#include "Garantie.h"

Garantie::Garantie()
{
    nr_luni = 0;
    service = NULL;
}

Garantie::Garantie(const int luni, const char* serv)
{
    nr_luni = luni;

    if (serv != NULL)
    {
        service = new char[strlen(serv) + 1];
        strcpy(service, serv);
    }
    else service = NULL;
}

Garantie::Garantie(Garantie &obj)
{
    nr_luni = obj.nr_luni;

    if (obj.service != NULL)
    {
        service = new char[strlen(obj.service) + 1];
        strcpy(service, obj.service);
    }
    else service = NULL;
}

Garantie Garantie::operator=(Garantie &obj)
{
    nr_luni = obj.nr_luni;

    if (service != NULL)
    {
        delete[] service;
    }

    if (obj.service != NULL)
    {
        service = new char[strlen(obj.service) + 1];
        strcpy(service, obj.service);
    }
    else service = NULL;

    return *this;
}

Garantie::~Garantie()
{
    delete[] service;
}

ostream& operator<<(ostream &dev, Garantie &g)
{
    dev << "Numarul de luni pentru care este valabila garantia: " << g.nr_luni << endl;

    if (g.service != NULL)
    {
        dev << "Service-ul este asigurat de " << g.service << "." << endl;
    }
    else dev << "Service-ul este necunoscut." << endl;

    return dev;
}

istream &operator>>(istream &dev, Garantie &g)
{
    cout << "Service: ";

    if (g.service != NULL)
    {
        delete[] g.service;
    }

    g.service = new char[20];
    
    dev.ignore(100, '\n');
    dev.getline(g.service, 21);
    
    cout << "Timpul(luni) pentru care este valabila garantia: ";
    dev >> g.nr_luni;

    return dev;
}

int Garantie::GetTime()
{
    return nr_luni;
}

char* Garantie::GetService()
{
    return service;
}