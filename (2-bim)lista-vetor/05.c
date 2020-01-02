#include <stdio.h>

#define MAXT 100

void lerVet(int v[], int t) {
  int i;
  for (i = 0 ; i < t; i++) {
    scanf("%d", &v[i]);
  }
}

void lerVetPonteiro(int *v, int t) {
  int *fim = (v + t);
  for (; v < fim; v++) {
    scanf("%d", v);
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

int anteriorEProximoParesPonteiro(int v[], int t) {
  int n = 0, *fim = (v + t - 2);

  for(v++; v <= fim; v++) {
//incrementei o v antes do for para o primeiro valor nao entrar no if
    if(!*(v - 1) % 2 && !*(v + 1) % 2) {
      n++;
    }
  }
}

int main () {
  int vet[MAXT], tam, resposta;

  scanf("%d", &tam);
  lerVet(vet, tam);
  resposta = anteriorEProximoPares(vet, tam);
  printf("%d\n", resposta);

  return 0;
}