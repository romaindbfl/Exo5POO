  #include "header/dame.hpp"

  Dame::Dame(char symbole, bool estBlanc) : Piece(symbole, estBlanc) {}

bool Dame::estDeplacementValide(int departX, int departY, int arriveeX, int arriveeY, string& raisonInvalide) const {
  Plateau plateau; 
    // Vérifier si le déplacement est sur une diagonale
    if (abs(arriveeX - departX) == abs(arriveeY - departY)) {
        // Vérifier si le chemin entre le départ et l'arrivée est libre
        int deltaX = (arriveeX - departX > 0) ? 1 : (arriveeX - departX < 0) ? -1 : 0;
        int deltaY = (arriveeY - departY > 0) ? 1 : (arriveeY - departY < 0) ? -1 : 0;

        int x = departX + deltaX;
        int y = departY + deltaY;
        while (x != arriveeX || y != arriveeY) {
            if (!plateau.estCaseVide(x, y)) {
                raisonInvalide = "Le chemin n'est pas libre.";
                return false; // Le chemin n'est pas libre
            }
            x += deltaX;
            y += deltaY;
        }

        // Le déplacement est valide
        return true;
    }

    // Le déplacement n'est pas sur une diagonale
    raisonInvalide = "Le déplacement n'est pas sur une diagonale.";
    return false;
}


    