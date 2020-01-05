#include <stdio.h>

#define MAXT 100

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

int main () {
  int vet[MAXT], tam, aux;

  scanf("%d", &tam);
  lerVet(vet, tam);
  aux = maiorIndex(vet, tam);
  printf("%d\n", aux);

  return 0;
}