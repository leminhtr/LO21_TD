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


// ----------------------- Exercice 12 --------------------------

void inverse (int *a, int *b){
    cout << "a=" << *a << ", b="<< *b << endl;
    int temp=*a;
    *a=*b;
    *b=temp;
    cout << "a=" << *a << ", b="<< *b << endl;
}

void inverse(int &a, int &b){
    cout << "a=" << a << ", b="<< b << endl;
    int temp=a;
    a=b;
    b=temp;
    cout << "a=" << a << ", b="<< b << endl;

}

// ----------------------- Exercice 13 --------------------------

mystruct raz (mystruct *var){
    cout << "n=" << var->n << ", x="<< var->x << endl;
    var->n=0;   // <=> (*var).n=0;
    var->x=0;   // <=> (*var).x=0;
    cout << "n=" << var->n << ", x="<< var->x << endl;
}

mystruct raz(mystruct &var){
    cout << "n=" << var.n << ", x="<< var.x << endl;
    var.n=0;
    var.x=0;
    cout << "n=" << var.n << ", x="<< var.x << endl;
}

//------------------------ Exercice 14 ---------------------------

//void truc1(const int& x){
//    std::cout<<x<<"\n";
//    x++;    // Erreur : x est const int => non modifiable
//    std::cout<<x<<"\n";
//}
//
//void truc2(int& x){
//    x++;
//    truc1(x);
//    x++;
//}
//void truc3(const int& x){
//    truc2(x);   // erreur : truc2 peut modifier la valuer de x qui est const int donc non modifiable
//                // Correction : On peut appeler truc1(x)
//    double y=x; // Conversion implicite entre valeur ok
//    double& z=x;    //erreur : lvalue de type int. Expected : lvalue type double
//                    // Mais const &z=x; OK
//    double& u=y;    // Ok passage référence double avec double
//    double& t=y-3;  // Erreur : y-3 n'est pas une lvalue : y-3 n'est pas stockée durablement en mémoire => Erreur passage référence rvalue
//}                   // const double &t =y-3; OK passage référence const lvalue



//------------------------ Exercice 15 ---------------------------

void init(point* pt, int _x, int _y, int _z) {
    pt->x=_x; pt->y=_y; pt->z=_z;
}
//// Les 3 fonctions suivantes sont redondantes à la première
//void init(point* pt, int _x, int _y) {
//    pt->x=_x; pt->y=_y; pt->z=0;
//}
//void init(point* pt, int _x) {
//    pt->x=_x; pt->y=0; pt->z=0;
//}
//void init(point* pt) {
//    pt->x=0; pt->y=0; pt->z=0;
//}
void essai_init() {
    point p;
    init(&p);
    init(&p,1);
    init(&p,1,2);
    init(&p,1,2,3);
}


//------------------------ Exercice 16 ---------------------------
/*
 *  Rappel : Allocation dynamique
 *
 *      En C : T *p=(T*)malloc(sizeof(T));
 *              T *pArray=(T*)malloc(taille*sizeof(T));
 *
 *      T *p= new T; : 1) Alloue un espace mémoire de type T
 *                      2) Fais pointer p sur l'espace mémoire alloué
 *      T *pArray= new T[taille];
 *
 *      Libération mémoire :
 *
 *          delete et delete[];
 *              delete p;   // en C : free(p);
 *              delete[] pArray;    // en C : free(pArray);
 *
 */


void essai_alloc(){
    //pt_int=(int*)malloc(sizeof(int));
    int *pt_int= new int;
    //pt_double=(double*)malloc(sizeof(double)*100);
    double *pt_double= new double[100];

    //free(pt_int);
    delete pt_int;
    //free(pt_double);
    delete[]pt_double;
}

//------------------------ Exercice 17 ---------------------------
void raz17(personne *p){
    p->age=0;
    //p->nom="";  Erreur et = adresse du 1er élément du tableau de char.
    *p->nom='\0';   // <=> (p->nom)[0]='\0';
}

void affiche_struct(const personne * p){
    cout << "La personne s'appelle : " << p->nom << " et a " << p->age << " ans." << endl;
}

void affiche_tab(const personne *tab_pers, int nb_pers ){   //tab_pers est l'adresse du 1er élément du tableau de personne
    for(int i=0; i< nb_pers; i++)
    {
        affiche_struct(tab_pers);
        tab_pers++; //élément suivant du tableau <=> adresse pointée incrémente
    }


}

void init_struct(personne *pers, const unsigned int n, const char *name){
    pers ->age=n;
    char *pt=pers->nom; //Pointeur vers emplacement mémoire du 1er caractère du nom

    while(*name){   //0 <=> '\0' => tant que *name != 0
        *pt=*name;
        ++pt;
        ++name;
    }

    *pt='\0';
}

void copy_struct(const personne *source, personne *dest){
    *dest=*source; // Possible d'initialiser une structure avec une autre structure : Copie champ par champ
}

void copy_tab(const personne *tab_pers_source, personne *tab_pers_dest, const int n){
    for(int i=0; i<n; i++){
        tab_pers_dest[i]=tab_pers_source[i];    // <=> *(source+i)
    }
}







