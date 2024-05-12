// Piece.cpp
#include "header/piece.hpp"

Piece::Piece(char symbole, bool estBlanc) : symbole(symbole), estBlanc(estBlanc) {}

    // Getter pour le symbole de la pièce
    char Piece::getSymbole() const {
        return symbole;
    }

    // Getter pour la couleur de la pièce
    bool Piece::estPieceBlanche() const {
        return estBlanc;
    }


bool Piece::estDeplacementValide(int departX, int departY, int arriveeX, int arriveeY) const {
    return true; //retourne toujours vrai pour l'instant
}
