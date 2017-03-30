//
// Created by Minh Tri on 30/03/2017.
//

#include "notes.h"
#include <iostream>

ostream & operator<<(ostream &f, const Article &a){ //il faut que l'opérateur << renvoie un ostream 'f'

    f << a.getId() <<endl;
    f << a.getTitle() <<endl;
    f << a.getText() <<endl;
    return f;

}

//f <<a.getText() << endl;
// (f <<a.getText()) << endl;



















