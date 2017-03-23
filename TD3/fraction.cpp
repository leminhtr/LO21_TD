//
// Created by Minh Tri on 23/03/2017.
//

#include "fraction.h"
#include <iostream>


using namespace std;
using namespace MATH;

//Constructeurs
//Fraction::Fraction() //: numerateur(0), denominateur(0)
//{
//    setFraction(0,1);
//}

//Fraction::Fraction(int n, int d) {  //redéfinition du constructeur : le constructeur par défaut n'est pas générée.
//    setFraction(n,d);
//}

//Fraction::Fraction(int n) {
//    setFraction(n,1);
//}


//Fraction::Fraction(int n=0, int d=1)
//
//Fraction::Fraction(int n=0, int d=1){ //default
//    Fraction::setFraction(n,d);};

void Fraction::setFraction(int n, int d) {    //accès à la fonction setFraction de la classe Fraction du namespace MATH

    numerateur=n;

    if(d==0) {
        cerr << "erreur : dénominateur nul !!" << endl; //cerr : output erreur
        denominateur=1;
    }
    simplification();
}

void Fraction::simplification()
{
    // si le numerateur est 0, le denominateur prend la valeur 1
    if (numerateur==0)
    { denominateur=1; return; }
    /* un denominateur ne devrait pas être 0;
    si c’est le cas, on sort de la méthode */
    if (denominateur==0)
        return;

    /* utilisation de l’algorithme d’Euclide pour trouver le Plus Grand Commun
    Denominateur (PGCD) entre le numerateur et le denominateur */
    int a=numerateur;
    int b=denominateur;

    // on ne travaille qu’avec des valeurs positives...
    if (a<0) a=-a; if (b<0) b=-b;

    while(a!=b)
    { if (a>b)
            a=a-b;
        else
            b=b-a;
    }

    // on divise le numerateur et le denominateur par le PGCD=a
    numerateur /=a;
    denominateur /=a;
    // si le denominateur est négatif, on fait passer le signe - au denominateur
    if (denominateur<0) {
        denominateur=-denominateur;
        numerateur=-numerateur;
    }
}


const Fraction Fraction::somme(const Fraction &f1) const //ce const ne modifie pas le paramètre f1 de la class
{ // ici : passage par valeur : Coûteux car recopie d'objet : créer un objet f1 puis va copier les valeurs de la variable appelée vers f1
                                                    // ++ performant par adresse : on accède directement à l'adresse de la variable appelée pour recopie mais plus de risque de faire des erreurs
                                                    // passage par référence : moins de risque de faire des erreurs || const Fraction &f1 : l'élément référencé est constante

    int a=getNumerateur();
    int b=getDenominateur();

    int c=f1.getNumerateur();
    int d=f1.getDenominateur();

    return Fraction(a*d+c*b,b*d);
}


const Fraction Fraction::somme(const Fraction &f1, const Fraction &f2) {
    int a=f1.getNumerateur();
    int b=f1.getDenominateur();

    int c=f2.getNumerateur();
    int d=f2.getDenominateur();

    return Fraction(a*d+c*b,b*d);
}


const Fraction Fraction::operator+(const Fraction &f1) const{
    int a=getNumerateur();
    int b=getDenominateur();

    int c=f1.getNumerateur();
    int d=f1.getDenominateur();

    return Fraction(a*d+c*b,b*d);

}

const Fraction operator+(const Fraction &f1, const Fraction &f2){
    int a=f1.getNumerateur();
    int b=f1.getDenominateur();

    int c=f2.getNumerateur();
    int d=f2.getDenominateur();

    return Fraction(a*d+c*b,b*d);

}