#if !defined(_NOTES_H)
#define _NOTES_H

#include <string>
#include <iostream>
using namespace std;

class Article;
class Tag;
class NotesManager;
class TagsManager;

class NotesException{
public:
    NotesException(const string& message):info(message){}
    string getInfo() const { return info; }
private:
    string info;
};

class Article {
    string id;
    string title;
    string text;

    Article(const Article &);
    Article::operator=(const Article & a);

public:
    Article(const string& i, const string& ti, const string& te);
    string getId() const { return id; }
    string getTitle() const { return title; }
    string getText() const { return text; }
    void setTitle(const string& t);
    void setText(const string& t);
};

class NotesManager {
private:
    Article** articles;
    unsigned int nbArticles;
    unsigned int nbMaxArticles;
    void addArticle(Article* a);
    string filename;


    NotesManager();
    ~NotesManager();
    NotesManager(const NotesManager& m);
    NotesManager& operator=(const NotesManager& m);

    //élément instance ajouté.
    static NotesManager * instance; //déclaration
    // static lié à objet pas à la classe : durée de vie

public:

//    static NotesManager& getInstance(){ //méthode qui vérifie qu'il n'y ait qu'une seule instance de NotesManager
//        if(instance==nullptr)   // si l'instance n'existe pas
//            instance = new NotesManager;    // on crée une instance
//        return *instance;
//
//    }
    static NotesManager& getInstance();
    static void libererInstance();

//    static void libererInstance(){
//        if(instance != nullptr) // si l'instance existe
//            delete instance;    // on la supprime
//        instance=nullptr;   // réinitialisation à nullptr
//
//
//    }


    Article& getNewArticle(const string& id);
    Article& getArticle(const string& id);
    void load(const string& f);
    void save() const;
};

class Tag {
    string name;
    const Article* article;
public:
    Tag(const string& n, const Article& a):name(n),article(&a){}
    const string& getName() const { return name; }
    const Article& getArticle() const { return *article; }
};

class TagsManager {
private:
    Tag** tags;
    unsigned int nbTags;
    unsigned int nbMaxTags;
    void addTag(Tag* a);
public:
    TagsManager();
    ~TagsManager();
    void addTag(const string& t, const Article& a);
    void removeTag(const string& t, const Article& a);
};

ostream& operator<<(ostream& f, const Article& a);
ostream& operator<<(ostream& f, const Tag& t);
#endif