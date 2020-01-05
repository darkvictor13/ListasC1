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

int maiorIndex(int v[], int t) {
  int i, maior;
  for(maior = 0, i = 1; i < t; i++) {
    if (v[maior] < v[i]) {
      maior = i;
    }
  }
  return maior;
}

void excluiMaior(int v2[], int v1[], int t) {
  int maior, i;
  maior = maiorIndex(v1, t);

  for (i = 0; i < maior; i++) {
    v2[i] = v1[i];
  }
  i++;//pode ser colocado na inicializacao do for
  for (; i < t; i++) {
    v2[i - 1] = v1[i];
  }
}

int main () {
  int entrada[MAXT], tam;

  lerVetCompleto(entrada, &tam);

  int sem_maior[tam - 1];//criando um vetor para armazenar todos os numeros menos o maior

  excluiMaior(sem_maior, entrada, tam);
  printVet(sem_maior, (tam - 1));

  return 0;
}

/*main um pouco mais normal
int main () {
  int entrada[MAXT], sem_maior[MAXT], tam_e, tam_s;

  lerVetCompleto(entrada, &tam_e);
  tam_s = tam_e - 1;
  excluiMaior(sem_maior, entrada, tam_e);
  printVet(sem_maior, tam_s);

  return 0;
}*/