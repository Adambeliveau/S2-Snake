//
// Created by Marie-Eve Castonguay on 2020-02-13.
//

#include "serpent.h"
#include <iostream>
#include <vector>
using namespace std;

serpent::serpent() {
    taille = 3;
    snake.push_back('o');
    snake.push_back('~');
    snake.push_back('~');
    x = LONGUEUR/2;
    y = LONGUEUR/2;
}

int serpent::getX() {
    return x;
}

int serpent::getY() {
    return y;
}

int serpent::getTaille() {
    return taille;
}

void serpent::allonger() {
    snake.push_back('~');
}

void serpent::afficherSerpent() {

    for (int i = 0; i<snake.size();++i){
        cout<<snake.at(i)<<" ";
    }
    cout<<endl;
}
