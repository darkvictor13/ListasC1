#include <stdio.h>

#define MAXT 100

void lerVetCompleto(int v[], int *t) {
  int i;
  scanf("%d", t);
  for(i = 0; i < (*t); i++) {
    scanf("%d", &v[i]);
  }
}

void printVet(int v[], int t) {
  for (int i = 0; i < t; i++) {
    printf("%d\n", v[i]);
  }
}

void excluiPrimeiroEUltimo(int v2[], int v1[], int t) {
  int i;
  for (i = 1; i < (t - 1); i++) {
    v2[i - 1] = v1[i];
  }
}

int main () {
  int entrada[MAXT], tam, tam_aux;

  lerVetCompleto(entrada, &tam);

  tam_aux = tam - 2;
  int sem_maior_e_menor[tam_aux];
  
  excluiPrimeiroEUltimo(sem_maior_e_menor, entrada, tam);
  printVet(sem_maior_e_menor, tam_aux);

  return 0;
}

/*se quiser pode usar esse main

int main () {
  int v_entrada[MAXT], tam, v_aux[MAXT],tam_aux;

  lerVetCompleto(v_entrada, &tam);

  tam_aux = tam - 2;
  
  excluiPrimeiroEUltimo(v_aux, entrada, tam);
  printVet(v_aux, tam_aux);

  return 0;
}*/