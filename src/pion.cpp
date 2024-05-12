#include "header/pion.hpp"

Pion::Pion(char symbole, bool estBlanc) : Piece(symbole, estBlanc) {}


bool Pion::estDeplacementValide(int departX, int departY, int arriveeX, int arriveeY, string& raisonInvalide) const{
    return true; //retourne toujours vrai pour l'instant
}