//
// Created by Minh Tri on 30/03/2017.
//

#include "notes.h"
#include <iostream>

ostream & operator<<(ostream &f, const Article &a){ //il faut que l'opérateur << renvoie un ostream 'f'

    f << a.getId() <<endl;
    f << a.getTitle() <<endl;
    f << a.getText() <<endl;
    return f;

}

//f <<a.getText() << endl;
// (f <<a.getText()) << endl;


NotesManager::NotesManager() :articles(0),nbArticles(0), nbMaxArticles(0), filename("tmp.dat")
// pointeur 'articles' à 0; initialement pas d'articles (nbArticles=0)
{}

NotesManager::~NotesManager() { // Relation de composition NotesManager 1-----* Articles
    // Libération de la mémoire alloué dynamiquement à chaque article
    for(unsigned int i=0;i<nbArticles;i++){
        delete articles[i];
    }
    //Libération de la mémoire alloué dynamiquement au tableau de pointeurs
    delete[] articles;

}

NotesManager::NotesManager(const NotesManager &m):
        articles(new Article*[m.nbMaxArticles]),
        nbArticles(m.nbArticles),
        nbMaxArticles(m.nbMaxArticles),
        filename(m.filename)
{
    for(unsigned int i=0;i<nbArticles;i++){
        articles[i]=new Article(*m.articles[i]);
    }


}

NotesManager &NotesManager::operator=(const NotesManager &m){
    if(this!=&m){   //Contrôle de non auto affectation
        // Création du tableau contenant l'adresse des articles
        Article ** newarticles=new Article*[m.nbMaxArticles];
        for(unsigned int i=0;i<m.nbArticles;i++){
            newarticles[i]=new Article(*m.articles[i]);
        }

        for(unsigned int i=0; i<nbArticles;i++){
            delete articles[i];
        }
        // Supprime l'ancien tableau
        delete[] articles;

        // Copie les attributs
        articles=newarticles;
        nbArticles=m.nbArticles;
        nbMaxArticles=m.nbMaxArticles;
    }

    return *this;
}



Article & NotesManager::getNewArticle(const string &id) {
    Article *a = new Article(id, "", "");
    addArticle(a);
    return *a;
}


// Référencer l'article crée dans le tableau 'articles'
// Lever une exception si article avec même idenfitiant existe déjà
// Gérer le redimensionnement du tableau 'articles
void NotesManager::addArticle(Article *a) {
    // Vérifie qu'un article avec même identifiant n'existe pas déjà
    for(unsigned int i=0; i<nbArticles;i++){
        if(articles[i]->getId()==a->getId())  //(*articles[i]).getId()
            throw NotesException("Error : creation of an already existent note");
    }

    // Agrandit l'espace mémoire si nécessaire
    if(nbArticles==nbMaxArticles){
        //Agrandit l'espace mémoire
        nbMaxArticles+=5;

        //Alloue de la mémoire pour stocker les pointeurs vers les articles
        Article ** newArticle=new Article*[nbMaxArticles];

        // Recopie les adresses des articles depuis l'ancien tableau vers le nouveau
        for(unsigned int i=0;i<nbArticles;i++){
            newArticle[i]=articles[i];
        }

        // Stocke l'adresse de l'ancien tableau pour libérer la mémoire
        Article ** oldArticles = articles;
        articles = newArticle;

        // Si l'adresse de l'ancien tableau est null, pas besoin de libérer la mémoire
        // Gère le cas du 1er appel de la méthode, où oldArticle est null
        if(oldArticles){
            delete[] oldArticles;
        }

    }

    // Stocke l'adresse du nouvel article
    articles[nbArticles++]=a;

}



// Renvoie un article a selon un id
Article & NotesManager::getArticle(const string &id) {
    for(unsigned int i=0; i<nbArticles;i++){
        if(articles[i]->getId()==id)    // Si l'article a été trouvé
            return *articles[i];
    }

    // On arrive ici uniquement si l'article demandé n'a pas été trouvé
    throw NotesException("Error, non existent note");

}




