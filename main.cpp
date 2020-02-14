#include <iostream>
#include "tableau.h"
#include "serpent.h"

using namespace std;

int main() {
    tableau tab;
    serpent serp;

    tab.afficherTableau();
    serp.afficherSerpent();

    cout << "Hello, World!" << endl;
    return 0;
}
