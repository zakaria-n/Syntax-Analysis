#include <iostream>
#include "automate.h"
#include "etat.h"


using namespace std;

Automate::Automate(string chaine) {
    Etat0 * etat0 = new Etat0();
    pileEtats.push(etat0);
    this->lexer = new Lexer(chaine);
}

void Automate::run() {
    bool end = false;
    while(!end){
        this->affichePile();
        Symbole * s = lexer->Consulter();
        end = pileEtats.top()->transition(*this,s);
    }
    Expr * expr = (Expr*)(pileSymboles.top());
    cout << "Valeur de l'expression : ";
    cout << expr->getValeur() << endl;
}

void Automate::affichePile() {
	cout << "Pile des symboles : " << endl;
	stack<Symbole*> copy = pileSymboles;
	while(!copy.empty()){
	    copy.top()->Affiche();
	    cout << " ";
		copy.pop();
    }
    cout << endl << "Pile des états : " << endl;
    stack<Etat*> etats = pileEtats;
    while(!etats.empty()){
		cout << etats.top()->getName() << " ";
		etats.pop();
    }
    cout << endl << endl;
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
