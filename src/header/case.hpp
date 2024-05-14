#ifndef CASE_HPP
#define CASE_HPP

#include "piece.hpp"

class Case 
{
private:
    Piece *piece; // Pointeur vers la pièce sur cette case

public:
    Case();

    // Vérifie si la case est vide
    bool estVide() const;

    // Obtenir la pièce sur cette case
    Piece *obtenirPiece() const;

    // Placer une pièce sur cette case
    void placerPiece(Piece *nouvellePiece);

    // Supprimer la pièce de cette case
    void retirerPiece();
};

#endif // CASE_HPP
