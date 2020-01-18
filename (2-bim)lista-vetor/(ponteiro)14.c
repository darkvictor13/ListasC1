#include <stdio.h>

#define MAXT 100

void le2VetsAoMesmoTempo(int *v1, int *v2, int *t) {
  int *fim;
  scanf("%d", t);
  
  for (fim = (v1 + (*t)); v1 < fim; v1++, v2++) {
    scanf("%d %d", v1, v2);
  }
}

long long int somaDosProdutos(int *v1, int *v2, int t) {
  int *fim, soma;
  for (fim = (v1 + t), soma = 0; v1 < fim; v1++, v2++) {
    soma += ((*v1) * (*v2));
  }
  return soma;
}

int main () {
  int vet1[MAXT], vet2[MAXT], tam;

  le2VetsAoMesmoTempo(vet1, vet2, &tam);
  printf("%lld\n", somaDosProdutos(vet1, vet2, tam));

  return 0;
}