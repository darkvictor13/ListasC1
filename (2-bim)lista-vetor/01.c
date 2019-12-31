#include <stdio.h>

#define MAXT 100

void lerVet(int v[], int t) {
  int i;
  for (i = 0 ; i < t; i++) {
    scanf("%d", &v[i]);
  }
}

void lerVetPont(int *v, int t) {
  int *fim = (v + t);
  for (; v < fim; v++) {
    scanf("%d", v);
  }
}

int somaVet(int v[], int t) {
  int i, soma;
  for (i = soma = 0 ; i < t; i++) {
    soma += v[i];
  }
  return soma;
}

int somaVetPont (int *v, int t) {
  int soma, *fim = (v + t);
  for (soma = 0; v < fim; v++) {
    soma += *v;
  }
  return soma;
}

int main () {
  int vet[MAXT], tam;

  scanf("%d", &tam);
  lerVetPont(vet, tam);
  printf("%d\n", somaVetPont(vet, tam));
  return 0;
}