#include <stdio.h>

#define MAXT 100

void lerVet(int v[], int t) {
  int i;
  for (i = 0 ; i < t; i++) {
    scanf("%d", &v[i]);
  }
}

void printVetInv(int v[], int t) {
  int i;//vai ser o index do ultimo
  for (i = (t - 1); i >= 0; i--) {
    printf("%d\n", v[i]);
  }
}

int main() {
  int vet[MAXT], tam;

  scanf("%d", &tam);
  lerVet(vet, tam);
  printVetInv(vet, tam);
  
  return 0;
}