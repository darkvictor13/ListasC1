#include <stdio.h>

#define MAXT 100

void lerVet(int v[], int t) {
  int i;
  for (i = 0 ; i < t; i++) {
    scanf("%d", &v[i]);
  }
}

int somaVet(int v[], int t) {
  int i, soma;
  for (i = soma = 0 ; i < t; i++) {
    soma += v[i];
  }
  return soma;
}

int main () {
  int vet[MAXT], tam;

  scanf("%d", &tam);
  lerVet(vet, tam);
  printf("%d\n", somaVet(vet, tam));
  system("PAUSE");
  
  return 0;
}