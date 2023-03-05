#include "MyString.h"

MyString::MyString()
{
    buf = NULL;
    l = 0;
}

MyString::MyString(const char* s)
{
    if (s != NULL)
    {
        l = strlen(s);
        buf = new char[l + 1];
        strcpy(buf, s);
    }
    else buf = NULL;
}

MyString::MyString(const MyString &alpha)
{
    buf = NULL;

    if (alpha.buf != NULL)
    {
        buf = new char[alpha.l + 1];
        strcpy(buf, alpha.buf);
    }
        
    l = alpha.l;
}

MyString& MyString::operator=(const MyString &alpha)
{
    if (buf != NULL)
    {
        delete[] buf;
    }

    if (alpha.buf != NULL)
    {
        buf = new char[alpha.l + 1];
        strcpy(buf, alpha.buf);
    }
    else buf = NULL;
        
    l = alpha.l;

    return *this;
}

MyString::~MyString()
{
    delete[] buf;
}

void MyString::citire()
{
    cout << "Lungimea sirului de caractere = ";
    cin >> l;
    cin.get();

    if (buf !=  NULL)
    {
        delete[] buf;
    }
    
    buf = new char[l + 1];

    cout << "Sirul de caractere = ";
    cin.getline(buf, l + 1);
    cout << "===================================\n";
}

void MyString::afisare() const
{
    cout << "Lungimea sirului de caractere este: " << l;
    cout << "\n";

    if (buf != NULL)
    {
        cout << "Sirul de caractere este: " << buf;
        cout << "\n";
    }
    else
    {
        cout << "Sirul de caractere nu exista.\n";
    }

    cout << "===================================\n";
}

MyString& MyString::operator+=(const MyString &string1)
{
    if (string1.l + l ==0)
    {
        return *this;
    }
    
    char *copy = NULL;

    if (buf != NULL)
    {
        copy = new char[l + 1];
        strcpy(copy, buf);
        delete[] buf;
    }
    
    buf = new char[l + string1.l + 1];

    if(copy != NULL)
        strcpy(buf, copy);

    if (string1.buf != NULL)
        strcat(buf, string1.buf);

    l += string1.l;

    delete[] copy;

    return *this;
}

bool operator==(const MyString &string1, const MyString &string2)
{
    if (string1.buf == NULL && string2.buf == NULL)
    {
        return true;
    }

    if (string1.buf != NULL && string2.buf != NULL)
    {
        if (strcmp(string1.buf, string2.buf) == 0)
        {
            return true;
        }
    }

    return false;
}

bool operator!=(const MyString &string1, const MyString &string2)
{
    if (string1.buf == NULL && string2.buf == NULL)
    {
        return false;
    }

    if (string1.buf != NULL && string2.buf != NULL)
    {
        if (strcmp(string1.buf, string2.buf) == 0)
        {
            return false;
        }
    }

    return true;
}

const MyString operator+(const MyString &string1, const MyString &string2)
{
    if (string1.buf == NULL)
    {
        return string2;
    }
    
    if (string2.buf == NULL)
    {
        return string1;
    }

    MyString string3(strcat(string1.buf, string2.buf));

    return string3;
}

int MyString::lookFor(char c)
{
    int nr = 0;

    for (int i = 0; i < l && buf != NULL; i++)
    {
        if (buf[i] == c)
        {
            nr++;
        }
        
    }

    return nr; 
}

ostream& operator<<(ostream &dev, const MyString &obj)
{
    dev << "Nr. caractere: " << obj.l << endl;

    if ( obj.buf != NULL)
    {
        for(int i = 0; i < obj.l; i++)
        {
            dev << obj.buf[i];
        }
    }
    else dev << "Sirul de carctere nu exista";  

    dev << endl;

    return dev;
}

istream & operator>>(istream &dev, MyString &obj)
{
    cout << "Dimensiunea sirului de caractere: ";
    
    dev >> obj.l;

    if (obj.buf != NULL) 
        delete[] obj.buf;

    cout << "Sirul de caractere: ";

    if (obj.l > 0)
    {
        obj.buf = new char[obj.l + 1];

        for(int i = 0; i < obj.l; i++)
            dev >> obj.buf[i];
    } 
    else obj.buf=NULL;

    obj.buf[obj.l] = '\0';

    return dev;
}

char& MyString::operator[](int i)
{
    assert (i >= 0 && i < l);
    return buf[i];
}

void test(MyString obj)
{
    cout << obj[21];
}