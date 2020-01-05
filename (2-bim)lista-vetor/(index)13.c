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

int numApareceNoVet(int v[], int t, int n) {
  int i;
  for (i = 0; i < t; i++) {
    if(v[i] == n) {
      return 1;
    }
  }
  return 0;
}

void eliminaRepetidos(int v2[],int *t2, int v1[], int t1) {
  int i, i_aux;

  v2[0] = v1[0];

  for (i = i_aux = 1; i < t1; i++) {
    if (!numApareceNoVet(v2, i_aux, v1[i])) {
      v2[i_aux] = v1[i];
      i_aux++;
    }
  }
  *t2 = i_aux;
}

int main () {
  int v1[MAXT], t1, sem_repeticao[MAXT], t_aux;

  lerVetCompleto(v1, &t1);
  eliminaRepetidos(sem_repeticao, &t_aux, v1, t1);
  printVet(sem_repeticao, t_aux);

  return 0;
}