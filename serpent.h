//
// Created by Marie-Eve Castonguay on 2020-02-13.
//

#ifndef MYSNAKE_SERPENT_H
#define MYSNAKE_SERPENT_H
#include "allDefines.h"
#include <vector>
#include "coord.h"


using namespace std;

class serpent {
private:
    vector <coord> snake;
    int taille;


public:
    serpent();
    int getTaille();
    void setcoord(vector<coord> x);
    vector<coord> getCoord(){return snake;}
    void setTaille(int d,coord c);
};


#endif //MYSNAKE_SERPENT_H
