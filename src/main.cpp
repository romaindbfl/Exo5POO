#include "header/jeu.hpp"
#include "header/joueur.hpp"
#include <limits> // Ajout de l'inclusion pour numeric_limits
#include <iostream>
using namespace std;

int main()
{
    Jeu jeu;
    jeu.demarrerPartie();

    int departX, departY, arriveeX, arriveeY;
    bool joueur1Tour = true;

    Joueur *joueur1 = jeu.getJoueur1();
    Joueur *joueur2 = jeu.getJoueur2();

    while (true)
    {
        // Afficher le plateau
        jeu.getPlateau().afficherPlateau();

        // Déterminer le joueur en cours
        Joueur *joueurCourant = joueur1Tour ? joueur1 : joueur2;
        cout << "C'est le tour de " << joueurCourant->getNom() << " (" << (joueur1Tour ? "Blanc" : "Noir") << ")" << endl;

        // Demander au joueur de saisir les coordonnées de départ
        while (true)
        {
            cout << "Coordonnées de départ (x y) : ";
            if (!(cin >> departX >> departY))
            {
                // Si la saisie échoue, effacer le flux d'entrée et réessayer
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Veuillez entrer des coordonnées valides." << endl;
                continue;
            }
            // Vérifier s'il y a un pion sur la case de départ
            if (jeu.getPlateau().obtenirPiece(departX, departY) == nullptr)
            {
                cout << "Il n'y a pas de pion sur la case de départ. Veuillez réessayer." << endl;
                continue;
            }
            break;
        }

        // Demander au joueur de saisir les coordonnées d'arrivée
        cout << "Coordonnées d'arrivée (x y) : ";
        if (!(cin >> arriveeX >> arriveeY))
        {
            // Si la saisie échoue, effacer le flux d'entrée et réessayer
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Veuillez entrer des coordonnées valides." << endl;
            continue;
        }

        // Déplacer la pièce
        if (jeu.deplacerPiece(departX, departY, arriveeX, arriveeY))
        {
            cout << "Déplacement réussi !" << endl;
            // Vérifier si l'un des joueurs a perdu
            if (jeu.getPlateau().conditionVictoire(joueur1))
            {
                cout << joueur1->getNom() << " a perdu !" << endl;
                cout << joueur2->getNom() << " Félicitations, tu as gagné !" << endl;
                break;
            }
            else if (jeu.getPlateau().conditionVictoire(joueur2))
            {
                cout << joueur2->getNom() << " a perdu !" << endl;
                cout << joueur1->getNom() << " Félicitations, tu as gagné !" << endl;

                break;
            }
            // Changer de joueur
            joueur1Tour = !joueur1Tour;
        }
        else
        {
            cout << "Déplacement invalide. Veuillez réessayer." << endl;
        }
    }
    return 0;
}