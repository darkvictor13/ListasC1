#include <stdio.h>

#define MAXT 100

void ler2Vets(int v1[], int v2[], int *t) {
  int i;

  scanf("%d", t);

  for (i = 0; i < (*t); i++) {
    scanf("%d %d", &v1[i], &v2[i]);
  }
}

long long int somaDosProdutos (int v1[], int v2[], int t) {
  int soma = 0;
  for (int i = 0; i < t; i++) {
    soma += (v1[i] * v2[i]);
  }
  return soma;
}

int main () {
  int v1[MAXT], v2[MAXT], t;

  ler2Vets(v1, v2, &t);
  printf("%d\n", somaDosProdutos(v1, v2, t));

  return 0;
}