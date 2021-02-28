#include "automate.h"
#include "etat.h"
#include <iostream>

using namespace std;

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

Symbole* Automate::popSymbol() {
    Symbole * sym = pileSymboles.top();
    if(!pileSymboles.empty()){
        pileSymboles.pop();
    }
    return sym;
}

void Automate::popAndDestroySymbol(){
    if(!pileSymboles.empty()){
        pileSymboles.pop();
    } else {
        cout << "EmptySymbolStack";
    }
}