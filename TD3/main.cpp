#include <iostream>
#include "fraction.h"
#include "FractionException.h"

using namespace std;
using namespace MATH;


Fraction* myFunction(){
    Fraction fx(7,8);
    Fraction* pfy=new Fraction(2,3);
    return pfy;
}

int main() {
    std::cout << "Hello, World!" << std::endl;

//Q.1
    //MATH::Fraction f; sans 'using namespace MATH'
   // Fraction f;

//    f.numerateur=3;
//    f.denominateur=4;

//    f.getNumerateur();
//    f.getDenominateur();
//
//    f.setFraction(1,9);
//    f.setFraction(1,0);

//
   // Fraction f2(5,7);   // 1/7
//    Fraction f3(6); // 6/1
//    Fraction f4;    // 0/1


//cout << f2.getNumerateur();



//Q.6

    Fraction f1(3,4);
    Fraction f2(1,6);
    Fraction* pf3=new Fraction(1,2);
    cout<<"ouverture d’un bloc\n";
    Fraction* pf6;  //pas d'appel au constructeur pour pf6
    cout<<"cou"<<endl;
    {
        Fraction f4(3,8);
        Fraction f5(4,6);
        cout<<"hel"<<endl;
        pf6=new Fraction(1,3);  // appel au constructeur pour pf6
    }
    cout<<"fin d’un bloc\n";    // destruction auto de f4,f5 car local
    cout<<"debut d’une fonction\n";
    Fraction* pf7=myFunction();
    cout<<"fin d’une fonction\n";
    cout<<"desallocations controlee par l’utilisateur :\n";
    delete pf6;
    delete pf7;

    delete pf3;
    cout<<"fin Q.6"<<endl;
//Ex.2

//Q.1

    Fraction f10(6,6); //conversion implicite int vers fraction
    Fraction f11(7,9);


//Q.3

//préfixe, postfixe
    /*  i++; :
         *  temp=i;
         *  i=i+1;
         *  return temp;
     *
     *  ++i;
     *      i=i+1;
     *      return i;
     */

/*
 * i++=5; rvalue
 * ++i=5; lvalue
 *
 *
 */

    //cout << f10 << endl;


//Ex.3

//Q.1
    /*  levée d'exeception : rupture de séquence d'intructions déclenchée par une instruction throw
     *  throw interrompt l'execution du programme pour traiter l'anomalie
     *
     * Avantage par rapport au C :
     * si f1(f2(f3(f4))) : appels successifs
     *      si une erreur survient en f4, elle remonte en f3. Mais si f3 ne gère pas cette erreur, elle la remonte en f2, etc,... => long debugage
     *
     *
     *
     *
     *
     *
     *  après throw :
     *      chaque exception est caractérisée par un type
     *
     */

try {
    Fraction f20(6,0);
    Fraction f21(7,9);
}

    catch (const char * e){
        cout << "Exception capturée : "<< e<<endl;

    }


catch (FractionException const &e){
    cout << "Exception capturée z : "<< e.getInfo()<<endl;

}



Fraction f20(4,5);
    cout<<f20.getNumerateur()<<endl;
Fraction f21(2,5);
    cout<<f21.getNumerateur()<<endl;

    Fraction f22=f20.somme(f21);
    cout<<f22.getNumerateur()<<endl;

    Fraction f23=f20+3;
    cout<<f23.getNumerateur()<<endl;

    Fraction f24(5);
    f24++;
    cout<<f24.getNumerateur()<<endl;
    cout<<f24.getDenominateur()<<endl;









    return 0;
}