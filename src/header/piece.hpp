// Piece.hpp
#ifndef PIECE_HPP
#define PIECE_HPP
#include <string>


class Piece {
protected:
    char symbole;
    bool estBlanc;

public:
    Piece(char symbole, bool estBlanc);
    char getSymbole() const;
    virtual bool estPieceBlanche() const = 0; // Dans la classe Piece
    virtual bool estDeplacementValide(int departX, int departY, int arriveeX, int arriveeY) const;
    
virtual bool estDame() const {
    return false; // Une pièce ordinaire n'est pas une dame
}
    
};

#endif // PIECE_HPP
