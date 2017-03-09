//
// Created by Minh Tri on 09/03/2017.
//

#include "ex10.h"

//double* pt1=4096; //conversion implicite de int vers double : n
double* pt2=(double*)4096;  //conversion explicite int vers double : y
void* pt3=pt1;  //conversion implicite double -> void : y
pt1=pt3;    //conversion implicite void -> double : n
pt1=(double*)pt3;   //conversion explicite double -> double : y
double d1=36;   //ok
const double d2=36; //ok
double* pt4=&d1;    //ok
const double* pt5=&d1;  //conversion implicite double -> const double
*pt4=2.1;   // ok : d1=*pt4=2.1
*pt5=2.1;   // erreur affectation const double : n
pt4=&d2;    //erreur : pas de conversion de const double -> double
pt5=&d2;    // affectation const double -> const double : y
double* const pt6=&d1;  // double -> const double : ok
pt6=&d1;    //erreur : affectation const double : n
*pt6=2.78;  //ok : pt6 est un pointeur constant (<=> la valeur de pt6 inchangeable) != n'est pas pointeur const (<=> valeur de *pt6, pointée par pt6 inchangeable)
    // ==> Ok.
double* const pt6b=&d2; // ok
const double* const pt7=&d1;    //
pt7=&d1;
*pt7=2.78;
double const* pt8=&d1;
pt8=&d2;
pt8=&d1;
*pt8=3.14;