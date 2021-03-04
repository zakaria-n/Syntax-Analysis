#pragma once
#include "lexer.h"
#include "symbole.h"
#include <stack>

class Etat;
class Automate {

    public :
        Automate(string chaine);
        virtual ~Automate();
        void run();
        void lecture();
        void reduction(int n, Symbole * s);
        void decalage(Symbole * s, Etat * e);
        Symbole* popSymbol();
        void popAndDestroySymbol();
    
    protected :
        // Attributs
        Lexer* lexer;
        stack<Symbole*> pileSymboles;
        stack<Etat*> pileEtats;       
        
};
