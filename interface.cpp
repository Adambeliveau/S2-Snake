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
        bool isDejaRemplace = false;
        system("cls");
        fstream file;
        SortScore();
        file.open("highscore.txt",ios::out);
        if(!file)
        {
            cout<<"highscore.txt est indisponible"<<endl;
        } else{
            for (int j = 0; j < 10; ++j) {

                if(Score[j] == ValueMin && isDejaRemplace == false)
                {
                    isDejaRemplace = true;
                    Score[j] = tab.getPoint();
                }

                if(j == 9)
                    file<<Score[j]<<";";
                else
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

interface::interface() {
    for (int i = 0; i < 10; ++i) {
        Score[i] = 0;
    }
    quit = false;
}

void interface::menu() {
    int choix;

    do{
        cout<<"*****************************"<<endl;
        cout<<"\nQue voulez-vous faire?"<<endl;
        cout<<"\tjouer(1)"<<endl;
        cout<<"\tMeilleure score(2)"<<endl;
        cout<<"\tQuitter(3)"<<endl;
        cin>>choix;
    }while(choix>2||choix<1);
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

void interface::SortScore() {
    fstream file;
    string temp;

    file.open("highscore.txt",ios::in);
    if(!file){
        cout<<"highscore.txt n'est pas disponible"<<endl;
    } else{
        getline(file,temp,';');
    }
    int longueur = temp.length();
    int cpt = 0;
    for (int i = 0; i < longueur; ++i) {
        if(temp.at(i) != ',')
        {
            Score[cpt] = stoi(temp.substr(i),nullptr,10);
            cpt++;
        }
    }
    int max = -1;
    int indmax;
    int ScoreTemp [10];
    for (int k = 0; k < 10 ; ++k) {
        for (int j = 0; j < 10; ++j) {
            if(Score[j] > max)
            {
                max = Score[j];
                indmax = j;
            }
        }
        if(k == 9)
            ValueMin = Score[indmax];
        ScoreTemp[k] = Score[indmax];
        Score[indmax] = 0;
        max = 0;
    }
    for (int l = 0; l < 10; ++l) {

        Score[l] = ScoreTemp[l];
    }
}

void interface::afficheScore() {
    system("cls");
    cout<<"\tMeilleure Score : "<<endl;
    for (int k = 0; k < 10; ++k) {
        cout << "player #"<<k+1<<" : "<<Score[k]<<endl;
    }

}



