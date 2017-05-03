//
// Created by Minh Tri on 09/03/2017.
//

#ifndef TD1_FONCTION_H
#define TD1_FONCTION_H
#include "essai.h"
//using namespace std;

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

void inverse(int *a, int *b);
void inverse(int &a, int &b);


//------------------- Exercice 13 --------------------
struct mystruct {
    int n;
    float x;
};

// mystruct var1={7, 3.14};
// var1.n=3;
// mystruct var2=var1;

//mystruct *pt1= &var1;
// (*p).i; <=> p-> i;

mystruct raz(mystruct *var);   // passage par adresse
mystruct raz(mystruct &var);   // passage par référence




//------------------- Exercice 14 --------------------
void truc1(const int& x);
void truc2(int& x);
void truc3(const int& x);


//------------------- Exercice 15 --------------------

/* Rappel : Valeur par défaut :
*
*       Fixés dans la déclaration de la fonction
*       Derniers de la liste des arguments
*       Pas forcément des constantes
*
*/

struct point {
    int x;
    int y;
    int z;
};

void init(point* pt, int _x=0, int _y=0, int _z=0);

void essai_init();

//------------------- Exercice 16 --------------------

void essai_alloc();


//------------------- Exercice 17 --------------------

/*  Rappel : Tableaux
 *
 *      /!\ Pas de transmission de tableau par valeur en argument d'une fonction
 *          MAIS ADRESSE 1er élément (tab ou &tab[0]) = OK
 *      /!\ Tableau peut être initialisé mais PAS affecté directement (tab1=tab2 interdit)
 *
 *      string : tab de char : char str[10] : taille_max de la string : 9+'\0' = 10 char
 *
 *
 *
 *      Exemple :
 *
 *          int tab[]={2,3,4,5};
 *
 *          char str[10]="arbre" // arbre = lvalue <=> const char[6]
 *
 */
struct personne {
    char nom[30];
    unsigned int age;
};

void raz17(personne *p);
void affiche_struct(const personne * p);
void affiche_tab(const personne *tab_pers, int nb_pers );
void init_struct(personne *pers, const unsigned int n, const char *name);
void copy_struct(const personne *source, personne *dest);
void copy_tab(const personne *tab_pers_source, personne *tab_pers_dest, const int n);




#endif //TD1_FONCTION_H