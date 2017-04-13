#include <QApplication>
#include <QPushButton>
int main(int argc, char* argv[]) {
QApplication app(argc, argv);

// Q.1
QPushButton p_button("Quitter");
p_button.show();

// Q.4
/*
 * Tout objet de type QWidget (en particulier QPushbutton)
 *
 *
*/

QPushButton p_button2("coucou"); // Créer button dans fenêtre séparé
p_button2.show();

QPushButton p_button2_bis("coucou", &p_button); // Créer tout dans une seule fenêtre
p_button2_bis.show();
// Q.2
/*
 * La méthode show permet d'afficher le widget QPushButton.
 * Si on enlève show, rien ne s'affiche
 *
 * Show() est un slot : méthode ouvant être conecté à un signal
 * C'est une méthode qui hérite de la classe Qwidget
 *
*/

QObject::connect(&p_button, SIGNAL(clicked()), &app, SLOT(quit()));

/*
 * QObject::connect est une méthode statique
 * cliqcked() est un signal de la classe QPushButton héritée de
 * la classe abstraite QAbstractButton
 * quit() est un slot de l'application
 */



return app.exec();
}
