#ifndef ARTICLEEDITEUR_H
#define ARTICLEEDITEUR_H

#include <QWidget>
#include <QLineEdit>
#include <QTextEdit>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTextEdit>
#include "Notes.h"

class ArticleEditeur : public QWidget{
    Q_OBJECT    //macro pour pouvoir utiliser les signals et les slots

    QLineEdit *id;
    QLineEdit *titre;
    QTextEdit *text;

    QLabel *id1;
    QLabel *titre1;
    QLabel *text1;

    QPushButton *save;

    QHBoxLayout *cid;
    QHBoxLayout *ctitre;
    QHBoxLayout *ctext;
    QVBoxLayout *couche;


    Article *article;   //pointeur vers l'article à afficher par la fenetre

public:
    explicit ArticleEditeur(Article &art, QWidget *parent=0);
    // explicit pour empêcher conversion implicite de article vers Article

signals:

private slots:
    // Q.3
    void activerSave(QString = "");
    // La valeur par défaut c'est pour pouvoir la connecter avec deux signals
    // l'un avec un paramètre QString
    // et l'autre sans paramètre.


public slots:

    void saveArticle();






};












#endif // ARTICLEEDITEUR_H
