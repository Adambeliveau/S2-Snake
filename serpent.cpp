//
// Created by Marie-Eve Castonguay on 2020-02-13.
//

#include "serpent.h"
#include <iostream>
#include <vector>
using namespace std;

serpent::serpent() {
    taille = 5;

    coord coordonnee;
    coordonnee.x = LONGUEUR/2;
    coordonnee.y = LONGUEUR/2;
    snake.push_back((coordonnee));
    for (int i = 0; i < taille; ++i) {
        coordonnee.x++;
        snake.push_back(coordonnee);
    }
}





int serpent::getTaille() {
    return taille;
}

void serpent::setcoord(vector<coord> x) {
    snake = x;
}

void serpent::setTaille(int d, coord c) {
    if(d == RIGHT)
    {
        c.x++;
        snake.push_back(c);
    }
    if(d == LEFT) {
        c.x--;
        snake.push_back(c);
    }
    if(d == UP) {
        c.y++;
        snake.push_back(c);
    }
    if(d == DOWN) {
        c.y--;
        snake.push_back(c);
    }
    taille++;

}





