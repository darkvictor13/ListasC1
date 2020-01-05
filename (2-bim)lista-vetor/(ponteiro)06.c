#include <stdio.h>

#define MAXT 100

void lerVetCompleto(int *v, int *t) {
  scanf("%d", t);
  for (int *fim = (v + *t); v < fim; v++) {
    scanf("%d", v);
  }
}

int maiorIndex(int *v, int t) {
  int *salva_inicio_vet = v;
  int *fim = (v + t);
  int *maior_endereco = v;

  for (v++; v < fim; v++) {
    if (*v > *maior_endereco) {
      maior_endereco = v;
    }
  }
  return (maior_endereco - salva_inicio_vet);
}

int main () {
  int vet[MAXT], tam;

  lerVetCompleto(vet, &tam);
  printf("%d\n", maiorIndex(vet, tam));

  return 0;
}