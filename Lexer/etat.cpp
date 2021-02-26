#include "etat.h"
#include <iostream>

Etat::Etat() {}
Etat::~Etat() {}
Etat::Etat(string s) { name = s; }

Etat0::Etat0() : Etat("E0") {}

Etat1::Etat1() : Etat("E1") {}

Etat2::Etat2() : Etat("E2") {}

Etat3::Etat3() : Etat("E3") {}

Etat4::Etat4() : Etat("E4") {}

Etat5::Etat5() : Etat("E5") {}

Etat6::Etat6() : Etat("E6") {}

Etat7::Etat7() : Etat("E7") {}

Etat8::Etat8() : Etat("E8") {}

Etat9::Etat9() : Etat("E9") {}

bool Etat0::transition(Automate &automate, Symbole *symbole)
{
    switch (*symbole)
    {
    case INT:
        automate.decalage(symbole, new Etat3);
        break;
    case OPENPAR:
        automate.decalage(symbole, new Etat2);
        break;
    case EXPR:
        automate.decalage(symbole, new Etat1);
        break;
    default:
        automate.decalage(new symbole(ERREUR), NULL);
        break;
    }
    return false;
}

bool Etat1::transition(Automate &automate, Symbole *symbole)
{
    switch (*symbole)
    {
    case PLUS:
        automate.decalage(symbole, new Etat4);
        break;
    case MULT:
        automate.decalage(symbole, new Etat5);
        break;
    case FIN:
        return true;
        break;
    default:
        automate.decalage(new symbole(ERREUR), NULL);
        break;
    }
    return false;
}

bool Etat2::transition(Automate &automate, Symbole *symbole)
{
    switch (*symbole)
    {
    case INT:
        automate.decalage(symbole, new Etat3);
        break;
    case OPENPAR:
        automate.decalage(symbole, new Etat2);
        break;
    case EXPR:
        automate.decalage(symbole, new Etat6);
        break;
    default:
        automate.decalage(new symbole(ERREUR), NULL);
        break;
    }
    return false;
}

bool Etat3::transition(Automate &automate, Symbole *symbole)
{
    switch (*symbole)
    {
    case PLUS:
        Entier * e = (Entier*) automate.popSymbol();
        automate.reduction(1, new Entier(e));
        break;
    case MULT:
        Entier * e = (Entier*) automate.popSymbol();
        automate.reduction(1, new Entier(e));
        break;
    case CLOSEPAR:
        Entier * e = (Entier*) automate.popSymbol();
        automate.reduction(1, new Entier(e));
        break;
    case FIN:
        Entier * e = (Entier*) automate.popSymbol();
        automate.reduction(1, new Entier(e));
        break;
    default:
        automate.decalage(new symbole(ERREUR), NULL);
        break;
    }
    return false;
}

bool Etat4::transition(Automate &automate, Symbole *symbole)
{
    switch (*symbole)
    {
    case INT:
        automate.decalage(symbole, new Etat3);
        break;
    case OPENPAR:
        automate.decalage(symbole, new Etat2);
        break;
    case EXPR:
        automate.decalage(symbole, new Etat7);
        break;
    default:
        automate.decalage(new symbole(ERREUR), NULL);
        break;
    }
}

bool Etat5::transition(Automate &automate, Symbole *symbole)
{
    switch (*symbole)
    {
    case INT:
        automate.decalage(symbole, new Etat3);
        break;
    case OPENPAR:
        automate.decalage(symbole, new Etat2);
        break;
    case EXPR:
        automate.decalage(symbole, new Etat8);
        break;
    default:
        automate.decalage(new symbole(ERREUR), NULL);
        break;
    }
}

bool Etat6::transition(Automate &automate, Symbole *symbole)
{
}

bool Etat7::transition(Automate &automate, Symbole *symbole)
{
}

bool Etat8::transition(Automate &automate, Symbole *symbole)
{
}

bool Etat9::transition(Automate &automate, Symbole *symbole)
{
}
