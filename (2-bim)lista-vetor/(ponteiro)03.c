#include <stdio.h>

#define MAXT 100

void lerVet(int *v, int t) {
  int *fim = (v + t);
  for (; v < fim; v++) {
    scanf("%d", v);
  }
}

void inverteVet(int dest[], int org[], int t) {
  int *fim = (org + t - 1);
  for (;fim >= org; fim--, dest++) {
    *dest = *fim;
  }
}

void printVet(int v[], int t) {
  for (int *fim = (v + t); v < fim; v++) {
    printf("%d\n", *v);
  }
}

int main () {
  int entrada[MAXT], invertido[MAXT], tam;

  scanf("%d", &tam);
  lerVet(entrada, tam);
  inverteVet(invertido, entrada, tam);
  printVet(invertido, tam);

  return 0;
}