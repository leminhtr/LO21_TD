/**
 * Project Untitled
 */


#ifndef _ARTICLE_H
#define _ARTICLE_H

class Article {
public: 
    string id;
    string title;
    string text;
    
    string const getId();
    
    string const getTitle();
    
    string const getText();
    
    /**
     * @param t
     */
    void setTitle(const string & t);
    
    /**
     * @param t
     */
    void setText(const string & t);
    
    /**
     * @param filename
     * @param title
     * @param text
     */
    void Article(const string & filename, const string & title, const string & text);
};

#endif //_ARTICLE_H