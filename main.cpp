#include <iostream>
#include "tableau.h"
#include "serpent.h"

using namespace std;

int main() {
    tableau tab;
    serpent serp;

    tab.draw();
    tab.afficherTableau();
    //system("clear"); // changer pour "cls" sur windows
    //tab.input();
    //tab.afficherTableau();
    //serp.afficherSerpent();

    return 0;
}
