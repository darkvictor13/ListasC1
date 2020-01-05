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

int EhPrimo (int n) {
  int i;

  if (n < 2) return 0; 

  for (i = 2; i < (n - 1); i++) {
    if (!(n % i)) {
      return 0;
    }
  }
  return 1;
}

void separaOsPrimos(int v1[], int *t1, int v2[], int *t2, int r[], int t_r) {
  int i, c1, c2;

  for (i = c1 = c2 = 0; i < t_r; i++) {
    if (EhPrimo(r[i])) {
      v1[c1] = r[i];
      c1++;
    }else {
      v2[c2] = r[i];
      c2++;
    }
  }
  *t1 = c1;
  *t2 = c2;
}

int main () {
  int v1[MAXT], v2[MAXT], entrada[MAXT], t1, t2, t_e;

  lerVetCompleto(entrada, &t_e);
  separaOsPrimos(v1,&t1, v2, &t2, entrada, t_e);
  printf("Primeiro vetor\n");
  printVet(v1, t1);
  printf("\nSegundo vetor\n");
  printVet(v2, t2);

  return 0;
}