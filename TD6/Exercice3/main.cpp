#include <QApplication>
#include <QString>
#include "ArticleEditeur.h"
#include <QFileDialog>
#include "Notes.h"

int main(int argc, char *argv[]) {

QApplication app(argc, argv);
QString fichier = QFileDialog::getOpenFileName();


NotesManager& m=NotesManager::getManager();
m.setFilename(fichier);
m.load();
Article& a=m.getArticle("id:citation_babage");
ArticleEditeur fenetre(a);



fenetre.show();
return app.exec();
}
