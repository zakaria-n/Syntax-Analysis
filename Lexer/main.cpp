#include <iostream>
#include "lexer.h"
#include "automate.h"

int main(void) {
   //string chaine("(1+34)*123");
   string chaine;
   while(1)
   {
      cout << "Veuillez saisir la chaîne à analyser: (saisir :q pour quitter l'application)" << endl;
      cin >> chaine;
      if (chaine == ":q") break;
      Automate *automate = new Automate(chaine);
      automate->run();
   }
   
   return 0;
}

