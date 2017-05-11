#include <iostream>
#include "evenement.h"
int main(){
    using namespace std;
    using namespace TIME;
//    Evt1j e1(Date(4,10,1957),"Spoutnik");
//    Evt1j e2(Date(11,6,2013),"Shenzhou");
//    Evt1jDur e3(Date(11,6,2013),"Lancement de Longue Marche",Horaire(17,38),Duree
//            (0,10));
//    e1.afficher();
//    e2.afficher();
//    e3.afficher();

    { // début de bloc
        Rdv e(Date(11,11,2013),"reunion UV",Horaire(17,30),Duree(60),"Intervenants UV","bureau");
        std::cout<<"RDV:";
        e.afficher();
    } // fin de bloc

    Evt1j e1(Date(4,10,1957),"Spoutnik");
    Evt1j e2(Date(11,6,2013),"Shenzhou");
    Evt1jDur e3(Date(11,6,2013),"Lancement de Longue Marche",Horaire(17,38),Duree
            (0,10));
    Rdv e4(Date(11,4,2013),"reunion UV",Horaire(17,30),Duree(60),"Intervenants UV","bureau");
    e1.afficher(); e2.afficher(); e3.afficher(); e4.afficher();
    Evt1j* pt1= &e1; Evt1j* pt2=&e2; Evt1j* pt3=&e3; Evt1j* pt4=&e4;
    pt1->afficher(); pt2->afficher(); pt3->afficher(); pt4->afficher();


    Rdv* pt5= new Rdv(Date(12,11,2013),"reunion UV",Horaire(17,30),Duree(60),"Intervenants UV","bureau");
    pt5->afficher();
    delete pt5;
    Evt1j* pt6= new Rdv(Date(12,11,2013),"reunion UV",Horaire(17,30),Duree(60),"Intervenants UV","bureau");
    pt6->afficher();
    delete pt6;

    // TD8

    //ex.32
    //q.1 Design pattern iterator

        Agenda monAgenda;
        monAgenda<<e1<<e2;
        for(Agenda::iterator it=monAgenda.begin();it!=monAgenda.end();++it){
            cout<<*it<<endl;
        }

    //Q.2 : Factory method

    /*
     * Relation entre Agenda et Evenement : Composition. Mais agrégation possible, => Pas de meilleure solution
     * /!\ Il faut libérer la mémoire si composition
     *
     *
     * Factory Method :
     *
     * Permet de laisser les classes filles instancier les objets
     * définir méthode 'clone' dans classe mère abstraite
     * puis la spécialiser/surcharger dans les classes filles
     *
     * => Au lieu de faire tab[nbEvts++]=new Evt1j(e);.... (créer un nouvel objet, et sans utiliser 'new')
     *      => tab[nbEvts++]=e.clone(); où clone est appelée sur l'objet e et par la surcharge de cette méthode
     *          cela permet de cloner l'objet e.
     *
     *
     *
     */















    return 0;
}