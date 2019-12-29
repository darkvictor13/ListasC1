#include <stdio.h>

void printaLinha(int n) {
  char i, j;//como so precisamos de numeros ate 255 um char ja resolve
  for (i = j = 1; i < n; i++, j++) {
    printf("%c", 'a' + j);
  }
}

int main () {
  int num_linhas;
  scanf ("%d", &num_linhas);
    for (int i = 1; i <= num_linhas; i++) {
      printaLinha(i);
      printf("\n");
    }
  return 0;
}
