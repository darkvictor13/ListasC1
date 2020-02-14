#include <stdio.h>

#define MAXT 100

void lerVet(int v[], int t) {
  int i;
  for (i = 0 ; i < t; i++) {
    scanf("%d", &v[i]);
  }
}

void printVet(int v[], int t) {
  for (int i = 0; i < t; i++) {
    printf("%d\n", v[i]);
  }
}

int ehPrimo (int n) {
  int i;

  if (n < 2) return 0; 
  //1 nao eh numero primo

  for (i = 2; i < (n - 1); i++) {
    if (!(n % i)) {
      return 0;
    }
  }
  return 1;
}

void preencheVetComNPrimos(int v[], int N) {
  int i, num;

  for(i = 0, num = 1; i < N; num++) {
    if (ehPrimo(num)) {
      v[i] = num;
      i++;
    }
  }
}

int main () {
  int vet[MAXT],num_de_primos;
  
  printf("Entre com o tam do vet : ");
  scanf("%d", &num_de_primos);
  printf("==\n");
  while (num_de_primos > 0) {
    preencheVetComNPrimos(vet, num_de_primos);
    printVet(vet, num_de_primos);
    printf("==\nDenovo : ");
    scanf("%d", &num_de_primos);
    printf("==\n");
  }

  return 0;
}