//
// Created by Minh Tri on 11/05/2017.
//

#include "timing.h"
#include<iostream>
#include "evenement.h"


using namespace TIME;
using namespace std;
#include "log.h"


//void Mylog::addEvt(const TIME::Date &d, const TIME::Horaire &h, const string &s){
//    //*this<<TIME::Evt1jDur(d,s,h,TIME::Duree(0));  //avec héritage privé Agenda
//    evts<<TIME::Evt1jDur(d,s,h,TIME::Duree(0)); // sans héritage private Agenda
//
//}
// l'héritage public de Agenda dans Mylog aurait permis de faire :
/*
 * Mylog mlog;
 * EvtPj e(...);    // création d'un élément EvtPj
 * mlog<<e; //operator << public de Agenda pour insérer un évènement
 *
 *  ===> Erreur car on traite uniquement le cas de Evt1jDur et pas de EvtPj.
 *
 */

void Mylog::displayLog(std::ostream f) const{
    for(Agenda::iterator it=evts.begin();it!=evts.end();++it){
        f<<(*it).getDate()<<" - "<< dynamic_cast<const TIME::Evt1jDur &>(*it).getHoraire()<<" : "<<(*it).getDescription()<<endl;
    }


}

void Mylog::addEvt(const TIME::Date &d, const TIME::Horaire &h, const string &s) {
    if(begin()!=end()){
        const TIME::Evt1jDur & lastEvent= dynamic_cast<const TIME::Evt1jDur &>(*(--end()));
        if(d<lastEvent.getDate() || (d==lastEvent.getDate() && h<lastEvent.getHoraire())){
            throw LogError("Addition of a posterior event");
        }

        *this<<TIME::Evt1jDur(d,s,h,TIME::Duree(0));
    }



}