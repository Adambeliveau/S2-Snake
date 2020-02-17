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
    bool gameOver;
    int dir;
    int point;
    int pos;




public:
    tableau();
    void randomFruit();
    void draw(serpent last);
    void input();
    void afficherTableau();
    bool getgameOver(){return gameOver;}
    void setSerpent(serpent SErpp){ serp = SErpp;}
    serpent getSerpent(){return serp;}
    int getDir(){return dir;}
    void detection();
    char intToChar();
    int getPoint(){return point;}

};


#endif //MYSNAKE_TABLEAU_H
