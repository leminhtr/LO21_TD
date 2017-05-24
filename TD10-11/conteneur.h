//
// Created by Minh Tri on 24/05/2017.
//

#if !defined(_Contener_T_H)
#define _Contener_T_H
#include<string>
#include<stdexcept>


namespace TD {

    //template : classe de classe
    /* On peut remplacer le template par une autre classe
     *
     *
     */

    class ContenerException : public std::exception {
    protected :
        std::string info;
    public:
        ContenerException(const std::string& i="") throw() :info(i){}
        const char* what() const throw() { return info.c_str(); }
        ~ContenerException()throw(){}
    };


    template<class T>
    class Contener {

    protected:
        unsigned  int nbEl;

    public:
        // constructeur qui initialie le nombre d'éléments
        // taille du conteneur

        Contener(unsigned int n) : nbEl(n) {}

        //le destructeur est virtual car la classe contener va être héritée par d'autre classes
        // => nécessaire pour que désallocation dynamique
        virtual ~Contener() {}

        // ces méthodes ne seront pas redéfinie/modifiée dans les classes filles onc elles sont délcarées comme non virtuelles

        unsigned int size() const {return nbEl;}
        bool empty() const { return nbEl==0;}

        // il est nécessaire de définir les méthodes front/back dans le même fichier .h (donc ici)
        // elles sont des method template (template method)
        virtual T& front();
        virtual T& back();

        virtual const T& front() const;
        virtual const T& back() const;


        // méthode virtuelle pure (=0) : abstract donc pas définie ici mais dans les classes filles
        // car leurs définition dépend fortement de la structure de données : pile, file, arbre, tableau, liste,...
        virtual T& element(unsigned int i)=0;
        virtual const T& element(unsigned int i) const =0;

        virtual void push_back(const T& x)=0;
        virtual void pop_back()=0;

        // la méthode pop_back n'est pas définie ici mais elle peut être
        //appelée pour définir la méthode clear
        virtual void clear() {  // pop tous les éléments
            while(!empty())
                pop_back();
        }




    };






}

//chaque méthode (même non-inline) doit être définie dans le fichier .h
// définition des méthodes front/back en dehors du namespace
// elles doivent être précédés de "template<class T>"

template<class T> T& TD::Contener<T>::front() {
    if(!empty())
        return element(0);
    //else
    throw ContenerException("Erreur Contener : demande hors limite");
}

template<class T> T& TD::Contener<T>::back() {
    if(!empty())
        return element(nbEl -1);
    //else
    throw ContenerException("Erreur Contener : demande hors limite");

}

template <class T> const T& TD::Contener<T>::front() const {
    if(!empty())
        return element(0);

    throw ContenerException("Erreur Contener : demande hors limite");
}

template<class T> const T& TD::Contener<T>::back() const {
    if(!empty())
        return element(nbEl -1);
    //else
    throw ContenerException("Erreur Contener : demande hors limite");

}

#endif
