#include "header/pion.hpp"

Pion::Pion(char symbole, bool blanc) : Piece(symbole, blanc) {}

bool Pion::estPieceBlanche() const 
    {
        return blanc;
    }

bool Pion::estDeplacementValide(int departX, int departY, int arriveeX, int arriveeY, const Plateau& plateau, string& raisonInvalide) const {
    // Vérifier s'il y a un pion à capturer avant de vérifier si le déplacement est en diagonale
    if (abs(arriveeX - departX) == 2 && abs(arriveeY - departY) == 2) {
        // Coordonnées de la case à capturer
        int ligneCapture = (departX + arriveeX) / 2;
        int colonneCapture = (departY + arriveeY) / 2;

        // Vérifier si la case entre les positions de départ et d'arrivée contient une pièce adverse
        if (plateau.obtenirPiece(ligneCapture, colonneCapture) != nullptr && plateau.obtenirPiece(ligneCapture, colonneCapture)->estPieceBlanche() != estPieceBlanche()) {
            // Vérifier si la case d'arrivée est vide
            if (plateau.obtenirPiece(arriveeX, arriveeY) == nullptr) {
                // La capture est valide, enlever la pièce capturée
                plateau.capturePiece(ligneCapture, colonneCapture);
                return true;
            }
        }
        
        raisonInvalide = "Le déplacement n'est pas valide. Un pion peut capturer une pièce en se déplaçant de deux cases en diagonale.";
        return false;
    }

    // Vérifier si le déplacement est en diagonale
    if (abs(arriveeX - departX) != 1 || abs(arriveeY - departY) != 1) {
        raisonInvalide = "Le déplacement n'est pas en diagonale.";
        return false;
    }

    // Vérifier si le pion se déplace vers le haut du plateau
    if (estPieceBlanche() && arriveeX <= departX) {
        raisonInvalide = "Un pion blanc ne peut pas reculer.";
        return false;
    }

    if (!estPieceBlanche() && arriveeX >= departX) {
        raisonInvalide = "Un pion noir ne peut pas reculer.";
        return false;
    }

    // Vérifier si la case voisine en diagonale est vide
    if (plateau.obtenirPiece(arriveeX, arriveeY) != nullptr) {
        raisonInvalide = "La case d'arrivée n'est pas vide.";
        return false;
    }

    // Tous les critères de validité sont satisfaits pour un déplacement non-capture
    return true;
}
