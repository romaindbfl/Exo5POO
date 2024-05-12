#include "header/case.hpp"

 Case::Case() : piece(nullptr) {} // Initialiser la case sans pièce

    // Vérifie si la case est vide
    bool Case::estVide() const {
        return piece == nullptr;
    }

    // Obtenir la pièce sur cette case
    Piece* Case::obtenirPiece() const {
        return piece;
    }

    // Placer une pièce sur cette case
    void Case::placerPiece(Piece* nouvellePiece) {
        piece = nouvellePiece;
    }

    // Supprimer la pièce de cette case
    void Case::retirerPiece() {
        piece = nullptr;
    }