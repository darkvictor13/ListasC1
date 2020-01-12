#include <stdio.h>

#define MAXT 100

void copiaVet(int *dest, int *org, int t) {
  for (int *fim = (org + t); org < fim; org++, dest++) {
    *dest = *org;
  }
}

void printVet(int v[], int t) {
  for (int *fim = (v + t); v < fim; v++) {
    printf("%d\n", *v);
  }
}

void lerVetCompleto(int *v, int *t) {
  scanf("%d", t);
  for (int *fim = (v + *t); v < fim; v++) {
    scanf("%d", v);
  }
}

void permuta2A2(int *dest, int *org, int t_o, int *t_d){
  int *acaba = (org + t_o - 2);
  *t_d = t_o;

  for (;org < acaba; org += 2, dest += 2) {
    *dest = *(org + 1);
    *(dest + 1) = *org;
  }
  if (t_o % 2) {
    *dest = *org;
  }else {
    *dest = *(org + 1);
    *(dest + 1) = *org;
  }
}

int main () {
  int vet[MAXT], resp[MAXT], tam_v, tam_r;

  lerVetCompleto(vet, &tam_v);
  permuta2A2(resp, vet, tam_v, &tam_r);
  printVet(resp, tam_r);
  
  return 0;
}