//
// Created by Marie-Eve Castonguay on 2020-02-13.
//

#ifndef MYSNAKE_INTERFACE_H
#define MYSNAKE_INTERFACE_H
#include "allDefines.h"
#include "serpent.h"
#include "tableau.h"

class interface {
private:
    tableau tab;
    Direction moving;

    bool gameOver;

public:
    interface();


};


#endif //MYSNAKE_INTERFACE_H
