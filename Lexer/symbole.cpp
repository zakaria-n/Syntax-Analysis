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

ExprPlus::ExprPlus(Expr* exp1, Expr* exp2) {
   toExpr();
   valeur = exp1->getValeur() + exp2->getValeur();
}

ExprMult::ExprMult(Expr* exp1, Expr* exp2) {
   toExpr();
   valeur = exp1->getValeur() * exp2->getValeur();
}

int Entier::getValeur() {
   return this->valeur;
}