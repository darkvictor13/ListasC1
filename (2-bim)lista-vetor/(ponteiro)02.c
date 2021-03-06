#include <stdio.h>

#define MAXT 100

void lerVet(int *v, int t) {
  int *fim = (v + t);
  for (; v < fim; v++) {
    scanf("%d", v);
  }
}

void printVetInv(int *v, int t) {
  int *ponteiro_dec = ((v + t) - 1);
  for (;ponteiro_dec >= v; ponteiro_dec--) {
    printf("%d\n", *ponteiro_dec);
  }
}

int main() {
  int vet[MAXT], tam;

  scanf("%d", &tam);
  lerVet(vet, tam);
  printVetInv(vet, tam);
  
  return 0;
}