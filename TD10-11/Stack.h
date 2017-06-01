//
// Created by Minh Tri on 24/05/2017.
//

#ifndef TD10_11_STACK_H
#define TD10_11_STACK_H

#include "Vector.h"
#include "conteneur.h"

// Soit Stack lié à Vector par héritage privé, soit par composition

namespace AC {// adaptateur de classe sur Vector<T> : adaptater par héritage

    template<class T>
    class Stack : private TD::Vector<T>{    // héritage privé pour utiliser les méthodes de Vector
                                            // héritage privé <=> est implémenté en tant que "composition 1-vers-1"
                                                // membre privé de la classe mère non accessible, méthode/attributs public/protégés deviennent private
                                                // méthode/attributs public/protégés sont private
                                                // méthode virtuelle redefinissable
                                                // méthode de la classe fille peuvent convertir un pointeur/référence sur classe fille VERS objet classe mère
    public:
        Stack() : TD::Vector<T>(0) {}

        void push(const T& x) {
            TD::Vector<T>::push_back(x);}   //utilisation de la méthode push_back de Vector

        void pop() {
            TD::Vector<T>::pop_back();  //utilisation de la méthode pop_back de Vector
        }

        const T& top() const { return TD::Vector<T>::back();}
        T& top() { return TD::Vector<T>::back();}

        bool empty() { return  TD::Vector<T>::empty();}
        void clear() {TD::Vector<T>::clear();}


    };

    // DESIGN PATTERN STRATEGY
    template<class T, class CONT=TD::Vector<T> >//CONT = Vector<T> : valeur par défaut => on peut adapter n'importe quel conteneur
    class Stack1 : private CONT {

    public:
        Stack1() : CONT(0) {}// CONT() : constructeur sans paramètre de la classe

        void push(const T& x) {CONT::push_back(x);}
        void pop() {CONT::pop_back();}

        const T& top() const {return CONT::back();}
        T& top() {return CONT::back();}

        bool empty() {return CONT::empty();}
        void clear() {return CONT::clear();}


        // iterator par adaptor de classe (par héritage)

        class iterator : public CONT::iterator {

        public:
            iterator() : CONT::iterator(){}
            // typename : besoin car ambiguité => sans typename, ça peut être interprété comme un attribut static du genre "CONT::nb_element".
            // or iterator est un type de CONT
            iterator(typename CONT::iterator c) : CONT::iterator(c) {}

            // pas besoin de surcharger les opérateurs ++, ==, !=, * car ils sont déjà hérités de la class CONT::iterator

            };

        iterator begin() {return iterator(CONT::begin());}
        iterator end() {return iterator (CONT::end());}


        // CONST iterator par adaptor de classe (par héritage)

        class const_iterator : public CONT::const_iterator {

        public:
            const_iterator() : CONT::const_iterator(){}
            // typename : besoin car ambiguité => sans typename, ça peut être interprété comme un attribut static du genre "CONT::nb_element".
            // or iterator est un type de CONT
            const_iterator(typename CONT::const_iterator c) : CONT::const_iterator(c) {}

            // pas besoin de surcharger les opérateurs ++, ==, !=, * car ils sont déjà hérités de la class CONT::const_iterator

        };

        const_iterator begin() const {return const_iterator(CONT::begin());}
        const_iterator end() const {return const_iterator (CONT::end());}
    };




};

namespace AO {// Adaptateur d'objets : Composition

    template <class T>
    class Stack{
        TD::Vector<T> cont; //relation de composition

    public:
        Stack(): cont(0){}

        void push(const T& x) { cont.push_back(x);} // comme cont est un TD::Vector alors on peut directement appeler la méthode sur l'objet cont
                                                    // donc différence avec adaptateur classe = pas besoin de TD::Vector<T>::push_back() pour appeler la méthode
        void pop() { cont.pop_back();}

        const T& top() const {return cont.back();}
        T& top() {return cont.back();}

        bool empty() {return cont.empty();}
        void clear() {cont.clear();}





    };

    // DESIGN PATTERN STRATEGY
    template<class T, class CONT=TD::Vector<T> >//CONT = Vector<T> par défaut => on peut adapter n'importe quel conteneur
    class Stack1 {
        CONT cont;

    public:
        Stack1() : cont(0) {}// CONT() : constructeur sans paramètre de la classe

        void push(const T& x) {cont.push_back(x);}  //on utilise les méthodes de la classe CONT directement sur l'objet cont.
                                                    // => != de CONT::push_back() (fait dans adaptateur classe)
        void pop() {cont.pop_back();}

        const T& top() const {return cont.back();}
        T& top() {return cont.back();}

        bool empty() {return cont.empty();}
        void clear() {return cont.clear();}

        // iterator
        //
        class iterator {

            typename CONT::iterator current;

        public:
            iterator() : current(){}
            iterator(typename CONT::iterator c): current(c){}

            // il est plus optimisé d'utiliser l'opérator ++ préfixe.
            // redéfinir tous les opérateurs ++,==, !=, * car non hérité comme avec Adaptateur classe
            iterator &operator++() {++current; return  *this;}
            iterator &operator++(int) {iterator tmp = *this; current++; return tmp;}

            bool operator ==(const iterator & it) const { return current == it.current;}
            bool operator !=(const iterator & it) const {return current!= it.current;}

            T &operator*() const {return *current;}

        };

        iterator begin() {return iterator(cont.begin());}
        iterator end() { return  iterator(cont.end());}


        // const_iterator
        class const_iterator {

            typename CONT::const_iterator current;

        public:
            const_iterator() : current(){}
            const_iterator(typename CONT::const_iterator c): current(c){}

            // il est plus optimisé d'utiliser l'opérator ++ préfixe.
            // redéfinir tous les opérateurs ++,==, !=, * car non hérité comme avec Adaptateur classe
            const_iterator &operator++() {++current; return  *this;}
            const_iterator &operator++(int) {const_iterator tmp = *this; current++; return tmp;}

            bool operator ==(const const_iterator & it) const { return current == it.current;}
            bool operator !=(const const_iterator & it) const {return current!= it.current;}

            T &operator*() const {return *current;}

        };

        const_iterator begin() const {return const_iterator(cont.begin());}
        const_iterator end() const { return  const_iterator(cont.end());}









    };
}


#endif //TD10_11_STACK_H

/*
                                        Contener
                    |                                           |
 *    Adaptateur objet (Composition)                Adaptateur classe (héritage)
                    |                                           |
 *                Stack                                       Stack
          |                 |                        |                  |
 *   Adap' objet        Adap' classe            Adap' objet         Adap' classe
 *        |                 |                        |                  |
 *   Iterator           Iterator                Iterator            Iterator
 */