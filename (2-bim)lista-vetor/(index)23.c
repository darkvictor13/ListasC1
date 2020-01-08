#include <stdio.h>
#include <math.h>

#define MAXT 100

void lerVetCompleto(int v[], int *t) {
  int i;
  scanf("%d", t);
  for(i = 0; i < (*t); i++) {
    scanf("%d", &v[i]);
  }
}

int somaTudoAntes(int v[], int index_analisado) {
  int i, soma;

  for(i = soma = 0; i < index_analisado; i++) {
    soma += v[i];
  }
  return soma;
}

int somaTudoDepois(int v[], int index_analisado, int t) {
  int i, soma;

  for (soma = 0, i = (index_analisado + 1); i < t; i++) {
    soma += v[i];
  }
  return soma;
}

int pontoDeEquilibrio(int v[], int tam) {
  int i, eq_positivo, eq_negativo;

  for(i = eq_positivo = 1; eq_positivo < 0; i++) {
    eq_positivo = somaTudoAntes(v, i) - somaTudoDepois(v, i, tam);
  }
  i--;
  eq_negativo = somaTudoAntes(v, (i - 1)) - somaTudoDepois(v, (i - 1), tam);

  if (eq_negativo > eq_positivo) {
    return (i - 1);
  }else {
    return i;
  }
}

int main () {
  int vet[MAXT], tam;

  lerVetCompleto(vet, &tam);
  while (tam > 0) {
    printf("%d", pontoDeEquilibrio(vet, tam));
    lerVetCompleto(vet, &tam);
  }

  return 0;
}