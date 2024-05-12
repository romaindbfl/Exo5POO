// Plateau.hpp
#ifndef PLATEAU_HPP
#define PLATEAU_HPP

#include "case.hpp"
#include "joueur.hpp"
#include "piece.hpp"
#include "pion.hpp"
#include <vector>
#include <iostream>

class Plateau {
private:
    vector<vector<Piece*>> cases; // Matrice représentant les cases du plateau

public:
static const int TAILLE = 8; // Taille du plateau de jeu
    Plateau();

    // Initialiser le plateau avec des pièces
    void initialiserPlateau();

    // Méthode pour obtenir une pièce à une position spécifique
    Piece* obtenirPiece(int x, int y) const;
    // Méthode pour placer une pièce à une position spécifique
    void placerPiece(Piece* piece, int x, int y);

    // Méthode pour vérifier si une case est vide
    bool estCaseVide(int x, int y) const;
    void retirerPiece(int x, int y);
    void afficherPlateau() const;
};

#endif // PLATEAU_HPP
