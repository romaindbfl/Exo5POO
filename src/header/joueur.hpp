// Joueur.hpp
#ifndef JOUEUR_HPP
#define JOUEUR_HPP
#include <string>
using namespace std;

class Joueur
{
private:
    string nom;
    char symbole; // Symbole utilisé pour représenter les pions du joueur sur le plateau

public:
    Joueur(const string &nom, char symbole); 
    Joueur() = default;                      // Constructeur par défaut
    // Getter pour le nom du joueur
    string getNom() const;

    // Getter pour le symbole du joueur
    char getSymbole() const;
    bool estBlanc() const;
};

#endif // JOUEUR_HPP
