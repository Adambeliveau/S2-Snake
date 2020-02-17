//
// Created by Marie-Eve Castonguay on 2020-02-13.
//

#include "tableau.h"
#include <iostream>
#include <conio.h>
using namespace std;

tableau::tableau() {
    gameOver = false;
    dir = 2;
    point = 0;


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

    fruitX = 1 + (rand() * (int)(taille - 1 - 1) / RAND_MAX);
    fruitY = 1 + (rand() * (int)(taille - 1 - 1) / RAND_MAX);

}

void tableau::afficherTableau() {
    system("cls");
    for (int i=0;i<taille;i++){
        for (int j=0;j<taille;j++){
            cout<<tab[i][j];
            cout<<" ";
        }
        cout<<endl;
    }

}

void tableau::draw(serpent last) {

    for (int i = 0; i < taille; i++) {
        for (int j = 0; j < taille; j++) {


            if (i == 0 || j == 0 || i == (taille - 1) || j == (taille - 1)) {
                if (j == LONGUEUR/2 + 1||j == LONGUEUR/2 - 2)
                {
                    tab[i][j]= ' ';
                }
                else if(j == LONGUEUR/2 - 1)
                {
                    pos = 2;
                    tab[i][j] = intToChar();
                }
                else if(j == LONGUEUR/2) {
                    pos = 1;
                    tab[i][j] = intToChar();
                }
                else
                    tab[i][j] = '#';
            }
            for (int k = 0; k < serp.getTaille(); ++k) {
                if (last.getCoord().at(0).x == j && last.getCoord().at(0).y == i) {
                    tab[i][j] = 'o';
                }
                else if(last.getCoord().at(k).x == j && last.getCoord().at(k).y == i){
                    tab[i][j] = ' ';
                }
                else if (serp.getCoord().at(0).x == j && serp.getCoord().at(0).y == i) {
                    tab[i][j] = 'O';
                }
                else if(serp.getCoord().at(k).x == j && serp.getCoord().at(k).y == i){
                    tab[i][j] = 'o';
                }
            }

            if (i == fruitY && j == fruitX) {
                tab[i][j] = '*';
            }



        }

    }
    cout << serp.getCoord().at(0).x <<"|"<<fruitX<<"|"<<serp.getCoord().at(0).y<<"|"<<fruitY<<endl;

}

void tableau::input() {
if(_kbhit())
    switch (_getch())
    {
        case 'a': if(dir==0?dir = 3:dir--);
            break;
        case 'd': if(dir==3?dir = 0:dir++);
            break;
        case 'x': gameOver = true;
            break;
    }

}

void tableau::detection() {
    if(serp.getCoord().at(0).x == fruitX && serp.getCoord().at(0).y == fruitY)
    {
        coord c;
        c.x = serp.getCoord().end()->x;
        c.y = serp.getCoord().end()->y;
        serp.setTaille(dir,c);
        randomFruit();
        point += 1;
    }
    for (int i = 0; i < serp.getTaille(); ++i) {
        for (int j = 0; j < serp.getTaille(); ++j) {
            if(i != j)
            {
                if(serp.getCoord().at(i).x == serp.getCoord().at(j).x && serp.getCoord().at(i).y == serp.getCoord().at(j).y )
                {
                    gameOver = true;
                }
            }

        }
    }
    if(serp.getCoord().at(0).x == 0 || serp.getCoord().at(0).x == LONGUEUR || serp.getCoord().at(0).y == 0 || serp.getCoord().at(0).y == LONGUEUR-1){
        gameOver = true;
    }


}

char tableau::intToChar() {
   char *ptr_c = new char[1];
    int a;

    if(pos == 1)
   {
        a = point%10;
        itoa(a,ptr_c,10);
   }
    else if (pos == 2)
    {
        a = (point-point%10)/10;
        itoa(a,ptr_c,10);
    }
    char c = ptr_c[0];
    cout << c<< endl;
    cout << point<<endl;
    return c;
}


