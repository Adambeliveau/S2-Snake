#include "interface.h"

using namespace std;

int main() {

    system("cls");
    interface Interface;
    while(!Interface.getQuit())//affiche le menu tant que quit est faux
        Interface.menu();

    return 0;
}
