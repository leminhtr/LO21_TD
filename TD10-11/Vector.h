//
// Created by Minh Tri on 24/05/2017.
//

#ifndef TD10_11_VECTOR_H
#define TD10_11_VECTOR_H

#include "conteneur.h"

namespace TD {

    template<class T>
    class Vector : public Contener<T> {

        T* tab;
        unsigned int cap;

    public:
        Vector(unsigned int s=0, const T& init=T());    // T() : constructeur de la classe T
        Vector(const Vector<T> &);  // recopie
        ~Vector();

        Vector<T>& operator=(const Vector<T> & t);

        T& element (unsigned int i);
        const T& element(unsigned int i) const;

        T& operator[](unsigned int i) {
            return tab[i];}
        const T& operator[](unsigned int i) const {
            return tab[i];};

        void push_back(const T& x);
        void pop_back();

    };



}

template<class T>
TD::Vector<T>::Vector(unsigned int s, const T& init) :
        Contener<T>(s), tab(new T[s]), cap(s) {
    // new T[s] suppose l'existence du constructeur sans paramètre pour la classe T

    for(unsigned int i=0; i< Contener<T>::nbEl; i++)    //nbEl est dans Contener<T>/ on peut aussi directement mettre i< nbEl ou i < this.nbEl
        tab[i]=init;
}

// constructeur de recopie
template<class T>
TD::Vector<T>::Vector(const Vector<T> & t) :
    Contener<T>(t.nbEl), tab(new T[t.size()]), cap(t.size()) {

    for (unsigned int i=0; i< t.size() ; i++)
        tab[i]= t.tab[i];
}

//destructeur
template<class T>
TD::Vector<T>::~Vector() {
    delete[] tab;
}

template<class T> T& TD::Vector<T>::element(unsigned int i){
    if(i< Contener<T>::nbEl) // ou Contener<T>::nbEl ou this.nbEl
        return tab[i];
    //else
    throw ContenerException("erreur Vector : demande hors limite");
}

template<class T> const T& TD::Vector<T>::element(unsigned int i) const{
    if(i< Contener<T>::nbEl) // ou Contener<T>::nbEl ou this.nbEl
        return tab[i];
    //else
    throw ContenerException("erreur Vector : demande hors limite");
}

//opérateur d'affectation
template<class T> TD::Vector<T>& TD::Vector<T>::operator=(const Vector<T> &t) {
    if (this != &t){
        T* newtab = new T[t.nbEl + 5];

        for (unsigned int i = 0; i < t.nbEl; ++i) {
            newtab[i]= t.tab[i];
        }

        Contener<T>::nbEl = t.nbEl;
        cap=t.nbEl;
        T* old= tab;
        tab= newtab;
        delete[] old;
    }
    return *this;
}

// push_back
template<class T> void TD::Vector<T>::push_back(const T &x) {
    if(Contener<T>::nbEl == cap){   // si full
        T* newtab= new T[cap +5];

        for(unsigned int i=0; i< cap; i++)
            newtab[i]=tab[i];

        T* old=tab;
        cap+=5;
        tab=newtab;

        delete[] old;
    }

    tab[Contener<T>::nbEl++]=x;

}

template<class T> void TD::Vector<T>::pop_back() {
    if (!this->empty()) {
        Contener<T>::nbEl--;
    }
    else
        throw ContenerException("Erreur vector : Vector vide !");

}



#endif //TD10_11_VECTOR_H
