//
// Created by adamb on 2020-02-16.
//

#include "interface.h"

void interface::init() {
    clock_t start = clock();
    tableau tab;
    serpent serp;

    int direction;
    vector<coord> coordonnee;



    int n = 1;

    do{

        if(((clock()-start)/(double)CLOCKS_PER_SEC) >= SPEED*n)
        {
            n++;
            serp = tab.getSerpent();

            tab.input();
            direction = tab.getDir();

            serpent lastSerp = serp;

            if(direction == RIGHT)
            {
                coordonnee = serp.getCoord();
                for (int i = 0; i <= serp.getTaille(); ++i) {
                    if (i == 0)
                        coordonnee.at(i).x++;
                    else
                        coordonnee.at(i) = serp.getCoord().at(i-1);
                }
                serp.setcoord(coordonnee);
            }
            if(direction == LEFT)
            {
                coordonnee = serp.getCoord();
                for (int i = 0; i <= serp.getTaille(); ++i) {
                    if (i == 0)
                        coordonnee.at(i).x--;
                    else
                        coordonnee.at(i) = serp.getCoord().at(i-1);
                }
                serp.setcoord(coordonnee);
            }
            if(direction == UP)
            {
                coordonnee = serp.getCoord();
                for (int i = 0; i <= serp.getTaille(); ++i) {
                    if (i == 0)
                        coordonnee.at(i).y++;
                    else
                        coordonnee.at(i) = serp.getCoord().at(i-1);
                }
                serp.setcoord(coordonnee);
            }
            if(direction == DOWN)
            {
                coordonnee = serp.getCoord();
                for (int i = 0; i <= serp.getTaille(); ++i) {
                    if (i == 0)
                        coordonnee.at(i).y--;
                    else
                        coordonnee.at(i) = serp.getCoord().at(i-1);
                }
                serp.setcoord(coordonnee);
            }

            tab.setSerpent(serp);
            tab.detection();
            tab.draw(lastSerp);
            tab.afficherTableau();

        }
    }while(!tab.getgameOver());


    if(tab.getgameOver()) {
        system("cls");
        cout << "\n\n\n\n\n*************************************VOTRE SCORE :" << tab.getPoint()
             << "********************************************\n";
        cout << "__________      ___     ___  ___  __________  __________  __         __  __________  __________\n"
             << "|  ____  |     /  \\     |  \\/  |  |  ______|  |   ___  |  \\ \\       / /  |  ______| |   ___   |\n"
             << "| |    |_|    / /\\ \\    | |\\/| |  | |______   |  |   | |   \\ \\     / /   | |______  |  |___|  |\n"
             << "| |  _____   / /__\\ \\   | |  | |  |  ______|  |  |   | |    \\ \\   / /    |  ______| |  ____  / \n"
             << "| |____| |  /  _____ \\  | |  | |  | |______   |  |___| |     \\ \\ / /     | |______  |  |   \\ \\ \n"
             << "|________| / /      \\ \\ | |  | |  |________|  |________|      \\___/      |________| |__|    \\_\\ \n";
    }
}

interface::interface() {

}



