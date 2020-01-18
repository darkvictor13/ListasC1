#include <stdio.h>

#define MAXT 100

void lerVetCompleto(int *v, int *t) {
  scanf("%d", t);
  for (int *fim = (v + *t); v < fim; v++) {
    scanf("%d", v);
  }
}

void printVet(int v[], int t) {
  for (int *fim = (v + t); v < fim; v++) {
    printf("%d\n", *v);
  }
}

void excluiPares(int *dest, int *org, int *t_d, int t_o) {
  int *fim = (org + t_o), *salva_inicio_dest = dest;

  for (; org < fim; org++) {
    if (*org % 2) {//se for impar
      *dest = *org;
      dest++;
    }
  }
  *t_d = (dest - salva_inicio_dest);
}

int main () {
  int vet[MAXT], resposta[MAXT],tam_v, tam_r;

  lerVetCompleto(vet, &tam_v);
  excluiPares(resposta, vet, &tam_r, tam_v);
  printVet(resposta, tam_r);

  return 0;
}