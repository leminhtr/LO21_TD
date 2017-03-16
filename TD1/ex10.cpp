//
// Created by Minh Tri on 09/03/2017.
//

// TD : benoit cantais

/*  Rappel pointeur :
 *      Syntaxe :
 *          T const *p; : p est un pointeur "const" qui pointe vers une constante de type T" => l'objet pointé est non modifiable
 *          const T *p; : pareil
            T* const p; : p est un pointeur constant vers un objet de type T => p est non modifiable
 *
 *
 *      Exemple :
 *          int a=3; a int NON constant
 *          const int *p; =&a; => interdit de modifier la valeur pointé par p (var a) même si a n'est pas constant à la base
 *              => On rajoute des contraintes : Autorisé !
 *          donc *p=6; => INTERDIT
 *
 *
 *      Règle :
 *          On peut ajouter des restrictions sans problèmes, pour en supprimer, il faut utiliser des conversions de type explicites.
 *          Un pointeur de T peut être converti (implicitement) en pointeur de void.
 *              int a=3;
 *              void *p=&a;
 *
 */

#include "ex10.h"

double* pt1=4096; //conversion implicite de int vers double : n
double* pt2=(double*)4096;  //conversion explicite int vers double : y, MAIS : pt2= adresse 4096 et *pt= ?! => danger
void* pt3=pt1;  //conversion implicite double -> void : y
pt1=pt3;    //conversion implicite void -> double : n
pt1=(double*)pt3;   //conversion explicite double -> double : y
double d1=36;   //ok
const double d2=36; //ok
double* pt4=&d1;    //ok
const double* pt5=&d1;  //conversion implicite double* -> const double*
*pt4=2.1;   // ok : d1=*pt4=2.1
*pt5=2.1;   // erreur affectation à la valeur pointée const double : n
pt4=&d2;    //erreur : pas de conversion de const double* -> double*
pt5=&d2;    // affectation const double -> const double : y
double* const pt6=&d1;  // double -> const double : ok
pt6=&d1;    //erreur : affectation à un pointeur constant : n
*pt6=2.78;  //ok : pt6 est un pointeur constant (<=> la valeur de pt6 inchangeable) != n'est pas pointeur "const" (<=> valeur de *pt6, pointée par pt6 changeable)
    // ==> Ok.
double* const pt6b=&d2; // erreur : pas de conversion const double* vers double* const (on peut ajouter restrictions mais pas en supprimer)
const double* const pt7=&d1;    //point "const" ET constant : y
pt7=&d1;    // erreur : pt7 : pointeur constant => pas de podification de la valeur d'un pointeur constant
*pt7=2.78;  // erreur : modification de la valeur pointée par p7 : *p7
double const* pt8=&d1;  // Ok <=> const double *pt8 => pointeur "const"
pt8=&d2;    // Ok
pt8=&d1;    // Ok
*pt8=3.14;  // Erreur : pointeur "const" : modification de la valeur pointée par pt8