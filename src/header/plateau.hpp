#ifndef PLATEAU_HPP
#define PLATEAU_HPP

#include "pion.hpp"
#include "dame.hpp"
#include "case.hpp"
#include "joueur.hpp"
#include <vector>
#include <iostream>

class Piece;
class Pion; 

class Plateau {
private:
    mutable vector<vector<Piece*>> cases; // Déclarez cases comme mutable
    Piece* pieces[8][8]; // Déclaration de la variable membre pieces

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
    void capturePiece(int ligne, int colonne) const;
    bool conditionVictoire(Joueur* joueur) const;
};

#endif // PLATEAU_HPP
