//
// Created by adamb on 2020-02-16.
//

#ifndef MYSNAKE_INTERFACE_H
#define MYSNAKE_INTERFACE_H

#include <iostream>
#include <ctime>
#include <conio.h>
#include <fstream>
#include <string>
#include <sstream>
#include "tableau.h"
#include "serpent.h"
#include "allDefines.h"


class interface {
    int ValueMin;
    int Score[10];
    bool quit;
public:
    interface();
    void init();
    void menu();
    void SortScore();
    void afficheScore();
    bool getQuit(){return quit;}

};


#endif //MYSNAKE_INTERFACE_H
