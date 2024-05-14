// Plateau.cpp
#include "header/plateau.hpp"

Plateau::Plateau()
{
    initialiserPlateau();
}

void Plateau::initialiserPlateau()
{
    cases.resize(TAILLE);
    for (int i = 0; i < TAILLE; ++i)
    {
        cases[i].resize(TAILLE);
    }

    // Initialisation des pièces sur le plateau
    // Les pions blancs sont placés dans les lignes 0 à 2
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < TAILLE; ++j)
        {
            if ((i + j) % 2 != 0)
            {
                cases[i][j] = new Pion('O', true); // Pion blanc
            }
        }
    }

    // Les pions noirs sont placés dans les lignes 5 à 7
    for (int i = 5; i < TAILLE; ++i)
    {
        for (int j = 0; j < TAILLE; ++j)
        {
            if ((i + j) % 2 != 0)
            {
                cases[i][j] = new Pion('X', false); // Pion noir
            }
        }
    }
}

Piece *Plateau::obtenirPiece(int x, int y) const
{
    return cases[x][y];
}

void Plateau::placerPiece(Piece *piece, int x, int y)
{
    cases[x][y] = piece;
}

bool Plateau::estCaseVide(int x, int y) const
{
    return cases[x][y] == nullptr;
}

void Plateau::retirerPiece(int x, int y)
{

    cases[x][y] = nullptr; // Réinitialise la case à nullptr
}

void Plateau::afficherPlateau() const
{
    cout << "  0 1 2 3 4 5 6 7" << endl;
    for (int i = 0; i < 8; ++i)
    {
        cout << i << " ";
        for (int j = 0; j < 8; ++j)
        {
            if (cases[i][j] == nullptr)
            {
                cout << "-";
            }
            else
            {
                cout << cases[i][j]->getSymbole(); // Correction ici
            }
            cout << " ";
        }
        cout << endl;
    }
}

void Plateau::capturePiece(int ligne, int colonne) const
{
    // Supprimer la pièce à la position spécifiée en la remplaçant par un pointeur nul
    cases[ligne][colonne] = nullptr;
}

bool Plateau::conditionVictoire(Joueur *joueur) const
{
    // Parcourir toutes les cases du plateau
    for (int i = 0; i < TAILLE; ++i)
    {
        for (int j = 0; j < TAILLE; ++j)
        {
            // Vérifier si la case contient une pièce du joueur spécifié
            Piece *piece = obtenirPiece(i, j);
            if (piece != nullptr && piece->estPieceBlanche() == joueur->estBlanc())
            {
                // Le joueur a au moins une pièce sur le plateau, donc il n'a pas perdu
                return false;
            }
        }
    }
    // Si aucun pion ou dame du joueur n'est trouvé sur le plateau, le joueur a perdu
    return true;
}