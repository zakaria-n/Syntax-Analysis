#include <iostream>
#include "lexer.h"
#include "automate.h"

int main(void) {
   //string chaine("(1+34)*123");
   string chaine;
   cout << "Veuillez saisir la chaîne à analyser:" << endl;
   cin >> chaine;
   Automate *automate = new Automate(chaine);
   automate->run();
   
   return 0;
}

