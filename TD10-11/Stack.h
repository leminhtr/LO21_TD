//
// Created by Minh Tri on 24/05/2017.
//

#ifndef TD10_11_STACK_H
#define TD10_11_STACK_H

#include "Vector.h"

// Soit Stack lié à Vector par héritage privé, soit par composition

namespace AC {// adaptateur de classe sur Vector<T>

    template<class T>
    class Stack : private TD::Vector<T>{    // héritage privé pour utiliser les méthodes de Vector
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
    template<class T, class CONT=TD::Vector<T> >//CONT = Vector<T> par défaut => on peut adapter n'importe quel conteneur
    class Stack1 : private CONT {

    public:
        Stack1() : CONT(0) {}// CONT() : constructeur sans paramètre de la classe

        void push(const T& x) {CONT::push_back(x);}
        void pop() {CONT::pop_back();}

        const T& top() const {return CONT::back();}
        T& top() {return CONT::back();}

        bool empty() {return CONT::empty();}
        void clear() {return CONT::clear();}


    };




};

namespace AO {// Adaptateur d'objets

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
        Stack1() : CONT(0) {}// CONT() : constructeur sans paramètre de la classe

        void push(const T& x) {cont.push_back(x);}  //on utilise les méthodes de la classe CONT directement sur l'objet cont.
                                                    // => != de CONT::push_back() (fait dans adaptateur classe)
        void pop() {cont.pop_back();}

        const T& top() const {return cont.back();}
        T& top() {return cont.back();}

        bool empty() {return cont.empty();}
        void clear() {return cont.clear();}


    };
}


#endif //TD10_11_STACK_H
