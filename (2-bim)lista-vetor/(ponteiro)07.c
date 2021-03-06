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

int * achaLocalDoMaior(int *v, int t) {
  int *fim = (v + t), *maior = v;
  for (v++; v < fim; v++) {
    if (*maior < *v) {
      maior = v;
    }
  }
  return maior;
}

void criaVetResposta(int *dest, int *org, int tam_o, int *tam_d) {
  copiaVet(dest, org, tam_o);
  *tam_d = tam_o;
  troca(achaLocalDoMaior(dest, (*tam_d)), dest);//dest == &dest[0]
}

int main () {
  int vet[MAXT], resp[MAXT], tam_v, tam_r;

  lerVetCompleto(vet, &tam_v);
  criaVetResposta(resp, vet, tam_v, &tam_r);
  printVet(resp, tam_r);

  return 0;
}