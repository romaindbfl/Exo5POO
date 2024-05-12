#ifndef PION_HPP
#define PION_HPP

#include "piece.hpp"
#include "plateau.hpp"


class Pion : public Piece {
public:
    Pion(char symbole, bool blanc);
    bool estDeplacementValide(int departX, int departY, int arriveeX, int arriveeY, string& raisonInvalide) const override;

    bool estPieceBlanche() const override {
        return blanc;
    }
    void mangerPiece(int x, int y);
       
};

#endif // PION_HPP
