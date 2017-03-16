//
// Created by Minh Tri on 16/03/2017.
//

#include "ex11.h"


/*  Rappel : Passage par Référence
 *
 *      T &p : lvalue de type T
 *      lvalue : locator value : objet qui occupe emplacement mémoire au délà d'une expression unique
 *      rvalue : exp. qui n'est pas une lvalue
 *      Doit toujours être initialisée
 *      Pas de vue direct sur l'implémentation "bas niveau"
 *      Une référence après initialisation s'utilise directement comme si c'était la donnée référencée
 *      La référence ne peut pas être modifiée pour référencer un autre objet. <=> ~~=pointeur constant
 *
 *
 *      Exemple :
 *          int a=3;
 *          int &b=a; // => Référence à une variable de type int
 *          b=27; // modification par référence
 *
 *          const T &p=... : l'objet référence non modifiable <=> pointeur "const"
 *
 *          T &p : initialisation avec lvalue de type T : obligatoire
 *          const T &p : Référence const : Conversion implicite réalisée si nécessaire, variable temporaire de type T créee si nécessaire
 *          const int &p=32; : pas forcément d'initialisation avec lvalue : ravalue possible
 *
 */

//double& d1=36;  //erreur : une référence doit être initialisée avec une lvalue
//double d2=36;   //ok
//double& ref=d2; //ok : initialisation avec une lvalue
//ref=4;  // ok : affectation de d2 par référence
//const double d3=36; //ok
//const double& d4=36;    //ok : une référence const peut être initialisée avec une rvalue
//const double& d5=d2;    //ok : on peut ajouter des restrictions : double -> const double
//d5=21; //erreur : modification de la valeur référencée qui est const <=> pas de conversion implicite const double & -> double &
//const double& d6=d3;    // Ok
//double& ref2=d6;    //crée une référence (non const) vers une référence const double => Erreur : conversion implicite const double & -> double &
//int i=4;    //ok
//double& d7=i;   //erreur : conversion implicite int -> double
//const double& d8=i; // Affectation référence const : coversion implicite possible
//d8=3;   // erreur : modification valeur référencée const
//


