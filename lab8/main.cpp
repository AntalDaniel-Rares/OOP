#include <fstream>
#include <iostream>
#include <stdlib.h>
#include<sstream>
#include<string>
using namespace std;

void print(string *vec, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << vec[i] << endl;
    } 
}

void file_print(string *vec, int n, ofstream &out)
{
    for (int i = 0; i < n; i++)
    {
        out << vec[i] << endl;
    }  
}

int compare(const void* a, const void *b)
{
	string x = *(string*) a;
	string y = *(string*) b;

	if (x.compare(y) > 0)
		return 1;
	else if (x.compare(y) < 0)
		return -1;

	return 0;
}

void sortare(string *t, int n)
{
   qsort(t, n, sizeof(string), compare);
}

int nr_linii(ifstream& ifis)
{
    ifis.clear();
    ifis.seekg (0, ios::beg);

    int nr = 0;

    char buf [14];

    while (!ifis.eof())
    {
        ifis.getline(buf, 14, '\n');
        nr++;
    }

    return nr;
}

void vector_string(ifstream& ifis, string *vec)
{
    ifis.clear();
    ifis.seekg (0, ios::beg);

    int i = 0;

    char buf [14];

    while (!ifis.eof())
    {
        ifis.getline(buf, 14, '\n');
        vec[i++] = buf;
    }
}

void femei_barbati(string *vec, int n)
{
    ofstream barbati("barbati.out");
    ofstream femei("femei.out");

    for (int i = 0; i < n; i++)
    {
        if( vec[i][0] % 2 == 0)
            femei << vec[i] << endl;
        else barbati << vec[i] << endl;
    }  
}

void date_nastere(string *vec, int n)
{
    string *date_nastere = new string[n];

    ofstream d("date_nastere.out");

    for (int i = 0; i < n; i++)
    {
        date_nastere[i] = vec[i].substr(1,6);
    }

    sortare(date_nastere, n);

    file_print(date_nastere, n, d); 

    d.close();
}

void replaceAll(const string& secv, const string& cuv)
{   
    ifstream d;
    d.open("date_nastere.out");

    int i = 0;
    string s;

   if (d) 
   {
      ostringstream ss;
      ss << d.rdbuf(); // reading data
      s = ss.str();
   }

    int loc;
    while ((loc = s.find(secv)) != string::npos)//cat timp se gaseste o secventa nemodificata
    {   //retin pozitia de inceput a secventei in loc
        s.replace(loc, secv.size(), cuv); //inlocuieste secventa cu cuv
    }

    d.close();

    ofstream out("date_nastere.out");

    out << s;

    out.close();
} 

int main()
{
    ifstream ifis;
    ifis.open("date.in");

    if(!ifis)
        cout << "Eroare la deschidere date.in";

    int n = nr_linii(ifis);

    cout << "Sunt " << n << " linii in fisierul date.in" << endl;

    string *vec = new string[n];

    vector_string(ifis, vec);

    print(vec, n);

    femei_barbati(vec, n);

    date_nastere(vec, n);

    ifis.close();

    replaceAll("010", "XY");

}