#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QTextEdit>

#include <QVBoxLayout>  // positionnement vertical
#include <QHBoxLayout>  // positionnement horizontal

#include "Notes.h"
#include <QFileDialog>  // boite de dialogue pour ouvrir fichier



int main(int argc, char *argv[]) {

QApplication app(argc, argv);
QWidget fenetre;
fenetre.setFixedSize(300, 300);


// Q.1

// Création des objets
QLabel id1("Identificateur", &fenetre);
QLabel titre1("Titre", &fenetre);
QLabel text1("Texte",&fenetre);

QLineEdit id(&fenetre);
QLineEdit titre(&fenetre);

QTextEdit text(&fenetre);

QPushButton save("Sauver", &fenetre);

// Paramétrage taille et position
//id1.move(10,10);
//titre1.move(10,45);
//text1.move(10,80);

//id.setFixedWidth(180);
//id.move(100,10);

//titre.setFixedHeight(180);
//titre.move(100,80);

//text.setFixedSize(180,110);

//save.setFixedWidth(80);
//save.move(200,170);

// Q.2

QHBoxLayout cid;
cid.addWidget(&id1);    // widget id1 (label) sera à gauche du widget id (zone de texte)
cid.addWidget(&id);     // -> Le tout = objet horizontal 'cid'.

QHBoxLayout ctitre;         // widget titre1 (label) sera à gauche du widget titre (zone de texte)
ctitre.addWidget(&titre1);
ctitre.addWidget(&titre);

QHBoxLayout ctext;      // widget text1 (label) sera à gauche du widget text (zone de texte)
ctext.addWidget(&text1);
ctext.addWidget(&text);

QVBoxLayout couche;     // On adjoute les widgets verticalement : du haut vers le bas (3 layout horizontaux)
couche.addLayout(&cid); // -> 'cid' sera en haut et au dessu de 'ctitre'
couche.addLayout(&ctitre);
couche.addLayout(&ctext);
couche.addWidget(&save);

fenetre.setLayout(&couche);

// Q.3
id.setReadOnly(true);   //id en lecture seule
QString filename= QFileDialog::getOpenFileName();   //chercher le fichier xml
NotesManager &m=NotesManager::getManager(); //créer une instance de NotesManager
m.setFilename(filename); //fixer le nom du fichier dans l'instance NotesManager
m.load();   //charger le fichier

Article &a=m.getArticle("id:to_read");  //Dans le XML, chercher l'article d'identifiant "id:to_read"
id.setText(a.getId());   //afficher les différentes valeurs dans la fenêtre
titre.setText(a.getTitle());
text.setText(a.getText());






fenetre.show();
return app.exec();
}
