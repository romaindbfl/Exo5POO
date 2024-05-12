// Piece.cpp
#include "header/piece.hpp"

Piece::Piece(char symbole, bool blanc) : symbole(symbole), blanc(blanc) {}

    // Getter pour le symbole de la pièce
    char Piece::getSymbole() const {
        return symbole;
    }

    // Getter pour la couleur de la pièce
    bool Piece::estPieceBlanche() const {
        return blanc;
    }



