#if !defined(_EVENEMENT_H)
#define _EVENEMENT_H

#include <iostream>
#include <string>
#include "timing.h"


// Quand specialisation de classe, il faut s'arranger pour utiliser méthode virtuelle.

namespace TIME{

    class Evt{
        std::string sujet;
    public:
        const std::string &getDescription() const {return sujet;}
        virtual void afficher (std::ostream &f= std::cout)const=0;
        Evt(const std::string &s):sujet(s){}

        virtual ~Evt();
    };

    class EvtPj : public Evt {
    private:

        Date debut;
        Date fin;

    public:

        EvtPj(const Date& d, const Date &f, const std::string &s):Evt(s),debut(d),fin(f){
            //std::cout<< "Construction EvtPj :" <<this<<"\n";
            // }   //-> 1 constructeur explicite + 1 constructeur de recopie implicite

        const Date& getDebut() const { return debut;}
        const Date& getFin() const { return fin;}

        virtual void afficher(std::ostream& f= std::cout) const {    // résout le polymorphisme <=> les classes filles ont "leurs propres" méthodes de classe afficher

            f<<"***** Evt ********"<<"\n"<<"Debut="<<debut<<" fin="<<fin()<<"sujet="<<getDescription()<< "\n";

        }
        ~EvtPj(){std::cout <<"Destruction EvtPj :"<<this<<"\n";}
    };

    class Evt1j :public Evt{
    private:

        Date date;

    public:

        Evt1j(const Date& d, const std::string& s):Evt(s),date(d){std::cout<< "Construction Evt1j :" <<this<<"\n";}   //-> 1 constructeur explicite + 1 constructeur de recopie implicite


        //const std::string& getDescription() const { return getDescription(); }
        const Date& getDate() const { return date; }

        virtual void afficher(std::ostream& f= std::cout) const {    // résout le polymorphisme <=> les classes filles ont "leurs propres" méthodes de classe afficher

            f<<"***** Evt ********"<<"\n"<<"Date="<<date<<" sujet="<<getDescription()<<"\n";

        }
        // ex30 q2
        virtual ~Evt1j(){std::cout <<"Destruction Evt1j :"<<this<<"\n";}
    };

    class Evt1jDur : public Evt1j{

        Horaire horaire;
        Duree duree;

    public:

        Evt1jDur(const Date &d, const std::string &s,
                 const Horaire &h, const Duree &dur):
                Evt1j(d,s), horaire(h), duree(dur){
            std::cout<<"Construction Evt1jDur :"<<this<<"\n";

        }
        const Horaire &getHoraire() const {return horaire;}
        const Duree &getDuree() const{ return  duree;}
        void afficher (std::ostream& f= std::cout) const{
            Evt1j::afficher(f);
            f<<"Horaire="<<horaire<<"\n"<<"Duree"<<duree<<"\n";
        }

        ~Evt1jDur(){std::cout <<"Destruction Evt1jDur :"<<this<<"\n";}


        // Ex.29
//        Evt1jDur(const Evt1jDur &e):
//                Evt1j(e.getDate(),e.getDescription()), // méthode 1
//                //Evt1j(e), horaire(e.horaire, e.duree){}
//
//        // Ex.29
//        Evt1jDur &operator=(const Evt1jDur &e){
//           /*
//            * Interdit d'accéder au éléments privé
//                date=e.date;
//                sujet=e.sujet;
//            */
//            Evt1j::operator=(e);    // Sol. -> On utilise l'opérateur d'affectation de la classe mère
//            horaire=e.horaire;
//            duree=e.duree;


        //return  *this;
//        }



    };

    class Rdv : public Evt1jDur{

        std::string personnes;
        std::string lieu;

    public:

        Rdv(const Date &d, const std::string &s,
            const Horaire &h, const Duree &dur,
            const std::string &p, const std::string &l):
                Evt1jDur(d,s,h,dur), personnes(p), lieu(l){
            std::cout<<"Construction Rdv :"<<this<<"\n";

        }

        const std::string &getPersonnes() const { return  personnes;}
        const std::string &getLieu () const { return lieu;}
        void afficher (std::ostream& f= std::cout) const{
            Evt1j::afficher(f);
            f<<"Personnes="<<personnes<<"\n"
             <<"Lieu"<<lieu<<"\n";
        }
        ~Rdv(){std::cout <<"Destruction Rdv :"<<this<<"\n";}


    };

    std::ostream &operator<<(std::ostream &f, const TIME::Evt& e);

    // Q.3
    class Agenda {

        Evt** evts; //plus Evt1j mais Evt
        unsigned int nb;
        unsigned int nbMax;
        Agenda(const Agenda &a);
        Agenda &operator=(const Agenda &a); // interdit la duplication

    public:
        Agenda():evts(nullptr),nb(0),nbMax(0){}
        Agenda &operator<<(const Evt &e);
        void afficher(std::ostream &f=std::cout) const;
        virtual ~Agenda();



    };

};
#endif