#include <stdio.h>

void printaLinhaComPadrao(int n) {
  char i, j;//usando char para economizar 3bytes de memoria
  for (i = j = 0; i < n; i++) {//pode colocar o j++ dentro do for
    printf("%c", 'a' + j);
    j++;
  }
}

int main () {
  int num_linhas, aux;
  char i;
  scanf ("%d", &num_linhas);
    for (i = aux = 1; i <= num_linhas; i++, aux++) {
      if (aux == 4) {
        aux = 1;
      }
      printaLinhaComPadrao(aux);
      printf("\n");
    }
  return 0;
}
