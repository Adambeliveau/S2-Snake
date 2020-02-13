//
// Created by Marie-Eve Castonguay on 2020-02-13.
//

#ifndef MYSNAKE_TABLEAU_H
#define MYSNAKE_TABLEAU_H
#define LONGUEUR 20

class tableau {
private:
    char tab[LONGUEUR][LONGUEUR];
    int taille;

public:
    tableau();
    int getTaille();
    void setTaille(int t);
    void afficherTableau();
};


#endif //MYSNAKE_TABLEAU_H
