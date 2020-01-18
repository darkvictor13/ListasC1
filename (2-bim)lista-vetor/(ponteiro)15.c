#include <stdio.h>

#define MAXT 100

void le2VetsAoMesmoTempo(int *v1, int *v2, int *t) {
  int *fim;
  scanf("%d", t);
  
  for (fim = (v1 + (*t)); v1 < fim; v1++, v2++) {
    scanf("%d %d", v1, v2);
  }
}

void junta2Vets(int *v1, int *v2, int *t1,int t2) {
  int *fim = (v2 + t2);
  for (v1 += t2; v2 < fim; v1++, v2++) {//(v1 += t) eh igual a v1 = (v1 + t)
    *v1 = *v2;
  }
  *t1 = (2 * t2);
}

void printVet(int v[], int t) {
  for (int *fim = (v + t); v < fim; v++) {
    printf("%d\n", *v);
  }
}

int main () {
  int vet1[MAXT], vet2[MAXT], tam1, tam2;

  le2VetsAoMesmoTempo(vet1, vet2, &tam2);
  junta2Vets(vet1, vet2, &tam1, tam2);
  printVet(vet1, tam1);

  return 0;
}