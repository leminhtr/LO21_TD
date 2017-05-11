#include "evenement.h"
#include <iostream>
#include <sstream>
//sstream : string qui se comporte comme un ostream "une string"<<"suite";

using namespace TIME;

std::ostream& operator<<(std::ostream& f,
                         const TIME::Evt& e){
        e.afficher(f);
        return f;
    }

TIME::Agenda& TIME::Agenda::operator<<(const Evt& e){
    if(nb==nbMax){
        Evt** tab=new Evt* [nbMax+5];
        for(unsigned int i=0; i<nb; i++) tab[i]=evts[i];
        nbMax+=5;
        Evt** old=evts;
        evts=tab;
        delete[] old;
    }
    evts[nb++]=const_cast<Evt*>(&e);
    return *this;
}

void TIME::Agenda::afficher(std::ostream& f) const{
    f<<"===================AGENDA===================\n";
    for(unsigned int i=0; i<nb; i++) evts[i]->afficher(f);
}

TIME::Agenda::~Agenda(){
    delete[] evts;
}
// pratiquement, pas de resp donc ne detruit pas les evenements #agregation


// TD8

//ex.32

//Q.2

TIME::Evt1j *TIME::Evt1j::clone() const {return new Evt1j(*this);}  //tab[nb++]=evt.clone(); : appel de clone sur l'objet evt (==*this),
                                                                    // puis créer le new objet approprié
TIME::Evt1jDur *TIME::Evt1jDur::clone() const {return new Evt1jDur(*this);}
TIME::Rdv *TIME::Rdv::clone() const {return new Rdv(*this);}
TIME::EvtPj *TIME::EvtPj::clone() const {return new EvtPj(*this);}


string TIME::Evt1j::toString() const {
    stringstream f;
    f<<"*********** Evt ***"<<endl;
    f<<"Date= "<<getDate()<<"objet "<<getDescription()<<endl;

    return f.str();
}

string TIME::EvtPj::toString() const {
    stringstream f;
    f<<"*********** Evt ***"<<endl;
    f<<"Debut= "<<getDebut()<<"Fin "<<getFin()<<endl;

    return f.str();
}

string TIME::Evt1jDur::toString() const {
    stringstream f;
    f<<"*********** Evt ***"<<endl;
    f<<"Duree= "<<getDuree()<<"Horaire "<<getHoraire()<<endl;

    return f.str();
}


string TIME::Rdv::toString() const {
    stringstream f;
    f<<"*********** Evt ***"<<endl;
    f<<"Lieu= "<<getLieu()<<"Personnes "<<getPersonnes()<<endl;

    return f.str();
}
