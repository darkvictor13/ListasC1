#include <stdio.h>

#define MAXT 100

void lerVet(int *v, int t) {
  int *fim = (v + t);
  for (; v < fim; v++) {
    scanf("%d", v);
  }
}

int oProxEhMaior(int *v,int t) {
  int count,*final = (v + t - 2);
  //final aponta para o penultimo elemento valido do vetor 
  for (count = 0; v <= final; v++) {
    if (*v < *(v + 1)) {
      count++;
    }
  }
  return count;
}

int main () {
  int vet[MAXT], tam, qnt_sucessores_maiores;

  scanf("%d", &tam);
  lerVet(vet, tam);
  qnt_sucessores_maiores = oProxEhMaior(vet, tam);
  printf("%d\n", qnt_sucessores_maiores);
  //pode-se eliminar a variavel "qnt..." fazendo -> printf("%d\n", oProxEhMaior(vet, tam));
  return 0;
}