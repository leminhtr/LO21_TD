#include<iostream>
#include <string>
#include "fonction.h"
#include<stdio.h>


using namespace std;

void bonjour() {
    cout<<"Entrez votre prenom :";
    string prenom;
    cin>>prenom;
    cout<<"Bonjour "<<prenom<<"\n";
}

//Ex.5
void exerciceA(){//aire d'un cercle

    //printf("donnez le rayon entier d’un cercle:");
    cout << "donnez le rayon entier d’un cercle";
    int r;
    cin >> r;
    //scanf("%d",&r);
    double p, s;
    const double PI=3.14159;
    p=2*PI*r;
    s=PI*r*r;
    //printf("le cercle de rayon %d ",r);
    cout << "le cercle de rayon" << r;
    //printf("a un perimetre de %f et une surface de %f\n",p,s);
    cout << "a un perimetre de %f " << p << "et une surface de " << s;
}

void exercice_surcharge() {
    int i = 3, j = 15;
    float x = 3.14159, y = 1.414;
    char c ='A';
    double z = 3.14159265;
    fct(i); //appel 1
    fct(x); //appel 2
    fct(i, y); //appel 3
    fct(x, j); //appel 4
//    fct(c); //appel 5
    fct(i, (float)j); //appel 6
    fct(static_cast<float>(i),j);//appel 6

    fct((float)i, c); //appel 7
    fct(static_cast<float>(i),c);//appel 7

    fct(i, z); //appel 8

    fct((int)z, z); //appel 9
    fct(z, static_cast<int>(z));//appel9

}






