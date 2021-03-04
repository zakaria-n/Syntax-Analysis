#include "automate.h"
#include "etat.h"
#include <iostream>

using namespace std;

Automate::Automate(string chaine) {
    Etat0 * etat0 = new Etat0();
    pileEtats.push(etat0);
    this->lexer = new Lexer(chaine);
}

void Automate::run() {
    bool end = false;
    string chaine = this->lexer.flux;
    while(!end){
        Symbole * s = lexer->Consulter();
        end = pileEtats.top->transition(*this,s);
    }
    cout << "Valeur de l'expression" << chaine << ": ";
    cout << pileSymboles.top->valeur << endl;
}

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