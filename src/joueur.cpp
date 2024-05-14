// Joueur.cpp
#include "header/joueur.hpp"

Joueur::Joueur(const string &nom, char symbole) : nom(nom), symbole(symbole) {}

// Getter pour le nom du joueur
string Joueur::getNom() const
{
    return nom;
}

// Getter pour le symbole du joueur
char Joueur::getSymbole() const
{
    return symbole;
}

bool Joueur::estBlanc() const
{
    return symbole == 'W';
}