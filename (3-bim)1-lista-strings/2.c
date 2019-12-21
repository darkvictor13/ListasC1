#include <stdio.h>
#include <string.h>

#define MAXT 51

void trocaChar(char *a, char *b) {
  char aux = *a;
  *a = *b;
  *b = aux;
}

int retornaIndexDoMenor(char *str) {
  int menor, i;

  for (i = 1, menor = 0; str[i]; i++) {
    if (str[menor] > str[i]) {
      menor = i;
    }
  }
  return menor;
}

void ordenaStr(char *dest, char *org) {
  int i;
  int menor;
  strcpy(dest, org);

  for (i = 0; dest[i + 1]; i++) {
    menor = retornaIndexDoMenor(dest + i);
    trocaChar (dest[i], dest[menor]);
  }
  dest[i + 1] = 0;
}

int main () {
  char entrada[MAXT];
  char ordenado[MAXT];

  scanf("%[^\n]%*c", entrada);

  while (strcmp(entrada, "fim")) {
    ordenaStr(ordenado, entrada);
    printf("[%s]\n", ordenado);
  }
  return 0;
}