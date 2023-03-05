#include <iostream>
#include <cstring>

using namespace std;

struct Student{
private: //implicit ar fi publice, dar nu vreau ca oricine sa poata modifica aceste campuri -> private
int id;
char *nume;
char gr_serie[6];
int note_sem_I[6]; //POO, MN, SS, TCAI, …
public: //altfel ar fi private ca si campurile si nu as putea sa interactionez cu datele stocate
void init(); // citesc valori de la tastatura si aloc spatiu daca trebuie sau initializez cu 0 / NULL
void afisare() const;
void modificare(const char []); //modifica grupa
void modificare(const Student &); //modifica toate campurile folosind valorile stocate in
//variabila Student data ca parametru
void modificare(int, int); //modifica nota de pe o anumita pozitie din vectorul de note
//(primul parametru), iar noua valoare e transmisa in al doilea parametru
void sortare(int );//sorteaza elevii dupa medie
};

float media(int note[])
{
    int suma = 0;

    for (int i = 0; i < 4; i++)
    {
        suma = suma + note[i];
    }

    float media = suma/4.;

    return media;
    
}

void Student::init()
{
    for (int i = 0; i <= 3; i++)
    {
        this[i].nume = new char[15];

        cout<<"id = ";
        cin>>this[i].id;
        cin.get();

        cout<<"Nume student: ";
        cin.getline(this[i].nume, 14);

        cout<<"Grupa si seria: ";
        cin.getline(this[i].gr_serie, 5);

        cout<<"Nota POO = ";
        cin>>this[i].note_sem_I[0];

        cout<<"Nota TCAI = ";
        cin>>this[i].note_sem_I[1];

        cout<<"Nota SS = ";
        cin>>this[i].note_sem_I[2];

        cout<<"Nota MN = ";
        cin>>this[i].note_sem_I[3];
    }
}

void Student::afisare() const
{
    for(int counter = 0; counter <= 3; counter++)
    {
        cout<<this[counter].id<<" "<<this[counter].nume<<" "<<this[counter].gr_serie<<" "<<"NOTE: ";

        for(int i = 0; i <= 3; i++)
            cout<<this[counter].note_sem_I[i]<<", ";

        cout<<"\n";
    }

    //delete [] nume;
}

void Student::modificare(const char grupa_noua[6])
{
    strcpy(gr_serie, grupa_noua);

}

void Student::modificare(const Student &valori)
{
    id = valori.id;

    strcpy(nume, valori.nume);
    strcpy(gr_serie, valori.gr_serie);

    for (int i = 0; i < 4; i++)
    {
        note_sem_I[i] = valori.note_sem_I[i];
    }
    
}

void Student::modificare(int i, int x)
{
    note_sem_I[i] = x;
}

void Student::sortare(int n)
{
    for (int i = 0; i <= n - 1; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            float m1 = media(this[i].note_sem_I);
            float m2 = media(this[j].note_sem_I);

            if (m1 > m2)
            {
                Student* aux = new Student();
                aux->nume = new char[15];
                aux->modificare(this[i]);
                this[i].modificare(this[j]);
                this[j].modificare(aux[0]);
            }
            
        }
        
    }
    
}

int main()
{
    int n = 3;

    Student* s = new Student[n]();

    s->init();
    s->afisare();

    s->sortare(n);
    s->afisare();

    char grupa_noua[] = "321AA";
    s[1].modificare(grupa_noua);

    s[1].modificare(s[0]);

    int i = 2, x = 10;

    s[1].modificare(i, x);

    s->afisare();
    
    return 0;
}