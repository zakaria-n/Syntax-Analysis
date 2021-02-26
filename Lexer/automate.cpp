#include "automate.h"

void Automate::decalage(Symbole * s, Etat * e) {
    pileSymboles.push(s);
    pileEtats.push(e);
    if(s->estTerminal()) {
        lexer->Avancer();
    }
}

void Automate::reduction(int n, Symbole * s) {
    for(int i = 0 ; i<n ; i++) {
        delete(pileEtats.top());
        pileEtats.pop();
    }
    pileEtats.top()->transition(*this,s);
}