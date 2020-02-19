#include "interface.h"

using namespace std;

int main() {

    system("cls");
    interface Interface;
    while(!Interface.getQuit())
        Interface.menu();

    return 0;
}
