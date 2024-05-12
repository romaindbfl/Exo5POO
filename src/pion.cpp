#include "header/pion.hpp"

Pion::Pion(char symbole, bool estBlanc) : Piece(symbole, estBlanc) {}

bool Pion::estDeplacementValide(int departX, int departY, int arriveeX, int arriveeY, string& raisonInvalide) const {
    // Accéder au plateau à partir du jeu
Plateau plateau;    
    // Vérifier si le déplacement est en diagonale
    if (abs(arriveeX - departX) != 1 || abs(arriveeY - departY) != 1) {
        raisonInvalide = "Le déplacement n'est pas en diagonale.";
        return false;
    }

    // Vérifier si le déplacement est toujours en avant sauf s'il prend un pion ou une dame
    if (!estDame()) {
        // Si c'est un pion, vérifier si le déplacement est en avant
        if (estPieceBlanche()) {
            if (arriveeX <= departX) {
                raisonInvalide = "Le déplacement n'est pas en avant.";
                return false;
            }
        } else {
            if (arriveeX >= departX) {
                raisonInvalide = "Le déplacement n'est pas en avant.";
                return false;
            }
        }
    }
    
    // Vérifier si la case voisine en diagonale est vide
    if (plateau.obtenirPiece(arriveeX, arriveeY) != nullptr) {
        raisonInvalide = "La case d'arrivée n'est pas vide.";
        return false;
    }

    // Tous les critères de validité sont satisfaits
    return true;
}

void Pion::mangerPiece(int x, int y) {
    // Coordonnées du pion à retirer
    int xPiece = (x + getX()) / 2;
    int yPiece = (y + getY()) / 2;

    // Retirer la pièce du plateau
    plateau->retirerPiece(xPiece, yPiece);

    // Déplacer le pion sur la case libre
    deplacer(x, y);
}
