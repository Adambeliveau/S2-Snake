//
// Created by Marie-Eve Castonguay on 2020-02-13.
//

#include "tableau.h"

#include <iostream>
using namespace std;

tableau::tableau() {
    taille = LONGUEUR;
    fruit = '*';
    randomFruit();

    //Remplir tableau d'espaces blancs
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
}

int tableau::getTaille() {
    return taille;
}

void tableau::randomFruit() {
    fruitX = rand() % (taille-1) + 1;
    fruitY = rand() % (taille-1) + 1;
    cout<<fruitX<<" "<<fruitY<<endl;
}

int tableau::getFruitX() {
    return fruitX;
}

int tableau::getFruitY() {
    return fruitY;
}

void tableau::afficherTableau() {

    for (int i=0;i<taille;i++){
        for (int j=0;j<taille;j++){
            cout<<tab[i][j];
            cout<<" ";
        }
        cout<<endl;
    }
}

char tableau::getFruit() {
    return fruit;
}

void tableau::putFruit() {
    tab[fruitX][fruitY] = fruit;
}

