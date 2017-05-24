#include <iostream>

#include "conteneur.h"
#include "Vector.h"
#include "Stack.h"

using namespace std;
using namespace TD;
using namespace AO;
//using namespace AC;


int main() {

// on n'a qu'une seule classe fille Vector<T> : classe Stack

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

    // adaptateur objet avec stack
    Stack<int> pile;
    pile.push(10);
    pile.push(12);
    pile.push(11);

    while(!pile.empty())
        cout<<"sommet de pile = "<<pile.top()<<endl;

    Stack1<int> pile2;
    pile2.push(10);
    pile2.push(12);
    pile2.push(11);

    while(!pile2.empty())
        cout<<"sommet de pile = "<<pile2.top()<<endl;

    return 0;
}



















