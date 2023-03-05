#include "Produs.h"

using namespace std;

int main()
{
    Garantie g(1, NULL);
    Garantie g1(4, "Servant");

    //g = g1;

    //cout << g;

    Produs p(230, "Philips", g1);
    Produs p1(1000, "UPB", g);
    Produs p2(p);

    p2 = p1;

    //cout << p2;

    Produs *array;
    int n;

    cout << "Numarul de produse = ";
    cin >> n;

    array = new Produs[n];

    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }

    sortare(array, n);

    for (int i = 0; i < n; i++)
    {
        cout << array[i];
    }
    
    array->garantie12luni(n);

    array->service(n);

    return 0;
}