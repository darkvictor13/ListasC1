#include <stdio.h>

void alfabetoInv(int n) {
  for (char i = 'z'; i > 'z'- n; i--) {
    printf ("%c\n", i);
  }
}

int main () {
  int x;
  scanf("%d", &x);
  alfabetoInv(x);
  return 0;
}
