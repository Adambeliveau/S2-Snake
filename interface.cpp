//
// Created by adamb on 2020-02-16.
//

#include "interface.h"

void interface::init() // jeux snake
{
    clock_t start = clock();//avoir une interval de temp pour refresh le tableau(faire bouger le serpent)
    tableau tab;
    serpent serp;

    int direction;
    vector<coord> coordonnee;



    int n = 1;//nombre de fois que le tableau à refresh

    do{

        if(((clock()-start)/(double)CLOCKS_PER_SEC) >= SPEED*n)//refresh à chaque interval de Speed(en seconde)
        {
            n++;
            serp = tab.getSerpent();

            tab.input();//regarde l'input pour savoir la prochaine direction
            direction = tab.getDir();//va chercher la direction actuelle

            serpent lastSerp = serp;//garde en memoire le dernier serpent pour savoir sa position

            if(direction == RIGHT)//si la direction est vers la droite bouge le serpent vers la droite
            {
                coordonnee = serp.getCoord();//va chercher la position du serpent
                for (int i = 0; i <= serp.getTaille(); ++i)
                {
                    if (i == 0)//bouge la tete seulement
                        coordonnee.at(i).x++;
                    else//bouge le reste du corps selon la dernier coordonnee dans la position du vecteur avant la parti du corps qu'il bouge
                        coordonnee.at(i) = serp.getCoord().at(i-1);
                }
                serp.setcoord(coordonnee);
            }
            if(direction == LEFT)//si la direction est vers la droite bouge le serpent vers la gauche
            {
                coordonnee = serp.getCoord();//va chercher la position du serpent
                for (int i = 0; i <= serp.getTaille(); ++i)
                {
                    if (i == 0)//bouge la tete seulement
                        coordonnee.at(i).x--;
                    else//bouge le reste du corps selon la dernier coordonnee dans la position du vecteur avant la parti du corps qu'il bouge
                        coordonnee.at(i) = serp.getCoord().at(i-1);
                }
                serp.setcoord(coordonnee);
            }
            if(direction == UP)//si la direction est vers la droite bouge le serpent vers le bas
            {
                coordonnee = serp.getCoord();//va chercher la position du serpent
                for (int i = 0; i <= serp.getTaille(); ++i) {
                    if (i == 0)//bouge la tete seulement
                        coordonnee.at(i).y++;
                    else//bouge le reste du corps selon la dernier coordonnee dans la position du vecteur avant la parti du corps qu'il bouge
                        coordonnee.at(i) = serp.getCoord().at(i-1);
                }
                serp.setcoord(coordonnee);
            }
            if(direction == DOWN)//si la direction est vers la droite bouge le serpent vers le haut
            {
                coordonnee = serp.getCoord();
                for (int i = 0; i <= serp.getTaille(); ++i) {
                    if (i == 0)//bouge la tete seulement
                        coordonnee.at(i).y--;
                    else//bouge le reste du corps selon la dernier coordonnee dans la position du vecteur avant la parti du corps qu'il bouge
                        coordonnee.at(i) = serp.getCoord().at(i-1);
                }
                serp.setcoord(coordonnee);
            }

            tab.setSerpent(serp);//change les coordonne du serpent avec les nouvelles
            tab.detection();//regarde si le serpent touche à un objet
            tab.draw(lastSerp);//rempli le tableau et efface le dernier serpent (c'est pour sa qu'il est passé en parametre
            tab.afficherTableau();//affiche le tableau


        }
    }while(!tab.getgameOver());//le fait tant que gameOver est faux


    if(tab.getgameOver()) //si gameOver est vrai
    {
        bool isDejaRemplace = false;//pour pas remplacer plein de fois la valeur la plus basse si il y en a plusieur ex: dans la .txt les trois pires highscore son 2
        system("cls");
        fstream file;
        SortScore();//place en ordre le tableau
        file.open("highscore.txt",ios::out);
        if(!file)
        {
            cout<<"highscore.txt est indisponible"<<endl;
        } else{
            for (int j = 0; j < 10; ++j) {

                if(Score[j] == ValueMin && isDejaRemplace == false)//si la valeur de score est la plus petite il va la remplacer avec la nouveau highscore
                {
                    isDejaRemplace = true;
                    if(tab.getPoint()>ValueMin)//si le nouveau highscore est plus petit, il laisse la valeur minimal precedente
                        Score[j] = tab.getPoint();
                }

                if(j == 9)//ajoute un point virgule à la fin du fichier .txt
                    file<<Score[j]<<";";
                else//met des virgule en chaque score dans le .txt
                    file<<Score[j]<<",";
            }
        }
        file.close();
        cout << "\n\n\n\n\n*************************************VOTRE SCORE :" << tab.getPoint()
             << "********************************************\n";
        cout << "__________      ___     ___  ___  __________  _________  __         __  __________  __________\n"
             << "|  ____  |     /  \\     |  \\/  |  |  ______|  |  ___  |  \\ \\       / /  |  ______| |   ___   |\n"
             << "| |    |_|    / /\\ \\    | |\\/| |  | |______   | |   | |   \\ \\     / /   | |______  |  |___|  |\n"
             << "| |  _____   / /__\\ \\   | |  | |  |  ______|  | |   | |    \\ \\   / /    |  ______| |  ____  / \n"
             << "| |____| |  /  _____ \\  | |  | |  | |______   | |___| |     \\ \\ / /     | |______  |  |   \\ \\ \n"
             << "|________| / /      \\ \\ | |  | |  |________|  |_______|      \\___/      |________| |__|    \\_\\ \n";
    }
}

