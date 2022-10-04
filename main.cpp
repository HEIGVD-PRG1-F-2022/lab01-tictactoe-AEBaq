/*
 * Baquerizo Lema Anny Emily
 * Rendu le 29 septembre 2022
 * Laboratoire Tic Tac Toe
 *
 */
#include <iostream>
#include <string>
#include <list>

using namespace std;

bool check(int valeur, list<int> liste, bool& a)    {
    for (int i : liste) {
        if(valeur == i)  {
            a = true;
        }
    }
    return a;
}

void plateau(string (&qua)[3][3]){
    cout << "   " + qua[0][0] + "   |   " + qua[0][1] + "   |   " + qua[0][2] + ""<< endl;
    cout << "--------------------" << endl;
    cout << "   " + qua[1][0] + "   |   " + qua[1][1] + "   |   " + qua[1][2] + "" << endl;
    cout << "--------------------" << endl;
    cout << "   " + qua[2][0] + "   |   " + qua[2][1] + "   |   " + qua[2][2] + ""<< endl;
    cout << "" << endl;
}

//Version pour 2 joueurs V2.2: changement de joueur effectué via un bool
void player2 () {
    string qua[3][3] = {
            {"", "", ""},
            {"", "", ""},
            {"", "", ""}
    };

    bool end = false;
    //Fonctionnement
    cout << "Pour choisir une case, il suffit de rentrer le chiffre de la case correspondante lors de votre tour." << endl;
    cout << "" << endl;
    cout << "   1   |   2   |   3   "<< endl;
    cout << "-----------------------" << endl;
    cout << "   4   |   5   |   6   " << endl;
    cout << "-----------------------" << endl;
    cout << "   7   |   8   |   9   "<< endl;
    cout << "" << endl;


    //Initialisation nmbre de tour
    int tour = 0;

    //Changement de tour du joueur
    bool joueur1 = true;

    //Liste de case restante
    list<int> libre = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    cout << "La partie commence" << endl;
    //1 Tour de jeu
    while (!end && tour <= 8) {
        //Tour
        tour ++;
        cout << "Tour " << tour << endl;

        //Affichage plateau de jeu
        plateau(qua);

        string coup;

        //Tour du joueur
        string symbole;

        if (joueur1)   {
            cout << "Au tour du joueur 1 :   " << endl;
            symbole = "o";
        }
        else    {
            cout << "Au tour du joueur 2 : " << endl;
            symbole = "x";
        }
        cin >> coup;
        int choix = stoi(coup);

        bool vide = false;
        check(choix, libre, vide);

        while(vide == false)
        {
            cout << "Veuillez entrer un chiffre entre 1 et 9 correspondant a une case vide" << endl;
            cin >> coup;
            choix = stoi(coup);
            check(choix, libre, vide);
        }

        switch(choix) {
            case 1:
                qua[0][0] = symbole;
                libre.remove(1);
                break;
            case 2:
                qua[0][1] = symbole;
                libre.remove(2);
                break;
            case 3:
                qua[0][2] = symbole;
                libre.remove(3);
                break;
            case 4:
                qua[1][0] = symbole;
                libre.remove(4);
                break;
            case 5:
                qua[1][1] = symbole;
                libre.remove(5);
                break;
            case 6:
                qua[1][2] = symbole;
                libre.remove(6);
                break;
            case 7:
                qua[2][0] = symbole;
                libre.remove(7);
                break;
            case 8:
                qua[2][1] = symbole;
                libre.remove(8);
                break;
            case 9:
                qua[2][2] = symbole;
                libre.remove(9);
                break;
        }

        //Vérification d'une ligne
        for(int i = 0; i < 3; i++) {
            if (qua[i][0] == qua[i][1] && qua[i][0] == qua[i][2] && qua[i][0] != "") {
                end = true;
            }
        }

        //Vérification d'une colonne
        for(int i = 0; i < 3; i++) {
            if (qua[0][i] == qua[1][i] && qua[0][i] == qua[2][i] && qua[0][i] != "") {
                end = true;
            }
        }

        //Vérification d'une diagonale
        int i = 0;
        if (qua[0][0] == qua[1][1] && qua[0][0] == qua[2][2] && qua[0][0] != "") {
            end = true;
        }
        if (qua[0][2] == qua[1][1] && qua[0][2] == qua[2][0] && qua[0][2] != "") {
            end = true;
        }

        //Changement de joueur
        joueur1 = !joueur1;

    }

    //Affichage final plateau de jeu
    plateau(qua);

    if (tour == 9)    {
        cout << "Il n'y a pas de gagnant." << endl;
    }
    else if (!joueur1)   {
        cout << "Le joueur 1 gagne" << endl;
    }
    else    {
        cout << "Le joueur 2 gagne" << endl;
    }
}

int main() {
    player2();
    return 0;
}
