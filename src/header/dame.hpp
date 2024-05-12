// dame.hpp
#ifndef DAME_HPP
#define DAME_HPP

#include "piece.hpp"
#include "plateau.hpp"

class Dame : public Piece {
public:
    Dame(char symbole, bool blanc);

   bool estDeplacementValide(int departX, int departY, int arriveeX, int arriveeY, string& raisonInvalide) const override;
    bool estPieceBlanche() const override {
        return blanc;
    }
};

#endif // DAME_HPP