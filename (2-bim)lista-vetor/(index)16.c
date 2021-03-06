#include <stdio.h>

#define MAXT 100

void ler2Vets(int v1[], int v2[], int *t) {
  int i;

  scanf("%d", t);

  for (i = 0; i < (*t); i++) {
    scanf("%d %d", &v1[i], &v2[i]);
  }
}

void intercalaVets(int v1[], int v2[], int r[], int t) {
  int i;

  for(i = 0; i < t; i++) {
    r[(i * 2)] = v1[i];
    r[(i * 2) + 1] = v2[i];
  }
}

void printVet(int v[], int t) {
  for (int i = 0; i < t; i++) {
    printf("%d\n", v[i]);
  }
}

int main () {
  int src1[MAXT], src2[MAXT], resposta[MAXT * 2], tam_v, tam_r;

  ler2Vets(src1, src2, &tam_v);
  tam_r = tam_v * 2;
  intercalaVets(src1, src2, resposta, tam_v);
  printVet(resposta, tam_r);

  return 0;
}