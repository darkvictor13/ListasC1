#include <stdio.h>

#define MAXT 100

void lerVetCompleto(int v[], int *t) {
  int i;
  scanf("%d", t);
  for(i = 0; i < (*t); i++) {
    scanf("%d", &v[i]);
  }
}

void printVet(int v[], int t) {
  for (int i = 0; i < t; i++) {
    printf("%d\n", v[i]);
  }
}

void permutaDoisADois(int v2[], int v1[], int t) {
  int i;

  for(i = 0; i < t-2; i += 2) {
    v2[i] = v1[i + 1];
    v2[i + 1] = v1[i];
  }
  if (t % 2) {
    v2[i] = v1[i];
  }else {
    v2[i] = v1[i + 1];
    v2[i + 1] = v1[i];
  }
}

void copiaVet(int dest[], int org[], int t) {
  int i;

  for(i = 0; i < t; i++) {
    dest[i] = org[i];
  }
}

int main () {
  int entrada[MAXT], tam;

  lerVetCompleto(entrada, &tam);

  int permutado[tam];//pode criar o vetor antes com o tamanho maximo
  //mas isso aqui eh so para vc criar um vet com tamanho exato q precisa

  permutaDoisADois(permutado, entrada, tam);
  printVet(permutado, tam);

  return 0;
}