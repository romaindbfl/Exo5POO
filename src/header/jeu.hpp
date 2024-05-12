// Incluez les en-têtes nécessaires

#include "plateau.hpp"
#include "joueur.hpp"
#include "dame.hpp"

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

    Joueur* getJoueur1() { return &joueur1; }
    Joueur* getJoueur2() { return &joueur2; }

private:
    // Vérifie si le déplacement est valide
    bool estDeplacementValide(int departX, int departY, int arriveeX, int arriveeY) const;

    // Vérifie si le joueur peut déplacer une pièce dans le plateau
    bool peutDeplacer(const Joueur& joueur) const;


};
