#include <stdio.h>

#define MAXT 100

void lerVet(int *v, int t) {
  int *fim = (v + t);
  for (; v < fim; v++) {
    scanf("%d", v);
  }
}

int somaVet(int *v, int t) {
  int soma, *fim = (v + t);
  for (soma = 0; v < fim; v++) {
    soma += *v;
  }
  return soma;
}

int main () {
  int vet[MAXT], tam;

  scanf("%d", &tam);
  lerVet(vet, tam);
  printf("%d\n", somaVet(vet, tam));
  
  return 0;
}