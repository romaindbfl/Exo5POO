#ifndef JEU_HPP
#define JEU_HPP

#include "plateau.hpp"
#include "joueur.hpp"
#include "piece.hpp"
#include "dame.hpp"
#include "pion.hpp"

class Jeu {
private:
    Plateau plateau;
    Joueur joueur1;
    Joueur joueur2;
    Joueur* joueurCourant;

public:
    Jeu(); // Ajoutez le constructeur ici

    // Démarre une nouvelle partie
    void demarrerPartie();

     const Plateau& getPlateau() const;

    // Effectue le déplacement d'une pièce sur le plateau
    bool deplacerPiece(int departX, int departY, int arriveeX, int arriveeY);
        // Méthode pour manger une pièce
    //bool mangerPiece(int departX, int departY, int arriveeX, int arriveeY);

    Joueur* getJoueur1() { return &joueur1; }
    Joueur* getJoueur2() { return &joueur2; }
    



};

#endif