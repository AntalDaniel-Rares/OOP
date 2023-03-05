#include <iostream>
#include "MyString.h"
using namespace std;

int main()
{
    MyString obj1, obj2("strings");

    obj2.afisare();

    //cin >> obj2;

    //obj1 = obj2;

    obj2.afisare();

    MyString obj3 = obj1 + obj1;

    obj3.afisare();

    cout << obj1;

    cout << obj1.lookFor('s') << '\n';

    //test(obj2);

    return 0;
}