#include <stdio.h>

#define MAXT 100

void troca(int *a, int *b) {
  int aux = *a;
  *a = *b;
  *b = aux;
}

void copiaVet(int *dest, int *org, int t) {
  for (int *fim = (org + t); org < fim; org++, dest++) {
    *dest = *org;
  }
}

void printVet(int v[], int t) {
  for (int *fim = (v + t); v < fim; v++) {
    printf("%d\n", *v);
  }
}

void lerVetCompleto(int *v, int *t) {
  scanf("%d", t);
  for (int *fim = (v + *t); v < fim; v++) {
    scanf("%d", v);
  }
}

int * achaLocalDoMenor(int *v, int t) {
  int *fim = (v + t), *menor = v;

  for (v++; v < fim; v++) {
    if (*v < *menor) {
      menor = v;
    }
  }
  return menor;
}

void criaVetOrdenado (int *dest, int *org, int t_o, int *t_d) {
  copiaVet(dest, org, t_o);
  *t_d = t_o;
  for (;t_o > 2; t_o--) {
    troca(achaLocalDoMenor(dest, t_o), (dest + t_o - 1));
  }
}

int main () {
  int vet[MAXT], resp[MAXT], tam_v, tam_r;

  lerVetCompleto(vet, &tam_v);
  criaVetOrdenado(resp, vet, tam_v, &tam_r);
  printVet(resp, tam_r);

  return 0;
}
