#pragma once

#include <string>
using namespace std;

enum Identificateurs { OPENPAR, CLOSEPAR, PLUS, MULT, INT, FIN, ERREUR, EXPR };

const string Etiquettes[] = { "OPENPAR", "CLOSEPAR", "PLUS", "MULT", "INT", "FIN", "ERREUR", "EXPR" };

class Symbole {
   public:
      Symbole(int i, bool t) : ident(i), terminal(t) {  }
      virtual ~Symbole() { }
      operator int() const { return ident; }
      virtual void Affiche();
      bool estTerminal() {return terminal;}
   protected:
      int ident;
      bool terminal;
};

class Entier : public Symbole {
   public:
      Entier(int v) : Symbole(INT, true), valeur(v) { }
      ~Entier() { }
      virtual void Affiche();
   protected:
      int valeur;
};

class Expr : public Symbole {
   public :
      Expr():Symbole(EXPR, false) {}
      virtual ~Expr() {}
      virtual void Affiche();
   protected :
      // eval map
};

class ExprBin : public Expr {
   public :
      ExprBin(Expr * e1, Expr * e2):Expr(), expr1(e1), expr2(e2) {}
      virtual ~ExprBin() {}
   protected :
      Expr * expr1;
      Expr * expr2;
};

class ExprPlus : public ExprBin {
   public :
      ExprPlus(Expr * e1, Expr * e2):ExprBin(e1,e2), operateur(Symbole(PLUS,true)) {}
   protected :
      Symbole operateur;
};

class ExprMult : public ExprBin {
   public :
      ExprPlus(Expr * e1, Expr * e2):ExprBin(e1,e2), operateur(Symbole(MULT,true)) {}
   protected :
      Symbole operateur;
};

