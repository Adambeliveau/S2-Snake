//
// Created by Marie-Eve Castonguay on 2020-02-13.
//

#include "tableau.h"
#include <iostream>

tableau::tableau() {
    taille = LONGUEUR;
    for (int i=0; i<taille;i++){
        tab[i][0] = '_';
        tab[i][taille-1] = '_';

        tab[0][i] = '|';
        tab[taille-1][i] = '|';
    }


}

int tableau::getTaille() {
    return taille;
}

void tableau::setTaille(int t) {
    taille = t;
}

void tableau::afficherTableau() {

    for (int i=0;i<taille;i++){
        for (int j=0;j<taille;j++){
            std::cout<<tab[i][j];
        }
        std::cout<<std::endl;
    }
}
