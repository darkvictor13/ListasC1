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

int achaAntecessorRepetido(int *inicio, int *fim, int num) {//l_num eh o local de memoria do numero q vou analisar
  for (;inicio < fim; inicio++) {
    if (*inicio == num) {
      return 1;
    }
  }
  return 0;
}

void eliminaRepetidos(int *dest, int *org, int *t_d, int t_o) {
  int *salva_inicio = dest, *fim = (org + t_o);

  *dest = *org;
  for (dest++, org++; org < fim; org++) {
    if (!achaAntecessorRepetido(salva_inicio, dest, *org)) {
      *dest = *org;
      dest++;
    }
  }
  *t_d = (dest - salva_inicio);
}

int main () {
  int vet[MAXT], resposta[MAXT],tam_v, tam_r;

  lerVetCompleto(vet, &tam_v);
  eliminaRepetidos(resposta, vet, &tam_r, tam_v);
  printVet(resposta, tam_r);

  return 0;
}