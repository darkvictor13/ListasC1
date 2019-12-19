#include <stdio.h>

void print_alfabeto () {
  for (int a = 'z'; a >= 'a'; a--)
    printf ("%c\n",a);
}

int main () {
  print_alfabeto();
  return 0;
}
