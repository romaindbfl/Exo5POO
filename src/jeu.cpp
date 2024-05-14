#include "header/jeu.hpp"
#include <iostream>

// Constructeur de la classe Jeu
Jeu::Jeu() : joueur1("Joueur1", 'W'), joueur2("Joueur2", 'B'), joueurCourant(&joueur1) {}

// Fonction pour démarrer une partie
void Jeu::demarrerPartie()
{
    plateau.initialiserPlateau();
    cout << "La partie démarre !" << endl;
}

bool Jeu::deplacerPiece(int departX, int departY, int arriveeX, int arriveeY)
{
    // Obtenir la pièce à déplacer
    Piece *piece = plateau.obtenirPiece(departX, departY);

    // Déclarer une variable pour stocker la raison invalide afin de rendre le jeu plus compréhensible pour l'user
    string raisonInvalide;

    if (!piece->estDeplacementValide(departX, departY, arriveeX, arriveeY, plateau, raisonInvalide))
    {
        cout << "Déplacement invalide ! Raison : " << raisonInvalide << endl; // Affichage de la raison invalide
        return false;
    }

    // Obtenir la pièce à déplacer
    Piece *pieceADeplacer = plateau.obtenirPiece(departX, departY);

    // Déplacer la pièce
    plateau.placerPiece(pieceADeplacer, arriveeX, arriveeY);
    plateau.retirerPiece(departX, departY);

    // Promotion des pions s'ils atteignent la dernière rangée ou la paroi noire
    if ((arriveeY == Plateau::TAILLE - 1 && pieceADeplacer->getSymbole() == 'O') ||
        (arriveeY == 0 && pieceADeplacer->getSymbole() == 'X') ||
        (arriveeX == Plateau::TAILLE - 1 && pieceADeplacer->getSymbole() == 'O'))
    {
        // Promotion du pion en dame
        char symbolePromotion = pieceADeplacer->getSymbole() == 'O' ? 'W' : 'B';
        plateau.placerPiece(new Dame(symbolePromotion, pieceADeplacer->estPieceBlanche()), arriveeX, arriveeY);
    }

    // Changer de joueur
    if (joueurCourant == &joueur1)
    {
        joueurCourant = &joueur2;
    }
    else
    {
        joueurCourant = &joueur1;
    }

    return true;
}

// Accesseur pour obtenir le plateau
const Plateau &Jeu::getPlateau() const
{
    return plateau;
}
