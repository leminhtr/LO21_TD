#include <QApplication>
#include <QString>
#include "ArticleEditeur.h"
#include <QLineEdit>
#include "Notes.h"
#include <QMessageBox>
#include <QLineEdit>
#include <QTextEdit>


ArticleEditeur::ArticleEditeur(Article &art, QWidget *parent):
    QWidget(parent), article(&art)
    // appel au constructeur de QWidget en lui donnant en paramètre "parent"
    // initialisation de article avec le paramètre art
{
    // tous les Widget créés ont comme parent l'objet de type ArticleEditeur

    // Création des objets Widgets
    id=new QLineEdit(this);
    titre=new QLineEdit(this);
    text= new QTextEdit(this);

    save= new QPushButton("Sauver", this);

    id1= new QLabel("Identificateur", this);
    titre1=new QLabel("Titre", this);
    text1= new QLabel("Texte", this);

    // Création du layout de la fenêtre
    cid=new QHBoxLayout;
    cid->addWidget(id1);
    cid->addWidget(id);

    ctitre=new QHBoxLayout;
    ctitre->addWidget(titre1);
    ctitre->addWidget(titre);

    ctext=new QHBoxLayout;
    ctext->addWidget(text1);
    ctext->addWidget(text);

    couche= new QVBoxLayout;
    couche->addLayout(cid);
    couche->addLayout(ctitre);
    couche->addLayout(ctext);
    couche->addWidget(save);

    id->setReadOnly(true);

    id->setText(article->getId());
    titre->setText(article->getTitle());
    text->setText(article->getText());

    setLayout(couche);

    save-> setEnabled(false);

    // Q.2 : Connection SIGNAL -> SLOT pour la méthode saveArticle()
    QObject::connect(save, SIGNAL(clicked()), this, SLOT(saveArticle()));

    // Q.3

    // quand on édite un objet de type LineEdit, le signal textEdited est activé
    QObject::connect(titre, SIGNAL(textEdited(QString)), this, SLOT(activerSave()));
    // quand on édite un objet de type textEdit, le signal textEdited est activé
    QObject::connect(text, SIGNAL(textChanged()),this, SLOT(activerSave()));



}

// Q.2
void ArticleEditeur::saveArticle(){ //on sauvegarde dans article puis quand le destructeur de NotesManger est appelée,
    // la fonction save() enregistre le fichier xml -> PAS AVANT !
    // Si on ne clique pas sur save et qu'on quitte => pas d'enregistrement
    // Si on clique sur save , enregistrement au moment de quitter la fenêtre
    article->setTitle(titre->text());
    article->setText(text->toPlainText());
    QMessageBox::information(this, "Sauvegarde", "Votre article a bien été sauvé.");

    // Q.3
    save-> setEnabled(false);
}

// Q.3
void ArticleEditeur::activerSave(QString){
    save->setEnabled(true);
}

