interface::interface()//initialise l'interface
{
    for (int i = 0; i < 10; ++i) //rempli le tableau de 0
    {
        Score[i] = 0;
    }
    quit = false;
}

void interface::menu() // menu pour les differentes fonctionnalité
{
    int choix;

    do{
        cout<<"*****************************"<<endl;
        cout<<"\nQue voulez-vous faire?"<<endl;
        cout<<"\tjouer(1)"<<endl;
        cout<<"\tMeilleure score(2)"<<endl;
        cout<<"\tQuitter(3)"<<endl;
        cin>>choix;
    }while(choix>3||choix<1);
    switch(choix)
    {
        case 1: init();
        break;
        case 2:SortScore();
            afficheScore();
        break;
        case 3:quit = true;
        break;
    }
}

void interface::SortScore() // trier les score en ordre
{
    fstream file;
    string temp;

    file.open("highscore.txt",ios::in);//ouvre le fichier .txt pour avoir les higscore precedent
    if(!file){
        cout<<"highscore.txt n'est pas disponible"<<endl;
    } else{
        getline(file,temp,';');//prend tout le fichier .txt jusqu'a la fin (un point virgule)
    }

    int cpt = 0;//valeur incrementer à chaque inserton dans le tableau de score
    for (int i = 0; i < temp.length(); ++i) {
        if(temp.at(i) != ',')// si n'est pas une virgule -> est un chiffre
        {
            Score[cpt] = stoi(temp.substr(i), nullptr,10);//prend le chiffre
            cpt++;
            if(i<temp.length()-1)//si le chiffre à deux décimal, il incremente i de un pour pas qu'il reprenne le meme chiffre apres
            {
                if (temp.at(i+1) != ',')
                {
                    i++;
                }
            }
            if(i<temp.length()-2)//si le chiffre à trois décimal, il incremente i de deux pour pas qu'il reprenne le meme chiffre apres
            {
                if (temp.at(i+1) != ',')
                {
                    i++;
                }
            }

        }
    }
    int max = -1;//initialise max à -1 pour pas que quand le tableau soit remplit de 0 il y ai une erreur d'index_out_of_bound
    int indmax;//indince à laquelle la valeur mac à ete trouver
    int ScoreTemp [10];//tableaupour stocker temporairement le score
    for (int k = 0; k < 10 ; ++k)//boucle pour trier les score en ordre de grosseur
    {
        for (int j = 0; j < 10; ++j) {
            if(Score[j] > max)//si le score est plus gros que max max devient le score
            {
                max = Score[j];
                indmax = j;
            }
        }
        ScoreTemp[k] = Score[indmax];//met le socre en ordre dans le tableau temporaire
        Score[indmax] = 0;
        max = 0;
    }
    for (int l = 0; l < 10; ++l) //remettre le tableau temporaire dans le vrai tableau
    {

        Score[l] = ScoreTemp[l];
    }
    ValueMin = Score[9];//savoir quelle valeur est la plus petite pour pouvoir la rmeplacer plus tard si on fait un meilleure score
}

void interface::afficheScore() // affiche les scores
{
    system("cls");
    cout<<"\tMeilleure Score : "<<endl;
    for (int k = 0; k < 10; ++k) {
        cout << "player #"<<k+1<<" : "<<Score[k]<<endl;
    }
}



