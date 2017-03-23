#include <iostream>
#include "fonction.h"
#include "ex10.h"

using namespace std;

int main() {
    //bonjour();
    //exerciceA();

    double x =3.14;
    cout<< x << "\n";

    double y;
    cout<< y << "\n";
    y=3.14;
    cout<< y<<"\n";

    const double pi =3.14;
    cout << pi;
    //pi=5; error: assignment of read-only variable 'pi'


    exercice_surcharge();

    cout << endl;

    cout << "Exercice 12" << endl;

    int f=5;
    int g=9;
    inverse(&f, &g);
    cout << endl;

    inverse(f,g);
    cout << endl;


    cout << "Exercice 13" << endl;

    mystruct st1;

    st1.n=10;
    st1.x=3.14;
    raz(&st1);  //passage adresse

    st1.n=10;
    st1.x=3.14;
    raz(st1);   //passage par référence


    return 0;
}
