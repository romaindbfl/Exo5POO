#include "header/dame.hpp"

Dame::Dame(char symbole, bool blanc) : Piece(symbole, blanc) {}

bool Dame::estPieceBlanche() const
{
  return blanc;
}

bool Dame::estDeplacementValide(int departX, int departY, int arriveeX, int arriveeY, const Plateau &plateau, string &raisonInvalide) const
{
   // Vérifier s'il y a un pion sur la case de départ
    if (plateau.obtenirPiece(departX, departY) == nullptr)
    {
        raisonInvalide = "Il n'y a pas de pion sur la case de départ.";
        return false;
    }
  // Vérifier si une capture est possible dans n'importe quelle direction
  if (abs(arriveeX - departX) > 1 && abs(arriveeY - departY) > 1)
  {
    int deltaX = (arriveeX - departX > 0) ? 1 : -1;
    int deltaY = (arriveeY - departY > 0) ? 1 : -1;
    int x = departX + deltaX;
    int y = departY + deltaY;
    while (x != arriveeX && y != arriveeY)
    {
      if (!plateau.estCaseVide(x, y))
      {
        if (plateau.obtenirPiece(x, y)->estPieceBlanche() != estPieceBlanche())
        {
          // Capture du pion
          plateau.capturePiece(x, y);
          return true;
        }
        else
        {
          raisonInvalide = "Impossible de capturer son propre pion.";
          return false;
        }
      }
      x += deltaX;
      y += deltaY;
    }

    // Aucun pion à capturer sur la trajectoire, autoriser le déplacement
    return true;
  }

  // Vérifier si le déplacement est sur une diagonale
  if (abs(arriveeX - departX) == abs(arriveeY - departY))
  {
    // Vérifier si le chemin entre le départ et l'arrivée est libre
    int deltaX = (arriveeX - departX > 0) ? 1 : (arriveeX - departX < 0) ? -1
                                                                         : 0;
    int deltaY = (arriveeY - departY > 0) ? 1 : (arriveeY - departY < 0) ? -1
                                                                         : 0;

    int x = departX + deltaX;
    int y = departY + deltaY;
    while (x != arriveeX || y != arriveeY)
    {
      if (!plateau.estCaseVide(x, y))
      {
        raisonInvalide = "Le chemin n'est pas libre.";
        return false; // Le chemin n'est pas libre
      }
      x += deltaX;
      y += deltaY;
    }

    // Le déplacement est valide
    return true;
  }

  // Le déplacement n'est ni une capture ni sur une diagonale
  raisonInvalide = "Le déplacement n'est pas valide.";
  return false;
}