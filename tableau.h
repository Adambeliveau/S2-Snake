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
    void randomFruit();
    void draw();
    void input();
    void afficherTableau();

    //char getFruit();
    //int getFruitX();
    //int getFruitY();
    //int getTaille();
};


#endif //MYSNAKE_TABLEAU_H
