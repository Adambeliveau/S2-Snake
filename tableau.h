//
// Created by Marie-Eve Castonguay on 2020-02-13.
//

#ifndef MYSNAKE_TABLEAU_H
#define MYSNAKE_TABLEAU_H

#include "allDefines.h"
#include "serpent.h"

class tableau {
private:
    char tab[LONGUEUR][LONGUEUR];
    char fruit;
    int taille;
    int fruitX, fruitY;
    serpent serp;

public:
    tableau();
    int getTaille();

    void randomFruit();
    char getFruit();
    int getFruitX();
    int getFruitY();

    void putFruit();
    void afficherTableau();
};


#endif //MYSNAKE_TABLEAU_H
