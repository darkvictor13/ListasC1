#include <stdio.h>

void print_alfabeto () {
  for (int a = 'a'; a <= 'z'; a++)
    printf ("%c\n",a);
}

int main () {
  print_alfabeto();
  return 0;
}
