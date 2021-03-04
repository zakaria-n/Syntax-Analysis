#include <iostream>
#include "lexer.h"
#include "automate.h"

int main(void) {
   string chaine("((1+34)*123");

   Automate *automate = new Automate(chaine);
   automate->run();
   
   return 0;
}

