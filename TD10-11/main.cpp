#include <iostream>

#include "conteneur.h"
#include "Vector.h"

using namespace std;
using namespace TD;

int main() {



    std::cout << "Hello, World!" << std::endl;

    Vector<int> tab1(10, 100); // vector de 10 entiers initialisé à 100
    Vector<float> tab2(5,4.0);

    tab1.push_back(4);
    tab2.pop_back();


    for (unsigned int i = 0; i < tab1.size() ; ++i) {
        cout<<"tab1["<<i<<"]"<<tab1[i]<<endl;
    }

    for (unsigned int i = 0; i < tab2.size() ; ++i) {
        cout<<"tab2["<<i<<"]"<<tab2[i]<<endl;
    }



    return 0;
}



















