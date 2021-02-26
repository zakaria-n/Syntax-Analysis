#include "lexer.h"
#include <stack>

class Etat;
class Automate {

    public :
        void lecture();
        void reduction(int n, Symbole * s);
        void decalage(Symbole * s, Etat * e);
    
    protected :
        // Attributs
        Lexer* lexer;
        stack<Symbole*> pileSymboles;
        stack<Etat*> pileEtats;       
        
};
