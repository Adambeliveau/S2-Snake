//
// Created by Marie-Eve Castonguay on 2020-02-13.
//

#include "tableau.h"
#include <iostream>

tableau::tableau() {
    taille = LONGUEUR;

    //Remplir matrice d'espaces vides
    for (int i=0;i<taille;i++){
        for (int j=0;j<taille;j++){
            tab[i][j] = ' ';
        }
    }

    //Mettre le cadre autour de la matrice
    for (int i =0;i<taille;i++){
        tab[i][0] = '|';
        tab[i][taille-1] = '|';
        tab[0][i] = '_';
        tab[taille-1][i] = '_';
    }
    /*tab[0][0] = char (201);
    tab[0][taille] = char (200);
    tab[taille][0] = char(187);
    tab[taille][taille] = char (188);*/
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
            std::cout<<" ";
        }
        std::cout<<std::endl;
    }
}
