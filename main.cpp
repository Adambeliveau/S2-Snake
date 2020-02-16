#include <iostream>
#include <ctime>
#include "tableau.h"
#include "serpent.h"

using namespace std;

int main() {

    clock_t start = clock();
    tableau tab;
    serpent serp;

    tab.draw();
    do{
        if(((clock()-start)/CLOCKS_PER_SEC)%1 == 0)
        {
            tab.afficherTableau();
            system("CLS");
        }
    }while(tab.getgameOver() == false);


    //tab.input();
    //tab.afficherTableau();
    system("pause");
    //serp.afficherSerpent();

    return 0;
}
