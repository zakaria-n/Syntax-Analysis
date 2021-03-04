#pragma once

#include <string>
using namespace std;

enum Identificateurs { OPENPAR, CLOSEPAR, PLUS, MULT, INT, FIN, ERREUR, EXPR };

const string Etiquettes[] = { "OPENPAR", "CLOSEPAR", "PLUS", "MULT", "INT", "FIN", "ERREUR", "EXPR" };

class Symbole {
   public:
      Symbole(int i) : ident(i) {  }
      virtual ~Symbole() { }
      operator int() const { return ident; }
      virtual void Affiche();
      bool estTerminal() {return ident != EXPR;}
      void toExpr() {ident = EXPR;};
   protected:
      int ident;
};

class Entier : public Symbole {
   public:
      Entier(int v) : Symbole(INT), valeur(v) { }
      ~Entier() { }
      virtual void Affiche();
   protected:
      int valeur;
};

class Expr : public Entier {
   public :
      Expr(Entier* v):Entier(*v) {toExpr();}
      virtual ~Expr() {}
      virtual void Affiche();
};

class ExprPlus : public Expr {
   public :
      ExprPlus(Expr* exp1, Expr* exp2):Entier(exp1->valeur+exp2->valeur) {toExpr();}
      virtual ~ExprPlus() {}
      virtual void Affiche();
}

class ExprMult : public Expr {
   public :
      ExprMult(Expr* exp1, Expr* exp2):Entier(exp1->valeur*exp2->valeur) {toExpr();}
      virtual ~ExprMult() {}
      virtual void Affiche();
}