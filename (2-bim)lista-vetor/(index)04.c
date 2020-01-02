#include <stdio.h>

#define MAXT 100

void lerVet(int v[], int t) {
  int i;
  for (i = 0 ; i < t; i++) {
    scanf("%d", &v[i]);
  }
}

int oProxEhMaior(int v[], int t) {
  int i, count;
  for(i = count = 0; i < (t - 1); i++) {
    if (v[i] < v[i + 1]) {
      count++;
    }
  }
  return count;
}

int main () {
  int vet[MAXT], tam, qnt_sucessores_maiores;

  scanf("%d", &tam);
  lerVet(vet, tam);
  qnt_sucessores_maiores = oProxEhMaior(vet, tam);
  printf("%d\n", qnt_sucessores_maiores);
  //pode-se eliminar a variavel "qnt..." fazendo -> printf("%d\n", oProxEhMaior(vet, tam));
  return 0;
}