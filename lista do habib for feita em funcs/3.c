#include <stdio.h>

void printa_algumas_letras (int n) {
  for (int i = 'a'; i < 'a' + n; i++){
    printf("%c\n",i);
  }
}

void estudei_ponteiro (int * n) {
  scanf("%d", n);
}

int main () {
  int x;
  estudei_ponteiro (&x);
  printa_algumas_letras (x);
  return 0;
}
