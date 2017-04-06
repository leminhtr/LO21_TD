#include "Notes.h"
//_std = c++11;

void creation(){
	NotesManager & manager=NotesManager::getInstance();


	Article& a1=manager.getNewArticle("article_1");
	a1.setTitle("Avant Propos");
	a1.setText("Il faut toujours bien lire un sujet avant de commencer.");

	Article& a2=manager.getNewArticle("article_2");
	a2.setTitle("Objectifs");
	a2.setText("Comprendre la difference entre la composition et l'aggregation ainsi que les relations entre classes.");

	Article& a3=manager.getNewArticle("article_3");
	a3.setTitle("Objectifs");
	a3.setText("Apprendre comment implementer un design pattern.");


    NotesManager::libererInstance();


}

void affichage(){
	NotesManager &manager= NotesManager::getInstance();

	manager.load("tmp.dat");
	Article& a1=manager.getArticle("article_1");
	Article& a2=manager.getArticle("article_2");
	Article& a3=manager.getArticle("article_3");
	std::cout<<a1<<"\n";
	std::cout<<a2<<"\n";
	std::cout<<a3<<"\n";

    NotesManager::libererInstance();
}

int main() {
	try {
		creation(); // cette ligne peut �tre mise en commentaire apr�s la 1�re ex�cution
		affichage();
	}
	catch(NotesException& e){
		std::cout<<e.getInfo()<<"\n";
	}
	//system("pause");
	return 0;
}