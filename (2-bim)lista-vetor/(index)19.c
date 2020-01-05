#include <stdio.h>

#define MAXT 100

void lerVetCompleto(int v[], int *t) {
  int i;
  scanf("%d", t);
  for(i = 0; i < (*t); i++) {
    scanf("%d", &v[i]);
  }
}

int SomaDosDigitos(int n) {
  int soma = 0;

  while (n > 0) {
    soma += (n % 10);
    n /= 10;//n = n/10;
  }
  return soma; 
}

int somaEhPar(int n) {
  return !(SomaDosDigitos(n) % 2);
}

void printVet(int v[], int t) {
  for (int i = 0; i < t; i++) {
    printf("%d\n", v[i]);
  }
}

void separaOsSomaPar(int v1[], int *t1, int v2[], int *t2, int r[], int t_r) {
  int i, c1, c2;

  for (i = c1 = c2 = 0; i < t_r; i++) {
    if (somaEhPar(r[i])) {
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
  separaOsSomaPar(v1,&t1, v2, &t2, entrada, t_e);
  printf("Primeiro vetor\n");
  printVet(v1, t1);
  printf("\nSegundo vetor\n");
  printVet(v2, t2);

  return 0;
}

