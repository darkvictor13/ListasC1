#include <stdio.h>

#define MAXT 100

void troca(int *a, int *b) {
  int aux = *a;
  *a = *b;
  *b = aux;
}

void lerVetPonteiroCompleto(int *v, int *t) {
  scanf("%d", t);
  for (int *fim = (v + *t); v < fim; v++) {
    scanf("%d", v);
  }
}