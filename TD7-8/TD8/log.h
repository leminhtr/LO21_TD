//
// Created by Minh Tri on 11/05/2017.
//

#if !defined(LOG_H)
#define LOG_H
#include "timing.h"
#include<iostream>
#include "evenement.h"


using namespace TIME;
using namespace std;

class Log {



public:

    virtual void addEvt(const TIME::Date& d, const TIME::Horaire& h, const std::string & s)=0;
    virtual void displayLog(std::ostream& f) const=0;
};


//class Mylog: public Log, private TIME::Agenda { //héritage privé : tout élément public hérité devient privé dans la classe fille : S'applique pour tous les utilisateurs de la classe B
//                                                //Mylog ne peut pas se substituer à Agenda
//
//
//public:
//    void addEvt(const TIME::Date &d, const TIME::Horaire &h, const string &s);
//    void displayLog(std::ostream f) const;
//
//};



class Mylog: public Log{
private:
    Agenda evts;


public:
    void addEvt(const TIME::Date &d, const TIME::Horaire &h, const string &s);
    void displayLog(std::ostream f) const;

};


class LogError: public std::exception{
    std::string info;

public:
    LogError(const char * s) throw():info(s){}
    const char * what() const throw() { return  info.c_str();}//méthode virtuelle de LogError


};



#endif
