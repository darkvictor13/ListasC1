#include <stdio.h>

#define MAXT 100

void lerVetCompleto(int *v, int *t) {
  scanf("%d", t);
  for (int *fim = (v + *t); v < fim; v++) {
    scanf("%d", v);
  }
}

void printVet(int v[], int t) {
  for (int *fim = (v + t); v < fim; v++) {
    printf("%d\n", *v);
  }
}

void excluiPrimeiroEUltimo(int *dest, int *org, int t_o) {
  int *fim = (org + t_o - 1);
  for (org++; org < fim; org++, dest++) {
    *dest = *org;
  }
}

int main () {
  int vet[MAXT], tam_v, tam_r;

  lerVetCompleto(vet, &tam_v);

  tam_r = tam_v - 2;
  int resposta[tam_r];//criei o vetor do tamanho q preciso
  excluiPrimeiroEUltimo(resposta, vet, tam_v);
  printVet(resposta, tam_r);

  return 0;
}