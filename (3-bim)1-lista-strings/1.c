#include <stdio.h>
#include <string.h>

void fazContagem(char ref[], char in[], int vet[], int t) {
  int i, j, count;
  for (i = 0; ref[i]; i++) {
    for (j = count = 0; in[j]; j++) {
      if (in[j] == ref[i]) {
        count++;
      }
    }
    vet[i] = count;
  }
}

void printDados(char *ref, int *v, int t) {
  for (int i = 0; i < t; i++) {
    printf("#%c = %d\n", ref[i], v[i]);
  }
}

int main () {
  char referencia[11], entrada[51];
  int conta_referencia[10], tam;

  printf("Entre com a string de referencia sem repetir letras\naki -> ");
  scanf("%[^\n]%*c", referencia);
  tam = strlen(referencia);

  printf("String a ser processada : ");
  scanf("%[^\n]%*c", entrada);
  while (strcmp(entrada, "fim")) {
    fazContagem(referencia, entrada, conta_referencia, tam);
    printDados(referencia, conta_referencia, tam);
    printf("String a ser processada : ");
    scanf("%[^\n]%*c", entrada);
  }
  return 0;
}