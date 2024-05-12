#include "header/jeu.hpp"
#include <iostream>

// Constructeur de la classe Jeu
Jeu::Jeu() : joueur1("NomJoueur1", 'W'), joueur2("NomJoueur2", 'B'), joueurCourant(&joueur1) {}

// Fonction pour démarrer une partie
void Jeu::demarrerPartie() {
    plateau.initialiserPlateau();
    cout << "La partie démarre !" << endl; 
}

// Fonction pour déplacer une pièce sur le plateau
bool Jeu::deplacerPiece(int departX, int departY, int arriveeX, int arriveeY) {
    // Vérifier si le déplacement est valide
    if (!estDeplacementValide(departX, departY, arriveeX, arriveeY)) {
        cout << "Déplacement invalide !" << endl; // Affichage du message d'erreur
        return false;
    }

    // Obtenir la pièce à déplacer
    Piece* pieceADeplacer = plateau.obtenirPiece(departX, departY);

    // Déplacer la pièce
    plateau.placerPiece(pieceADeplacer, arriveeX, arriveeY);
    plateau.retirerPiece(departX, departY);

    // Promotion des pions s'ils atteignent la dernière rangée
    if (arriveeY == 0 || arriveeY == Plateau::TAILLE - 1) {
        if (pieceADeplacer->getSymbole() == 'O' && arriveeY == 0) {
            // Promotion d'un pion blanc
            plateau.placerPiece(new Dame('W', true), arriveeX, arriveeY);
        } else if (pieceADeplacer->getSymbole() == 'X' && arriveeY == Plateau::TAILLE - 1) {
            // Promotion d'un pion noir
            plateau.placerPiece(new Dame('B', false), arriveeX, arriveeY);
        }
    }

    // Changer de joueur
    if (joueurCourant == &joueur1) {
        joueurCourant = &joueur2;
    } else {
        joueurCourant = &joueur1;
    }

    return true;
}

// Fonction pour vérifier si un déplacement est valide
bool Jeu::estDeplacementValide(int departX, int departY, int arriveeX, int arriveeY) const {
    // Vérifier si les coordonnées sont dans les limites du plateau
    if (departX < 0 || departX >= Plateau::TAILLE || departY < 0 || departY >= Plateau::TAILLE ||
        arriveeX < 0 || arriveeX >= Plateau::TAILLE || arriveeY < 0 || arriveeY >= Plateau::TAILLE) {
        return false;
    }

    // Vérifier si la case de départ contient une pièce du joueur actuel
    Piece* pieceADeplacer = plateau.obtenirPiece(departX, departY);
    if (pieceADeplacer == nullptr || pieceADeplacer->estPieceBlanche() != joueurCourant->estBlanc()) {
        return false;
    }

    // Vérifier si la case d'arrivée est vide
    if (!plateau.estCaseVide(arriveeX, arriveeY)) {
        return false;
    }

    // Vérifier la direction du déplacement selon la couleur du joueur
    if (joueurCourant->estBlanc()) {
        // Les pièces blanches se déplacent vers le haut
        if (arriveeX <= departX) {
            return false;
        }
    } else {
        // Les pièces noires se déplacent vers le bas
        if (arriveeX >= departX) {
            return false;
        }
    }

    // Temporairement, on autorise tous les déplacements valides
    return true;
}

// Fonction pour vérifier si un joueur peut déplacer une pièce
bool Jeu::peutDeplacer(const Joueur& joueur) const {
    // Parcourir toutes les cases du plateau pour vérifier si le joueur a des pièces qu'il peut déplacer
    for (int i = 0; i < Plateau::TAILLE; ++i) {
        for (int j = 0; j < Plateau::TAILLE; ++j) {
            Piece* piece = plateau.obtenirPiece(i, j);
            if (piece != nullptr && piece->estPieceBlanche() == joueur.estBlanc()) {
                // Vérifier si cette pièce peut effectuer un déplacement valide
                for (int k = -1; k <= 1; k += 2) {
                    for (int l = -1; l <= 1; l += 2) {
                        if (estDeplacementValide(i, j, i + k, j + l)) {
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}

// Accesseur pour obtenir le plateau
const Plateau& Jeu::getPlateau() const {
    return plateau;
}
