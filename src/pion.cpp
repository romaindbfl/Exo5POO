#include "header/pion.hpp"

Pion::Pion(char symbole, bool blanc) : Piece(symbole, blanc) {}

bool Pion::estPieceBlanche() const 
    {
        return blanc;
    }

bool Pion::estDeplacementValide(int departX, int departY, int arriveeX, int arriveeY, const Plateau& plateau, string& raisonInvalide) const {
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