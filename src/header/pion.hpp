#ifndef PION_HPP
#define PION_HPP

#include "piece.hpp" 
#include "plateau.hpp" 

class Plateau; 

class Pion : public Piece
{
public:
    Pion(char symbole, bool blanc);
    bool estDeplacementValide(int departX, int departY, int arriveeX, int arriveeY, const Plateau &plateau, string &raisonInvalide) const override;

    bool estPieceBlanche() const override;
    
};

#endif // PION_HPP
