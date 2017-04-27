#include <iostream>
#include "evenement.h"


int main(){
using namespace std;
using namespace TIME;

//    Evt1j e1(Date(4,10,1957),"Spoutnik");
//    Evt1j e2(Date(11,6,2013),"Shenzhou");
//    { // début de bloc
//        Rdv e(Date(11,11,2013),"reunion UV",Horaire(17,30),Duree(60),"Intervenants UV","bureau");
//        std::cout<<"RDV:";
//        e.afficher();
//    } // fin de bloc
//
//
//    e1.afficher();
//    e2.afficher();

    // Ex. 30
    Evt1j e1(Date(4,10,1957),"Spoutnik");
    Evt1j e2(Date(11,6,2013),"Shenzhou");
    Evt1jDur e3(Date(11,6,2013),"Lancement de Longue Marche",Horaire(17,38),Duree
            (0,10));
    Rdv e4(Date(11,4,2013),"reunion UV",Horaire(17,30),Duree(60),"Intervenants UV","bureau");
    e1.afficher(); e2.afficher(); e3.afficher(); e4.afficher();
    Evt1j* pt1= &e1; Evt1j* pt2=&e2; Evt1j* pt3=&e3; Evt1j* pt4=&e4;
    pt1->afficher(); pt2->afficher(); pt3->afficher(); pt4->afficher();


system("pause");
return 0;
}