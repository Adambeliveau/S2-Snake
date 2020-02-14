//
// Created by Marie-Eve Castonguay on 2020-02-13.
//

#ifndef MYSNAKE_SERPENT_H
#define MYSNAKE_SERPENT_H
#include "allDefines.h"
#include <vector>

using namespace std;

class serpent {
private:
    vector <char> snake;
    int x;
    int y;
    int taille;

public:
    serpent();
    int getX();
    int getY();
    int getTaille();
    void allonger();
    void afficherSerpent();
};


#endif //MYSNAKE_SERPENT_H
