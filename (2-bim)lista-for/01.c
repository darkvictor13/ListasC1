#include <stdio.h>

void printAlfabeto () {
  int i;
  for (i = 'a'; i <= 'z'; i++) {
    printf ("%c\n", i);
  }
}

int main () {
  printAlfabeto();
  return 0;
}
