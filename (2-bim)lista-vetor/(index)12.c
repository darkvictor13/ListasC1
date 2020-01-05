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

void excluiImpares(int v2[], int *t2,int v1[], int t1) {
  int i,p;

  for(i = p = 0; i < t1; i++) {
    if (!(v1[i] % 2)) {//se v1 no indice i eh par
      v2[p] = v1[i];
      p++;
    }
  }
  *t2 = p;
}

int main () {
  int escaneado[MAXT], so_pares[MAXT], tam_in, tam_pares;

  lerVetCompleto(escaneado, &tam_in);
  excluiImpares(so_pares, &tam_pares, escaneado, tam_in);
  printVet(so_pares, tam_pares);

  return 0;
}