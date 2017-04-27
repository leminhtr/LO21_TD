#include "evenement.h"

using namespace TIME;

std::ostream &operator<<(std::ostream &f,
                         const TIME::Evt& e){
    e.afficher(f);  // e peut être n'importe quel objet de classe Evt1j, Evt1jDur ou Rdv donc 1 fonction suffit et fonctionne.
    return f;
}


//std::ostream &operator<<(std::ostream &f,
//                         const TIME::Evt1j& e){
//    e.afficher(f);  // e peut être n'importe quel objet de classe Evt1j, Evt1jDur ou Rdv donc 1 fonction suffit et fonctionne.
//    return f;
//}


// La classe Agenda n'est pas propriétaire de Evt1J => Donc relation d'agrégation entre Evt1j et Agenda
Agenda & Agenda::operator<<(const Evt1j& e){

    if(nb==nbMax){
        Evt** tab=new Evt*[nbMax+5];
        for(unsigned int i=0;i<nb;i++){
            tab[i]=evts[i];
        }
        nbMax+=5;
        Evt1j** old=evts;
        delete[] old;   // On delete avec old et non evts car toutes les opérations avant sont intègres et donc il est plus facile de debuger les exceptions
        // en créant une nouvelle variable juste avant la destruction
    }

    evts[nb++]= const_cast<Evt*>(&e);

    return *this;
}

void Agenda::afficher (std::ostream &f) const{
    f<<"=================== AGENDA ===================\n";
    for (unsigned int i=0; i<nb; i++)   //boucle
        evts[i]->afficher(f);

};

Agenda::~Agenda(){
    delete[] evts;

};





