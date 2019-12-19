#include <stdio.h>

void alfabeto_inv (int n) {
  for (int i = 'z'; i > 'z'- n; i--)
    printf ("%c\n",i);
}

void estudei_ponteiro (int * n) {
  scanf("%d", n);
}

int main () {
  int x;
  estudei_ponteiro (&x);
  alfabeto_inv (x);
  return 0;
}
