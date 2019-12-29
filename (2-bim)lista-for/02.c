#include <stdio.h>

void printAlfabetoInv() {
  for (char i = 'z'; i >= 'a'; i--)
    printf ("%c\n", i);
}

int main () {
  printAlfabetoInv();
  return 0;
}
