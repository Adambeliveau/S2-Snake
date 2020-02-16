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
}

void tableau::randomFruit() {
    fruitX = rand() % (taille-1)+1;
    fruitY = rand() % (taille-1)+1;
    tab[fruitX][fruitY] = fruit;
    cout<<fruitX<<" "<<fruitY<<endl;
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

void tableau::draw() {
    for (int i =0;i<taille;i++){
        for (int j=0;j<taille;j++){

            if(i==0 || j==0 || i==(taille-1) || j==(taille-1)){
                tab[i][j] = '#';
            }
            if(i==serp.getX() && j==serp.getY()) {
                tab[i][j] = 'O';
            }
            if(i==fruitX && j==fruitY){
                tab[i][j] = '*';
            }
        }
    }
}

void tableau::input() {

}


/*
int tableau::getTaille() {
    return taille;
}
 int tableau::getFruitX() {
    return fruitX;
}

int tableau::getFruitY() {
    return fruitY;

}

 char tableau::getFruit() {
    return fruit;
}*/
