#include "header/jeu.hpp"
#include "header/joueur.hpp"
#include "header/plateau.hpp"
#include "header/piece.hpp"
#include "header/case.hpp"
using namespace std;    
#include <iostream>

int main() {
    Jeu jeu;
    jeu.demarrerPartie();

    int departX, departY, arriveeX, arriveeY;
    bool joueur1Tour = true;

    while (true) {
        // Afficher le plateau
        jeu.getPlateau().afficherPlateau();

        // Déterminer le joueur en cours
        Joueur* joueurCourant = joueur1Tour ? jeu.getJoueur1() : jeu.getJoueur2();
        cout << "C'est le tour de " << joueurCourant->getNom() << " (" << (joueur1Tour ? "Blanc" : "Noir") << ")" << endl;

        // Demander au joueur de saisir les coordonnées de départ
        cout << "Coordonnées de départ (x y) : ";
        cin >> departX >> departY;

        // Demander au joueur de saisir les coordonnées d'arrivée
        cout << "Coordonnées d'arrivée (x y) : ";
        cin >> arriveeX >> arriveeY;

        // Déplacer la pièce
        if (jeu.deplacerPiece(departX, departY, arriveeX, arriveeY)) {
            cout << "Déplacement réussi !" << endl;
            // Changer de joueur
            joueur1Tour = !joueur1Tour;
        } else {
            cout << "Déplacement invalide. Veuillez réessayer." << endl;
        }
    }

    return 0;
}
