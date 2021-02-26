#include "automate.h"

class Etat
{
public:
    Etat();
    Etat (string name);
    virtual ~Etat();
    void print() const;
    virtual bool transition(Automate & automate, Symbole * symbole) = 0;
    virtual int etat();
protected:
    string name;
};

class Etat0 : public Etat 
{
    public:
        Etat0();
        bool transition(Automate & automate, Symbole * symbole);
};

class Etat1 : public Etat 
{
    public: 
        Etat1();
        bool transition(Automate & automate, Symbole * symbole);
};

class Etat2 : public Etat 
{
    public:
        Etat2();
        bool transition(Automate & automate, Symbole * symbole);
};

class Etat3 : public Etat 
{
    public:
        Etat3();
        bool transition(Automate & automate, Symbole * symbole);
};

class Etat4 : public Etat 
{
    public:
        Etat4();
        bool transition(Automate & automate, Symbole * symbole);
};

class Etat5 : public Etat 
{
    public:
        Etat5();
        bool transition(Automate & automate, Symbole * symbole);
};

class Etat6 : public Etat 
{
    public:
        Etat6();
        bool transition(Automate & automate, Symbole * symbole);
};

class Etat7 : public Etat 
{
    public:
        Etat7();
        bool transition(Automate & automate, Symbole * symbole);
};

class Etat8 : public Etat 
{
    public:
        Etat8();
        bool transition(Automate & automate, Symbole * symbole);
};
class Etat9 : public Etat 
{
    public:
        Etat9();
        bool transition(Automate & automate, Symbole * symbole);
};