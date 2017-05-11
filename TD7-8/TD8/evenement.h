#ifndef EVENEMENT_H_INCLUDED
#define EVENEMENT_H_INCLUDED

#include <iostream>
#include <string>
#include "timing.h"

using namespace std;



namespace TIME{


class Evt {
    std::string sujet;
  public:
    virtual string toString() const=0;

    const std::string& getDescription() const { return sujet; }
    virtual void afficher(std::ostream& f= std::cout) const{f.toString();} // methode virtuelle pure, son corps est un beau =0
    Evt(const std::string& s):sujet(s){}
    virtual ~Evt(){} // specialises -> polymorphisme pour respecter le principe de substitution

    //Ex.32, Q.2 Factory Method
    virtual Evt* clone() const=0; // méthode virtuelle pure

    //Q.3 Template Method



};

class EvtPj : public Evt {
  private:
    Date debut;
    Date fin;
  public:
    EvtPj(const Date& d, const Date& f, const std::string& s):Evt(s),debut(d),fin(f){
        //std::cout<<"Construction d'un objet de la classe EvtPj : "<<this<<"\n";
    }
    const Date& getDebut() const { return debut; }
    const Date& getFin() const { return fin; }
    virtual void afficher(std::ostream& f= std::cout) const {
        f<<"******** Evt ********"<<"\n"<<"Debut="<<debut<<"fin="<<fin<<" sujet="<<getDescription()<<"\n";
    }
    // EX30, Q2
    virtual ~EvtPj(){
        //std::cout<<"Destruction d'un objet de la classe EvtPj : "<<this<<"\n";
    }

    EvtPj *clone() const;

    string toString() const;

};

// Ex31, Evt et EvtPj
/*class Evt1j {
  private:
    Date date;
    std::string sujet;
  public:
    Evt1j(const Date& d, const std::string& s):date(d),sujet(s){
        std::cout<<"Construction d'un objet de la classe Evt1j : "<<this<<"\n";
    }
    const std::string& getDescription() const { return sujet; }
    const Date& getDate() const { return date; }
    virtual void afficher(std::ostream& f= std::cout) const {
        f<<"******** Evt ********"<<"\n"<<"Date="<<date<<" sujet="<<sujet<<"\n";
    }
    // EX30, Q2
    virtual ~Evt1j(){
        std::cout<<"Destruction d'un objet de la classe Evt1j : "<<this<<"\n";
    }
};*/

class Evt1j : public Evt {
  private:
    Date date;
  public:
    Evt1j(const Date& d, const std::string& s):Evt(s),date(d){
        std::cout<<"Construction d'un objet de la classe Evt1j : "<<this<<"\n";
    }
    const Date& getDate() const { return date; }
    virtual void afficher(std::ostream& f= std::cout) const {
        f<<"******** Evt ********"<<"\n"<<"Date="<<date<<" sujet="<<getDescription()<<"\n";
    }
    // EX30, Q2
    virtual ~Evt1j(){ // EX31, sar fik tchil kelmit virtual hone
        std::cout<<"Destruction d'un objet de la classe Evt1j : "<<this<<"\n";
    }

    Evt1j *clone() const;

    string toString() const;
};

class Evt1jDur : public Evt1j {
  private:
    Horaire horaire;
    Duree duree;
  public:
    Evt1jDur(const Date& d, const std::string& s,
             const Horaire& h, const Duree& du):
                 Evt1j(d,s),horaire(h),duree(du){
        std::cout<<"Construction d'un objet de la classe Evt1jDur : "<<this<<"\n";
                 }
    const Horaire& getHoraire() const { return horaire; }
    const Duree& getDuree() const { return duree; }
    void afficher(std::ostream& f= std::cout) const {
        Evt1j::afficher(f);
        f<<" horaire="<<horaire<<"duree="<<duree<<"\n";
    }
    ~Evt1jDur(){
        std::cout<<"Destruction d'un objet de la classe Evt1jDur : "<<this<<"\n";
    }
    Evt1jDur(const Evt1jDur& e):
        // Evt1j(e.getDate(),e.getDescription()),
        Evt1j(e),
        horaire(e.horaire), duree(e.duree){} // se baser sur le construteur de recopie de Evt1j
// EXERCICE 29 : Evt1j 3ando 2 constructeurs: elli 3melneh w iol a detruit el baa arguments, w el constructeur de recopie
    Evt1jDur& operator=(const Evt1jDur& e){
        // date=e.date; // mechkleh li2anno private w mech protected
        // sujet=e.sujet; // eza ma baddeh ghayyer el classe mere, besta3mel l'operateur d'affectation de la classe mere (genere par defaut) !
        Evt1j::operator=(e);
        horaire=e.horaire;
        duree=e.duree;
        return *this;
    }

    Evt1jDur *clone() const;

    string toString() const;
};

class Rdv : public Evt1jDur {
  private:
    std::string personnes;
    std::string lieu;
  public:
    Rdv(const Date& d, const std::string& s,
             const Horaire& h, const Duree& du,
             const std::string p, const std::string l):
                 Evt1jDur(d,s,h,du),personnes(p),lieu(l){
        std::cout<<"Construction d'un objet de la classe Rdv : "<<this<<"\n";
                }
    const std::string& getPersonnes() const { return personnes; }
    const std::string& getLieu() const { return lieu; }
    void afficher(std::ostream& f= std::cout) const {
        Evt1jDur::afficher(f);
        f<<" personnes="<<personnes<<" lieu="<<lieu<<"\n";
    }
    ~Rdv(){
        std::cout<<"Destruction d'un objet de la classe Rdv : "<<this<<"\n";
    }

    Rdv *clone() const;

    string toString() const;
};

/*class Agenda {
    Evt1j** evts;
    unsigned int nb;
    unsigned int nbMax;
    Agenda(const Agenda& a); // dans la partie privee pour ne pas permettre la duplication
    Agenda& operator=(const Agenda& a);
  public:
    Agenda():evts(nullptr),nb(0),nbMax(0){}
    Agenda& operator<<(const Evt1j& e);
    void afficher(std::ostream& f= std::cout) const;
    virtual ~Agenda(); // dynamique, donc baddo ya3mol delete mnih --> take care of it
};*/

// EX31? Evt et EvtPj
class Agenda {
    Evt** evts;
    unsigned int nb;
    unsigned int nbMax;
    Agenda(const Agenda& a); // dans la partie privee pour ne pas permettre la duplication
    Agenda& operator=(const Agenda& a);
  public:
    Agenda():evts(nullptr),nb(0),nbMax(0){}
    Agenda& operator<<(const Evt& e);
    void afficher(std::ostream& f= std::cout) const;
    virtual ~Agenda(); // dynamique, donc baddo ya3mol delete mnih --> take care of it

    class iterator{

        Evt** current;
        unsigned int nb_current;

        friend class Agenda;

        iterator(Evt** c, unsigned int n):current(c),nb_current(n){}

    public:
        iterator():current(nullptr), nb_current(0){}

        iterator & operator++(){
            ++current;
            return *this;
        } //++it

        iterator & operator--() {
            --current;
            return *this;
        }

        const Evt & operator*() const  { return **current;}
        bool operator==(const iterator it) const {return current==it.current;}
        bool operator !=(const iterator it) const  {return current!=it.current;}

    };

    iterator begin() const { return iterator(evts,nb);}
    iterator end() const { return iterator(evts+nb,nb);}

};

}

std::ostream& operator<<(std::ostream& f,const TIME::Evt& e);

#endif // EVENEMENT_H_INCLUDED
