#include <stdio.h>

#define MAXT 100

void lerVet(int v[], int t) {
  int i;
  for (i = 0 ; i < t; i++) {
    scanf("%d", &v[i]);
  }
}

int anteriorEProximoPares(int v[], int t) {
  int i, n = 0;
  for (i = 1; i < (t - 1); i++) {
    if (!(v[i-1] % 2) && !(v[i+1] % 2)) {
    //if (((v[i-1] % 2) == 0) && ((v[i+1] % 2) == 0))
    //se o anterior (e) o sucessor divididos por 2 dão zero
      n++;
    }
  }
  return n;
}

int main () {
  int vet[MAXT], tam, resposta;

  scanf("%d", &tam);
  lerVet(vet, tam);
  resposta = anteriorEProximoPares(vet, tam);
  printf("%d\n", resposta);

  return 0;
}