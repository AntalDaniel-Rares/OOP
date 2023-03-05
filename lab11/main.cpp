#include <iostream>
#include <vector>
#include <string.h>
#include <fstream>

using namespace std;

class produs{
    public:
    virtual void print(ostream&) = 0;
    virtual int suma() = 0;
    friend ostream& operator<<(ostream &out, produs *p)
    {
        out << "==========================================" << endl;
        p->print(out);
        return out;
    }
};

class produs_software: public produs //PS
{protected: 
        int pret;

    public:
    produs_software()
    {
        pret = 0;
    }

    produs_software(int p)
    {
        pret = p;
    }

    void print(ostream &out)
    {
        out << "Pret software: " << pret << endl;
    }

    produs_software(produs_software &p)
    {
        *this = p;
    }

    int suma()
    {
        return pret;
    }

};  

class Piesa
{ 
    char cod[6]; 
    int pret;

    public:
    Piesa()
    {
        strcpy(cod, "");
        pret = 0;
    }

    Piesa(const char c[], const int p):pret(p)
    {
        strcpy(cod, c);
    }

    friend ostream& operator<<(ostream &out, Piesa &p)
    {
        out << "COD: " << p.cod << endl;
        out << "Pret piesa: " << p.pret << endl;
        return out;
    }

    Piesa(const Piesa &p)
    {
        *this = p;
    }

    int suma()
    {
        return pret;
    }

};

class modul_hardware : virtual public produs//MH
{ protected:
    vector<Piesa> vec;  //vector piese
    int nr_piese;             //nr piese din vec
    int pm;                     //pret manopera pe ora
    int nr_ore;                //ore dezvoltare

    public:
    modul_hardware()
    {
        nr_piese = 0;
        pm = 0;
        nr_ore = 0;
        vec.clear();
    }

    modul_hardware(vector<Piesa> v, const int nrp, const int man, const int nro):nr_ore(nro),nr_piese(nrp),pm(man),vec(v)
    {
    }

    void print(ostream &out)
    {
        out << "Pret manopera: " << pm << endl;
        out << "Nr. ore: " << nr_ore << endl;
        out << "Nr. piese: " << nr_piese << endl;

        for (int i = 0; i < nr_piese; i++)
        {
            out << "------------------------------------------" << endl;
            out << "Piesa nr. " << i << endl;
            out << vec[i];
        }
        
    }

    modul_hardware(modul_hardware &p)
    {
        *this = p;
    }

    int suma()
    {
        int suma = 0;

        for (int i = 0; i < vec.size(); i++)
        {
            suma += vec[i].suma();
        }

        return suma + pm * nr_ore;
    }

};// pret=suma preturilor pieselor+pm*nr_ore	        

class produs_mixt: public modul_hardware  //PM
{   
    produs_software ps ;  
    vector<string> functionalitati;
    int nr_functionalitati;

    public:
    produs_mixt()
    {
        ps = *(new produs_software);
        functionalitati.clear();
        nr_functionalitati = 0;
    }

    produs_mixt(int nr, produs_software p, vector<string> f, vector<Piesa> v, const int nrp, const int man, const int nro):nr_functionalitati(nr),ps(p),functionalitati(f)
    {
        nr_ore = nro;
        nr_piese = nrp;
        pm = man;
        vec = v;
    }

    produs_mixt(produs_mixt &p)
    {
        *this = p;
    }

    void print(ostream &out)
    {
        ps.print(out);

        modul_hardware::print(out);

        out << endl;
        out << "Nr. functionalitai: " << nr_functionalitati << endl;

        for (int i = 0; i < nr_functionalitati; i++)
        {
            out << functionalitati[i] << ", ";
        }

        out << endl;
        
    }

    int suma()
    {
        return ps.suma() + modul_hardware::suma();
    }
};    //pret = pret ps+pret MH	

int main()
{
    vector<produs*> vec;
    vector<Piesa> piese, piese2;
    vector<string> fun;

    fun.push_back("anti-frezze");
    fun.push_back("soft-touch");

    produs_software m(500);

    piese.push_back(Piesa("1234", 10));
    piese.push_back(Piesa("0001", 20));

    piese2.push_back(Piesa("1004", 15));
    piese2.push_back(Piesa("0004", 30));
    piese2.push_back(Piesa("0102", 5));

    vec.push_back(new produs_software(10));
    vec.push_back(new modul_hardware(piese, piese.size(), 500, 10));
    vec.push_back(new produs_mixt(fun.size(), m, fun, piese2, piese2.size(), 300, 15));

    vector<produs*>::iterator it = vec.begin();

    int suma = 0;

    for (it = vec.begin(); it < vec.end(); it++)
    {
        cout << *it;
    }

    cout << endl;

    for(int i = 0; i < vec.size(); i++)
        suma += vec[i]->suma();

    cout << "Costul total este: " << suma;

    cout << endl;

    ofstream file;
    file.open ("file.txt");
    for (it = vec.begin(); it < vec.end(); it++)
    {
        file << *it;
    }

    file.close();

    vec.erase(vec.begin());
    vec.erase(vec.begin());

    vector<produs*>::iterator i = vec.begin();

    vec.insert(++i, new produs_software(700));

    /*
    for (it = vec.begin(); it < vec.end(); it++)
    {
        cout << *it;
    }
    */

    return 0;
}