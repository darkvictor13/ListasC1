#include <stdio.h>

void printaLinha (int n) {
  for (char i = 1; i <= n; i++) {
    printf("%c", 'a');
  }
}

int main () {
  int num_linhas;
  scanf("%d", &num_linhas);
  for (int i = 1; i <= num_linhas; i++) {
    printaLinha(i);
    printf("\n");
  }
  return 0;
}
