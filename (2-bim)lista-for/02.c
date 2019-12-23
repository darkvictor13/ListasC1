#include <stdio.h>

void printAlfabetoInv() {
  for (int a = 'z'; a >= 'a'; a--)
    printf ("%c\n",a);
}

int main () {
  printAlfabetoInv();
  return 0;
}
