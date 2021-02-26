#include "lexer.h"
#include <stack>

class Etat;
class Automate {

    public :
        void lecture();
    
    protected :
        // Attributs
        Lexer lexer;
        stack<Symbole> pileSymboles;
        stack<Etat> pileEtats;

        // Méthodes
        void reduction(int n, Symbole * s);
        void decalage(Symbole * s, Etat * e);
        
}
