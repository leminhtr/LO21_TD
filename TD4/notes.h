//
// Created by Minh Tri on 30/03/2017.
//

#ifndef TD4_NOTES_H
#define TD4_NOTES_H


#include<string>

using namespace std;

class NotesException{
public:
    NotesException(const string& message):info(message){}
    string getInfo() const { return info; }
private:
    string info;
};

//Q.2
class Article{
private:    //Optionnel
    string id;
    string title;
    string text;

public:
    Article(const string &i, const string &ti, const string &te):id(i), title(ti),text(te) {}

//Quel est l’intérêt d’utiliser des références const pour les paramètres du constructeur ?

    //Passage par référence => épargne opération recopie de type string en mémoire
    //(que ferait le passage par valeur) sur la pile
    //const : protège l'argument des modifications
    //Permet la conversion implicite const char* vers string, on peut passer n'importe quel type

    //La classe string possède un constructeur qui prend en paramètre (const char*)
    //Une référence non const de type string doit être initialisée avec un string
    //ce n'est pas le cas pour une référence const
    //permet de créer un article de cette manière : Article a("monID", "monTitre", "leTexte");
    // => monID est un const char


    // Pour les accesseurs, le même argument que le constructeur est utilisé.

    // Accesseurs en lecture (getters)
    const string & getId() const {return id;}
    const string & getTitle() const {return id;}
    const string & getText() const {return id;}

    // Accesseurs en écriture (setters)

    void setTitle(const string & t){title=t;}
    void setText(const string & t){text=t;}


//La classe Article nécessite t-elle (a priori) un destructeur, un constructeur de recopie et/ou un opérateur d’affectation ? Expliquer

    //    Article a("idA", "titleA", "texteA");
    //    Article b(a);

    //Pas besoin de construire un constructeur par recopie car celui par défaut nous convient
        // -> le constructeur par défaut réalise l'initialisation champ par champ
    //Pas besoin de construire un constructeur d'affectation car celui par défaut nous convient
        // -> le constructeur par défaut réalise l'affectation champ par champ
    //Pas besoin de construire un destructeur car pas d'allocation dynamique : donc pas nécessaire
        // -> le constructeur par défaut, pour chaque objet de la classe fait un appel à son destructeur

    // ==> Les versions générées par défaut conviennent donc pour la classe Article

//Q.3

//Est-il possible de définir un tableau (alloué dynamiquement ou non) d’objets Article ? Expliquer

    //Si un constructeur est déclaré par l'utilisateur, le compilateur ne génère pas de constructeur sans argument.
    // à la définition d'un tableau d'objets, le constructeur sans argument est appelé pour instancier chaque objet de ce tableau
    // Un tel constructeur n'existant pas pour Article, il n'est pas possible de définir un tableau de ce type
    // => pas de tableau d'objets Article

//Est-il possible de créer un tableau (alloué dynamiquement ou non) de pointeurs d’objet Article ? Expliquer.
    // Un pointeur n'a pas besoin d'être initialisé => Il est donc possible de créer des tableaux de pointeurs d'objets Article
    // => Cette structure pourra être utilisée pour NoteManager
    // UML : Article article *[*] : tableau de pointeur vers objets de type Article de taille multiple

};

class NotesManager {
    Article** articles;
    unsigned int nbArticles;
    unsigned int nbMaxArticles;
    void addArticle(Article* a);
    string filename;
public:
    NotesManager();
    Article& getNewArticle(const string& id);
    Article& getArticle(const string& id);
};


ostream & operator<<(ostream &f, const Article &a);
















#endif //TD4_NOTES_H
