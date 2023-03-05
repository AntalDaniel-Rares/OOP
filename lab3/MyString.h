//MyString.h
#include <iostream>
#include <string.h>
#include <assert.h>
using namespace std;

class MyString {
    private:
        char *buf; // stocheaza sirul de lungime l (nu uitati sa alocati spatiu si pentru caracterul’/0’)
        int l;
    public:
        MyString();
        MyString(const char *);
        MyString(const MyString &);
        MyString& operator=(const MyString &);
        ~MyString();
        void citire();
        void afisare() const;
        friend ostream& operator<<(ostream&, const MyString &);            
        friend istream& operator>>(istream&, MyString &);
        char& operator[](int);
        //puteti sa implementati aceste 3 functii (dar nu e obligatoriu) conform Cursului 4
        
        friend const MyString operator+(const MyString&, const MyString&); /* concateneaza 2 stringuri si salveaza rezultatul intr-un obiect nou de tip MyString pe care il returneaza*/
        MyString& operator+=(const MyString&); /*concateneaza 2 stringuri si salveaza rezultatul in primul operand a carui adresa o returneaza*/
        friend bool operator==(const MyString&, const MyString&); /*verifica daca cele 2 siruri sunt identice*/
        friend bool operator!=(const MyString&, const MyString&);/*verifica daca cele 2 siruri sunt diferite*/
        int lookFor(char); //cauta caracterul dat ca parametru in sir si returneaza numarul de aparitii
        friend void test(MyString);
};
