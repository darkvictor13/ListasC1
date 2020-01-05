#include <stdio.h>

#define MAXT 100

void troca(int *a, int *b) {
  int aux = *a;
  *a = *b;
  *b = aux;
}

void lerVet(int v[], int t) {
  int i;
  for (i = 0 ; i < t; i++) {
    scanf("%d", &v[i]);
  }
}

int maiorIndex(int v[], int t) {
  int i, maior;
  for(maior = 0, i = 1; i < t; i++) {
    if (v[maior] < v[i]) {
      maior = i;
    }
  }
  return maior;
}

void copiaVet(int dest[], int org[], int t) {
  int i;

  for(i = 0; i < t; i++) {
    dest[i] = org[i];
  }
}

void trocaMaiorComPrimeiro(int v[], int t) {
  int aux;
  aux = maiorIndex(v, t);
  troca(&v[aux], &v[0]);
  /*pode ser reescrito em 1 linha
  troca(v[maiorIndex(v, t)], v[0]);*/
}

void printVet(int v[], int t) {
  for (int i = 0; i < t; i++) {
    printf("%d\n", v[i]);
  }
}

int main () {
  int entrada[MAXT], trocado[MAXT], tam;

  scanf("%d", &tam);
  lerVet(entrada, tam);
  copiaVet(trocado, entrada, tam);
  trocaMaiorComPrimeiro(trocado, tam);
  printVet(trocado, tam);

  return 0;
}