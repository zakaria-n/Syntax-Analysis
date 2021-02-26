#include "automate.h"
#include "lexer.h"
#include "symbole.h"
class Etat
{
public:
    Etat (string name);
    virtual ~Etat();
    void print() const;
    virtual bool transition(Automate & automate, Symbole * symbole) = 0;
protected:
    string name;
};