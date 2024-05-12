  #include "header/dame.hpp"

  Dame::Dame(char symbole, bool estBlanc) : Piece(symbole, estBlanc) {}

  bool Dame::estDeplacementValide(int departX, int departY, int arriveeX, int arriveeY) const {
      Plateau plateau; 
    // Vérifier si le déplacement est horizontal, vertical ou diagonal
    if ((arriveeX == departX || arriveeY == departY || abs(arriveeX - departX) == abs(arriveeY - departY)) && 
        !(arriveeX == departX && arriveeY == departY)) { // la position de départ et d'arrivée DOIT être différente
        // Vérifier si le chemin entre le départ et l'arrivée est libre
        int deltaX = (arriveeX - departX > 0) ? 1 : (arriveeX - departX < 0) ? -1 : 0;
        int deltaY = (arriveeY - departY > 0) ? 1 : (arriveeY - departY < 0) ? -1 : 0;

        int x = departX + deltaX;
        int y = departY + deltaY;
        while (x != arriveeX || y != arriveeY) {
            if (!plateau.estCaseVide(x, y)) {
                return false; // Le chemin n'est pas libre
            }
            x += deltaX;
            y += deltaY;
        }

        // Vérifier si la case d'arrivée est vide ou contient une pièce adverse
        Piece* pieceArrivee = plateau.obtenirPiece(arriveeX, arriveeY);
        if (pieceArrivee == nullptr || pieceArrivee->estPieceBlanche() != estBlanc) {
            return true;
        }
    }

    // Le déplacement n'est pas valide
    return false;
}

    