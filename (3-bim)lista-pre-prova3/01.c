#include <stdio.h>

void ler2Vet (int v1[], int v2[], int tam) {
  for(int i = 0; i < tam; i++) {
    scanf("%d %d", v1 + i, v2 + i);
  }
}

int numApareceNoVet(int num, int v[], int t) {
  for(int i = 0; i < t; i++) {
    if (v[i] == num) {
      return 1;
    }
  }
  return 0;
}

int vetsSaoIguais (int v1[], int v2[], int t) {
  for(int i = 0; i < t; i++) {
    if (!numApareceNoVet(v1[i], v2, t)) {
      return 0;
    }
  }
  return 1;
}

int main () {
  int tam;
  scanf("%d", &tam);
  int vet1[tam], vet2[tam];
  ler2Vet(vet1, vet2, tam);
  if(vetsSaoIguais(vet1, vet2, tam)) {
    printf("Iguais\n");
  }else {
  	printf("Diferentes\n");
  }
  return 0;
}
