#ifndef PIECE_HPP
#define PIECE_HPP

#include <string>
using namespace std;

class Plateau;

class Piece
{
protected:
    char symbole;
    bool blanc;

public:
    Piece(char symbole, bool blanc);
    char getSymbole() const;
    virtual bool estPieceBlanche() const = 0; 
    virtual bool estDeplacementValide(int departX, int departY, int arriveeX, int arriveeY, const Plateau &plateau, string &raisonInvalide) const = 0;

    virtual bool estDame() const
    {
        return false; // Une pièce ordinaire n'est pas une dame
    }
};

#endif // PIECE_HPP
