#include <iostream>

#include "conteneur.h"
#include "Vector.h"
#include "Stack.h"
#include "algorithm.h"
#include "test2.h"

using namespace std;
using namespace TD;
//using namespace AO;
using namespace AC;
using namespace LO21;

bool inf(int a, int b) {return a<b;}
bool sup(int a, int b) {return a>b;}

class comparateur {
public:
    enum ordre{croissant, decroissant};
private:
    ordre d;

public:

    comparateur(ordre o=croissant) : d(o) {}
    bool operator() (int a, int b) {
        if(d==croissant)
            return a<b;
        else
            return a>b;
    }

};



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

//    while(!pile.empty())
//        cout<<"sommet de pile = "<<pile.top()<<endl;

    Stack1<int> pile2;
    pile2.push(10);
    pile2.push(12);
    pile2.push(11);

//    while(!pile2.empty())
//        cout<<"sommet de pile = "<<pile2.top()<<endl;


    //**************************** TD11 ********************************

    //Exemple question 1

    Stack1<string, Vector<string> > pile3;

    pile3.push("hello");
    pile3.push("world");
    pile3.push("!");

    Stack1<string, Vector<string> >::iterator it=pile3.begin();

    while(it !=pile3.end()){
        cout << *it<< endl;
        ++it;
    }


    //Exemple question 2
    Vector<int> tab(10,1);
    tab[0]=7;
    tab[4]=23;
    tab[6]=-10;

    for (Vector<int>::iterator it= tab.begin(); it!=tab.end(); ++it) {
        std::cout<< *it<<" "<<endl;
    }

    Vector<int>::iterator it_min=element_minimum(tab.begin(), tab.end());

    std::cout<<"le min est : "<< *it_min<<endl;


    // Exemple question 3



    Vector<int>::iterator it2=element_minimum(tab.begin(), tab.end());  // element_min normal
    Vector<int>::iterator ita=element_minimum(tab.begin(), tab.end(), inf); // element_min avec fonction inf
    Vector<int>::iterator itb=element_minimum(tab.begin(), tab.end(), sup);

    std::cout<< "le min est : "<<*it2<<endl;
    std::cout<< "le min est : "<<*ita<<endl;
    std::cout<< "le max est : "<<*itb<<endl;


    std::cout<<endl;

    // Méthode avec CLASS comparateur :
    Vector<int>::iterator itc=element_minimum(tab.begin(), tab.end(), comparateur(comparateur::decroissant));   // renvoie max
    Vector<int>::iterator itd=element_minimum(tab.begin(), tab.end(), comparateur(comparateur::croissant)); // renvoie min
                // Exemple d'éxecution avec croissant :
                /*
                 * 1. comparateur(comparateur::croissant) => "return a<b" et operator() (int a, int b)
                 * 2. Dans element_min(a, b, COMP) : if(comp(*it1, *it_min)) => comp=[operator() (int a, int b)] avec operator : "return a<b"
                 * 3. => Donc comparaison min.
                 */

    std::cout<< "le max est : "<<*itc<<endl;
    std::cout<< "le min est : "<<*itd<<endl;


    cout<<endl;
    //Exemple2
    exemple1<int> var;
    var.a=100;

    var.test(); // ici la variable globale est affiché
    var.test();

    cout<<var.a<<endl;  // ici, l'attribut a est affiché


    return 0;
}



















