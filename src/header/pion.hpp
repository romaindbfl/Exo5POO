// pion.hpp
#ifndef PION_HPP
#define PION_HPP

#include "piece.hpp"

class Pion : public Piece {
public:
    Pion(char symbole, bool estBlanc);
    bool estDeplacementValide(int departX, int departY, int arriveeX, int arriveeY) const;

    bool estPieceBlanche() const override {
        return estBlanc;
    }
};

#endif // PION_HPP
