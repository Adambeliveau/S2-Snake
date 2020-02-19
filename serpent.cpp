//
// Created by Marie-Eve Castonguay on 2020-02-13.
//

#include "serpent.h"
#include <iostream>
#include <vector>
using namespace std;

serpent::serpent() //initialise le serpent
{
    taille = 5;

    coord coordonnee;
    coordonnee.x = LONGUEUR/2;//le fait commmencer au millieu
    coordonnee.y = LONGUEUR/2;//le fait commencer au millieu
    snake.push_back((coordonnee));//ajoute la coordonnee au vecteur
    for (int i = 0; i < taille; ++i)//ajoute le corps du serpent dans le vecteur vers la gauche de sa tete
    {
        coordonnee.x++;
        snake.push_back(coordonnee);
    }
}

int serpent::getTaille()//renvois la taille
{
    return taille;
}

void serpent::setcoord(vector<coord> x) // le vecteur de coordonne en parametre au vecteur de coordonne "snake"
{
    snake = x;
}

void serpent::setTaille(int d, coord c) //ajoute les nouvelles coordonnee du serpent au vecteur de coordonnee
{
    if(d == RIGHT)//d = direction
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





