/**
 * Project Untitled
 */


#ifndef _NOTESMANAGER_H
#define _NOTESMANAGER_H

class NotesManager {
public: 
    Vector<Article*> articles;
    unsigned int nbArticles;
    unsigned int nbMaxArticles;
    string filename;
    void Port1;
    
    /**
     * @param id
     */
    void getNewArticle(const string & id);
    
    /**
     * @param id
     */
    Article & getArticle(const string & id);
    
    /**
     * @param a
     */
    void addArticle(Article* a);
    
    /**
     * @param f
     */
    void load(const string & f);
    
    void save();
};

#endif //_NOTESMANAGER_H