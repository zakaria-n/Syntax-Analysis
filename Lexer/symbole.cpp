#include "symbole.h"
#include <iostream>

void Symbole::Affiche() {
   cout<<Etiquettes[ident];
}

void Entier::Affiche() {
   Symbole::Affiche();
   cout<<"("<<valeur<<")";
}

void Expr::Affiche() {
   Symbole::Affiche();
   cout<<"(not Implemented yet)";
}

int Entier::getValeur() {
   return this->valeur;
}