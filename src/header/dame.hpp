// dame.hpp
#ifndef DAME_HPP
#define DAME_HPP

#include "piece.hpp"
#include "plateau.hpp"

class Dame : public Piece {
public:
    Dame(char symbole, bool estBlanc);

    bool estDeplacementValide(int departX, int departY, int arriveeX, int arriveeY) const;

    bool estPieceBlanche() const override {
        return estBlanc;
    }
};

#endif // DAME_HPP