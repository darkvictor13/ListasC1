#include <stdio.h>

void printAlfabeto () {
  for (int a = 'a'; a <= 'z'; a++)
    printf ("%c\n",a);
}

int main () {
  printAlfabeto();
  return 0;
}
