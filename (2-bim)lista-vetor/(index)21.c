#include <stdio.h>

#define MAXT 100

void lerVet(int v[], int t) {
  int i;
  for (i = 0 ; i < t; i++) {
    scanf("%d", &v[i]);
  }
}

void printVet(int v[], int t) {
  for (int i = 0; i < t; i++) {
    printf("%d\n", v[i]);
  }
}

int ehPalindromo(int v[], int t) {
  int i, j;//i comeca no inicio do vet, j comeca no final do vet, eles se encontram no meio

  for (i = 0, j = (t - 1); i < j; i++, j--) {
    if (v[i] != v[j]) {
      return 0;
    }
  }
  return 1;
}

int main () {
  int vet[MAXT], tam;

  scanf("%d", &tam);
  while (tam > 0) {
    lerVet(vet, tam);
    if (ehPalindromo(vet, tam)) {
      printf("Sim\n");
    }else {
      printf("Nao\n");
    }
    scanf("%d", &tam);
  }
  return 0;
}