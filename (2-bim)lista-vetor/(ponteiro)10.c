#include <stdio.h>

#define MAXT 100

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

void excluiMaior(int *dest, int *org, int t_o) {
  int *excluir = achaLocalDoMaior(org, t_o);

  for (int *fim = (org + t_o); org < fim; org++) {
    if (org != excluir) {
      *dest = *org;
      dest++;//pode colocar esse (++) na linha de cima
    }
  }
}

int main () {
  int vet[MAXT], tam_v, tam_r;

  lerVetCompleto(vet, &tam_v);

  tam_r = tam_v - 1;
  int resposta[tam_r];//criei o vetor do tamanho q preciso

  excluiMaior(resposta, vet, tam_v);
  printVet(resposta, tam_r);

  return 0;
}