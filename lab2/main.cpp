#include <iostream>
#include <cstring>
#include "Angajat.h"

using namespace std;


int main()
{    
    char *nume = new char[15];
    char* CNP = new char[14];
    int salariu = 3000;

    strcpy(nume, "George Munte");
    strcpy(CNP, "1750924618638");

    Angajat ang1(nume, CNP, salariu);

    //ang1.afisare();

    Angajat ang2(ang1);

    //ang2.afisare();

    Angajat *vec = new Angajat[5];

    strcpy(nume, "Elena Maia");
    strcpy(CNP, "6010623456274");
    salariu = 4500;

    Angajat ang3(nume, CNP, salariu);

    strcpy(nume, "Florin Maga");
    strcpy(CNP, "5010412456561");
    salariu = 3500;

    Angajat ang4(nume, CNP, salariu);

    strcpy(nume, "Petru Pevlean");
    strcpy(CNP, "1650317453289");
    salariu = 1500;

    Angajat ang5(nume, CNP, salariu);

    strcpy(nume, "Mihai Andrei");
    strcpy(CNP, "1770811755258");
    salariu = 1900;

    Angajat ang6(nume, CNP, salariu);

    int n = 5;

    vec[0].modificare(ang1);
    vec[1].modificare(ang3);
    vec[2].modificare(ang4);
    vec[3].modificare(ang5);
    vec[4].modificare(ang6);

    vec->afisare_tot(n);

    vec->sortare(n);
    cout<<"Angajatii sortati dupa nume:"<<endl;
    vec->afisare_tot(n);

    vec->gen(n);
    vec->bogati(n);

    return 0;
}


