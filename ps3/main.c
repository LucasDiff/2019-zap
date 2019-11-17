#include <stdio.h>
#include <stdlib.h>
#include "hangman.h"
int main() {
char secret[16];
get_word(secret);
hangman(secret);
return 0;
}