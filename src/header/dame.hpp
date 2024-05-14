// dame.hpp
#ifndef DAME_HPP
#define DAME_HPP

#include "piece.hpp"
#include "plateau.hpp"
class Plateau;

class Dame : public Piece
{
public:
    Dame(char symbole, bool blanc);

    bool estDeplacementValide(int departX, int departY, int arriveeX, int arriveeY, const Plateau &plateau, string &raisonInvalide) const override;
    bool estPieceBlanche() const override;
};

#endif // DAME_HPP