//
// Created by Minh Tri on 23/03/2017.
//

#ifndef TD3_FRACTIONEXCEPTION_H
#define TD3_FRACTIONEXCEPTION_H


#include <cstring>

class FractionException{

    char info[256];


public:
    const char * getInfo() {return info;}

    FractionException(const char *msg) {

        strcpy(info, msg);

    }


};












#endif //TD3_FRACTIONEXCEPTION_H
