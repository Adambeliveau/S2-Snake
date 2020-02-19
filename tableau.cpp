//
// Created by Marie-Eve Castonguay on 2020-02-13.
//

#include "tableau.h"
#include <iostream>
#include <conio.h>
using namespace std;

tableau::tableau() //initialise le tableau
{
    gameOver = false;
    dir = 2;//direction vers la gauche
    point = 0;
    taille = LONGUEUR;
    randomFruit();

    for (int i=0;i<taille;i++)//Remplir tableau d'espaces blancs
    {
        for (int j=0;j<taille;j++){
            tab[i][j] = ' ';
        }
    }
}

void tableau::randomFruit() //randomise l'emplacement du fruit
{
    fruitX = 1 + (rand() * (int)(taille - 1 - 1) / RAND_MAX);
    fruitY = 1 + (rand() * (int)(taille - 1 - 1) / RAND_MAX);
}

void tableau::afficherTableau()//affiche le tableau
{
    system("cls");
    for (int i=0;i<taille;i++){
        for (int j=0;j<taille;j++){
            cout<<tab[i][j];
            cout<<" ";//rajoute un espace pour rendre la tableau carré
        }
        cout<<endl;
    }
}

void tableau::draw(serpent last)//rempli le tableau avant de l'afficher
{
    for (int i = 0; i < taille; i++) {
        for (int j = 0; j < taille; j++) {
            if (i == 0 || j == 0 || i == (taille - 1) || j == (taille - 1)) {
                if (j == LONGUEUR/2 + 1||j == LONGUEUR/2 - 2)//met un espace avant et après d'afficher le score
                {
                    tab[i][j]= ' ';
                }
                else if(j == LONGUEUR/2 - 1)//met la deuxieme décimal des point de la partie dans la bordure du haut et du bas
                {
                    pos = 2;
                    tab[i][j] = intToChar();
                }
                else if(j == LONGUEUR/2) //met la premiere décimal des point de la partie dans la bordure du haut et du bas
                {
                    pos = 1;
                    tab[i][j] = intToChar();
                }
                else//rempli le reste de la bordure avec des #
                    tab[i][j] = '#';
            }
            for (int k = 0; k < serp.getTaille(); ++k) // delete et rempli le taleau avec les coordonnee du dernier et du nouveau serpent
            {
                if (serp.getCoord().at(0).x == j && serp.getCoord().at(0).y == i) //met la tete du serpent dans le tableau
                {
                    tab[i][j] = 'O';
                }
                else if(serp.getCoord().at(k).x == j && serp.getCoord().at(k).y == i)//met la corps du serpent dans le tableau
                {
                    tab[i][j] = 'o';
                }
                else if (last.getCoord().at(0).x == j && last.getCoord().at(0).y == i) //ou il y avait la tete avant, il met un parti du corps
                {
                    tab[i][j] = 'o';
                }
                else if(last.getCoord().at(k).x == j && last.getCoord().at(k).y == i)//ou il y avait un corps, il met un vide
                {
                    tab[i][j] = ' ';
                }

            }
            if (i == fruitY && j == fruitX)//met le fruit dans le tableau au coordonnee du fruit
            {
                tab[i][j] = '*';
            }
        }
    }
}

void tableau::input() //les different input au clavier durant une game
{
if(_kbhit())//regarde dans le buffer du clavier síl y a eu un entrée
    switch (_getch())//va prendre l'entrée du clavier
    {
        case 'a': if(dir==0?dir = 3:dir--);//dir = direction (regarde les define pour savoir quelle chiffre équivaut à quelle direction)
            break;
        case 'd': if(dir==3?dir = 0:dir++);//dir = direction (regarde les define pour savoir quelle chiffre équivaut à quelle direction)
            break;
        case 'x': gameOver = true;//quitte le jeu en cour
            break;
    }

}

void tableau::detection()//detection du serpent avec divers objet
{
    //detection du fruit
    if(serp.getCoord().at(0).x == fruitX && serp.getCoord().at(0).y == fruitY)
    {
        coord c;
        c.x = serp.getCoord().end()->x;//ajoute à la struct la derniere coordonnee en x du serpent
        c.y = serp.getCoord().end()->y;//ajoute à la struct la derniere coordonnee en x du serpent
        serp.setTaille(dir,c);//voir la definition de setTaille
        randomFruit();//fontion qui ajoute un autre fruit
        point += 1;//incremente le pointage total
    }
    //detection du serpent
    for (int i = 0; i < serp.getTaille(); ++i) {
        for (int j = 0; j < serp.getTaille(); ++j) {
            if(i != j)//ne rentre pas si il est dans le meme indice du vecteur
            {
                if(serp.getCoord().at(i).x == serp.getCoord().at(j).x && serp.getCoord().at(i).y == serp.getCoord().at(j).y )//regarde si le serpent à les meme coordonne dans deux indice different du vecteur
                {
                    gameOver = true;//termine la game
                }
            }

        }
    }
    //detection des murs
    if(serp.getCoord().at(0).x == 0 || serp.getCoord().at(0).x == LONGUEUR-1 || serp.getCoord().at(0).y == 0 || serp.getCoord().at(0).y == LONGUEUR-1)//regarde si le serpent n'a pas les meme coordonnee que les murs
    {
        gameOver = true;//termine la game
    }


}

char tableau::intToChar() //change les point en char pour les afficher dans le tableau
{
   char *ptr_c = new char[1];
    int a;

    if(pos == 1)//la premiere décimal d'un chiffre ex: 17-> 7
   {
        a = point%10;//prend seulement la premiere decimal
        itoa(a,ptr_c,10);//change cette décimal en char
   }
    else if (pos == 2)//la deuxieme décimal d'un chiffre ex: 17-> 1
    {
        a = (point-point%10)/10;//prend seulement la deuxieme décimal en soustraiyant la premiere et ensuite le divise par dix pour enleve le 0 ex: 17-7 -> 10/10 -> 1
        itoa(a,ptr_c,10);//change cette décimal en char
    }
    char c = ptr_c[0];//change le tableau de char en un caractere char
    return c;
}


