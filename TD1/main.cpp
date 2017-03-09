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







    return 0;
}
