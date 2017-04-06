


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
    Article & operator=(const Article & a);

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

    class Iterator{
        /*
         *  on appelle next à chaque itération sur currentA
         *  it.current pointe sur un élément de currentA (référence vers l'article courant)
         */
        friend class NotesManager;

        Article **currentA; //tableau de pointeur
        unsigned int nbRestant;

        Iterator(Article **a, unsigned int nr): currentA(a),nbRestant(nr){}

    public:
        Iterator(): currentA(nullptr),nbRestant(0){}

        bool isDone() const{    //renvoie vraie si nbRestant=0 <=> fin tu tableau
            return nbRestant==0;
        }

        void next(){
            if(isDone()){
                throw  NotesException("Error : next on Iterator already done");
            }
            else {
                currentA++;
                nbRestant--;
            }
        }

        Article &current() const{   //écriture possible
            if(isDone()){
                throw NotesException("Error : current on Iterator already done !");
            }
            else{
                return **currentA;
            }
        }
    };
        const Iterator getIterator() {
        return Iterator(articles, nbArticles);  //Iterator est un constructeur privé de NotesManager::Iterator : problème d'accès
        // Sol. -> on déclare NotesManager comme friend class de Iterator
        }

    class ConstIterator{
        /*
         *  on appelle next à chaque itération sur currentA
         *  it.current pointe sur un élément de currentA (référence vers l'article courant)
         */


        friend class NotesManager;

        Article **currentA; //tableau de pointeur
        unsigned int nbRestant;

        ConstIterator(Article **a, unsigned int nr): currentA(a),nbRestant(nr){}

    public:
        ConstIterator(): currentA(nullptr),nbRestant(0){}

        bool isDone() const{    //renvoie vraie si nbRestant=0 <=> fin tu tableau
            return nbRestant==0;
        }

        void next(){
            if(isDone()){
                throw  NotesException("Error : next on Iterator already done");
            }
            else {
                currentA++;
                nbRestant--;
            }
        }

        const Article &current() const{ // en lecture seulement
            if(isDone()){
                throw NotesException("Error : current on Iterator already done !");
            }
            else{
                return **currentA;
            }
        }
    };

    ConstIterator getIterator() const{
        return ConstIterator(articles, nbArticles);  //Iterator est un constructeur privé de NotesManager::Iterator : problème d'accès
        // Sol. -> on déclare NotesManager comme friend class de Iterator
    }

    class iterator{
        Article **current;
        iterator(Article **a):current(a){}

        friend class NotesManager;
    public:
        iterator():current(nullptr){}

        Article &operator*(){
            return **current;
        }

        iterator &operator++(){
            ++current;
            return *this;
        }

        bool operator!=(iterator it) const{
            return current != it.current;
        }

    };

    iterator begin(){   //1ère case du tableau articles
        return iterator(articles);
    }
    iterator end(){ //case juste après la dernière case du tableau articles (condition boucle for : !=m.end
        return iterator(articles + nbArticles);
    }

    class const_iterator{
        Article **current;
        const_iterator(Article **a):current(a){}

        friend class NotesManager;
    public:
        const_iterator():current(nullptr){}

        const Article &operator*() const {
            return **current;
        }

        const_iterator &operator++(){
            ++current;
            return *this;
        }

        bool operator!=(const_iterator it) const{
            return current != it.current;
        }

    };

    const_iterator begin() const{   //1ère case du tableau articles
        return const_iterator(articles);
    }
    const_iterator end() const{ //case juste après la dernière case du tableau articles (condition boucle for : !=m.end
        return const_iterator(articles + nbArticles);
    }


    class SearchIterator{
        friend class NotesManager;
        Article ** currentA;
        unsigned int nbRemain;
        string tofind;

        // Constructeur privé
        SearchIterator(Article **a, unsigned int nb, const std::string &tf):
            currentA(a), nbRemain(nb),tofind(tf){   //initialise

            //méthode find pour accéder à la position de la 1ère sous chaine de caractère 'tofind'
            while (nbRemain >0 && (*currentA)->getText().find(tofind)==std::string::npos){
                nbRemain--;
                currentA++;
            }
        }

    public:
        SearchIterator():currentA(nullptr), nbRemain(0), tofind("")/*initialisation tofind optionel*/{}

        bool isDone() const {return nbRemain==0;};

        void next () {
            if(isDone()){
                throw NotesException ("Error : next on iterator which is done");
            }
            else
            {
                nbRemain--;
                currentA++;
                while (nbRemain >0 && (*currentA)->getText().find(tofind)==std::string::npos){
                    nbRemain--;
                    currentA++;
                }
            }
        }

        Article& current() const{
            if(isDone())
                throw NotesException("Error : indirection on iterator which is done !");
            else
            {
                return **currentA; //renvoie référence vers article courant
            }
        }

    };

    SearchIterator getSearchIterator(const std::string &tf) const{
        return SearchIterator(articles, nbArticles, tf);
    }

    static NotesManager& getInstance();
    static void libererInstance();


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