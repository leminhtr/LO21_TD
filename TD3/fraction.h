//
// Created by Minh Tri on 23/03/2017.
//

#ifndef TD3_FRACTION_H
#define TD3_FRACTION_H

//Q.1
namespace MATH
{
    class Fraction {    //private par défaut

    public :
        int numerateur;
        int denominateur;

        inline int getNumerateur() const {return numerateur;}  //fonction courte -> inline mieux |||||| const : ne modifie pas l'objet sur laquelle elle est appelée : foo.getNumerateur();
        inline int getDenominateur() const { return denominateur}    // fonction courte -> inline mieux |||||| const : ne modifie pas l'objet sur laquelle elle est appelée

        void setFraction(int n, int d);


    };
}

#endif //TD3_FRACTION_H
