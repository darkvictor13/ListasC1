#include <stdio.h>

#define MAXT 100

void lerVetCompleto(int v[], int *t) {
  int i;
  scanf("%d", t);
  for(i = 0; i < (*t); i++) {
    scanf("%d", &v[i]);
  }
}

void une2Vets(int v1[], int t1, int v2[], int t2, int r[], int *t_r) {
  int i, j;

  for(i = 0; i < t2; i++) {
    r[i] = v2[i];
  }
  for (j = 0; j < t1; j++, i++) {
    r[i] = v1[j];
  }
}

void printVet(int v[], int t) {
  for (int i = 0; i < t; i++) {
    printf("%d\n", v[i]);
  }
}

int main () {
  int src1[MAXT], src2[MAXT], resposta[MAXT * 2], tam1, tam2, tam_r;

  lerVetCompleto(src1, &tam1);
  lerVetCompleto(src2, &tam2);
  tam_r = tam1 + tam2;
  une2Vets(src1, tam1, src2, tam2, resposta, &tam_r);
  printVet(resposta, tam_r);

  return 0;
}