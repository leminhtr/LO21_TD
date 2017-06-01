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


        // Iterator non constant pour accès en écriture/lecture
        // Check list : attribut current : pointeur * sur Type à itérer
        //constructeur public avec val. par défaut
        // méthodes : operator ++, !=, *
        // fonction begin/end
        class iterator {
            T* current; // attribut pointe vers élément en cours


        public:
            iterator(T* c=0 /* val par défaut*/) : current(c) {}

            iterator & operator++() {current++; return *this;}  // opérator ++ préfixe
            iterator &operator++(int) {iterator tmp=*this; current++; return tmp;}  // opérator ++ postfixe (on retourne la valeur PUIS on incrémente après)

            // operator ==
            bool operator==(const iterator &it) const {return current==it.current;}
            //operator !=
            bool operator !=(const iterator &it) const {return current !=it.current;}

            //operator d'indirection : déférencement (*it)
            T &operator*() const{ return *current;}

        };// fin iterator

        iterator begin() {return iterator(tab);}
        iterator end() {return iterator(tab+this->nbEl);}


        // Iterator constant pour accès en écriture/lecture
        // Check list : attribut current : pointeur * sur Type à itérer
        //constructeur public avec val. par défaut
        // méthodes : operator ++, !=, *
        // fonction begin/end
        class const_iterator {
            T* current; // attribut pointe vers élément en cours


        public:
            const_iterator(T* c=0 /* val par défaut*/) : current(c) {}

            const_iterator & operator++() {current++; return *this;}  // opérator ++ préfixe
            const_iterator &operator++(int) {const_iterator tmp=*this; current++; return tmp;}  // opérator ++ postfixe (on retourne la valeur PUIS on incrémente après)

            // operator ==
            bool operator==(const const_iterator &it) const {return current==it.current;}
            //operator !=
            bool operator !=(const const_iterator &it) const {return current !=it.current;}

            //operator d'indirection : déférencement (*it)
            const T &operator*() const{ return *current;}

        };// fin iterator

        const_iterator begin() const {return const_iterator(tab);}
        const_iterator end() const {return const_iterator(tab+this->nbEl);}

    };


    };





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
    if(i< Contener<T>::nbEl) // ou this->nbEl ou using Contener<T>::nbEl. On préfère utiliser this
        // !!!!! il faut spécifier l'opérateur de résolution pour utiliser nbEl : Contener<t>::nbEl
        // voir p.80 ou 84 ? diapo 14
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
