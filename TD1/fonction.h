//
// Created by Minh Tri on 09/03/2017.
//

#ifndef TD1_FONCTION_H
#define TD1_FONCTION_H
#include "essai.h"

//Ex.2 q1,2
//        Une université de technologie,
//        est un établissement à caractère scientifique, culturel et professionnel
//        qui a pour mission principale la formation des ingénieurs,
//        le développement de la recherche et de la technologie.
void bonjour();
void exerciceA();

// déclaration et définition des fonctions inline dans le même fichier
inline int fct(int x){ std::cout<<"1:"<<x<<"\n"; return 0; }
inline int fct(float y){ std::cout<<"2:"<<y<<"\n"; return 0; }
inline int fct(int x, float y){ std::cout<<"3:"<<x<<y<<"\n"; return 0; }
inline float fct(float x, int y){ std::cout<<"4:"<<x<<y<<"\n"; return 3.14; }
void exercice_surcharge();











#endif //TD1_FONCTION_H
