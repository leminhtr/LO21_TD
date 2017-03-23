#include <iostream>
#include "fraction.h"

using namespace std;
using namespace MATH;


int main() {
    std::cout << "Hello, World!" << std::endl;

//Q.1
    //MATH::Fraction f; sans 'using namespace MATH'
    Fraction f;

    f.numerateur=3;
    f.denominateur=4;

    f.getNumerateur();
    f.getDenominateur();

    f.setFraction(1,9);
    f.setFraction(1,0);


















    return 0;
}