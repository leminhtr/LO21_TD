//
// Created by Minh Tri on 01/06/2017.
//

#ifndef TD10_11_TEST2_H
#define TD10_11_TEST2_H

#include <iostream>

using namespace std;

int a= 8; // globale


template <class T>
class exemple2{
public:
    int a;
};


template <class T>
class exemple1 : public exemple2<T>{

public:
    void test() {
        std::cout<<"globale : "<<endl;
        std::cout<< a /* Quel "a" est affiché ? : globale ou class attribut exemple2*/<<endl;
        a=9;
        // Réponse : => La variable globale "a" est affiché.
        std::cout<<"attribut :"<<endl;
        std::cout<< this->a<<endl;
    }
};









#endif //TD10_11_TEST2_H
