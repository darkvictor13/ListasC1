#include <stdio.h>

#define MAXT 100

void lerVetCompleto(int v[], int *t) {
  int i;
  scanf("%d", t);
  for(i = 0; i < (*t); i++) {
    scanf("%d", &v[i]);
  }
}

void troca(int *a, int *b) {
  int aux = *a;
  *a = *b;
  *b = aux;
}

void copiaVet(int dest[], int org[], int t) {
  int i;

  for(i = 0; i < t; i++) {
    dest[i] = org[i];
  }
}

int maiorIndexMudaInicio(int v[], int inicio, int t) {
  int i, maior;
  for(maior = inicio, i = inicio + 1; i < t; i++) {
    if (v[maior] < v[i]) {
      maior = i;
    }
  }
  return maior;
}

void ordenaVet(int v[], int t) {
  int maior, i;
  for (i = 0; i < t; i++) {
    maior = maiorIndex(v, i, t);
    troca(&v[maior], &v[i]);
  }
  //foi usado selection sort, achando o maior
  //no arquivo do ponteiro vou achar o menor
}

void printVet(int v[], int t) {
  for (int i = 0; i < t; i++) {
    printf("%d\n", v[i]);
  }
}

int main () {
  int original[MAXT], ordenado[MAXT], tam;

  lerVetCompleto(original, &tam);
  copiaVet(ordenado, original, tam);
  ordenaVet(ordenado, tam);
  printVet(ordenado, tam);

  return 0;
}