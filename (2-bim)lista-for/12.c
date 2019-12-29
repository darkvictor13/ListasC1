#include <stdio.h>

void printaChar (int n) {
  char i, j;
  for (i = j = 0; i < n; i++, j++) {
    printf("%c", 'a' + j);
  }
}

void printaEspaco (int n) {
  for (int i = 1; i <= n; i++) {
    printf("%c", ' ');
  }
}

int main () {
  int num_linhas, count_p, count_n;
  scanf("%d", &num_linhas);
  count_p = 1;
  count_n = num_linhas - 1;
  for (int i = 1; i <= num_linhas; count_n--, count_p++, i++){
    printaEspaco(count_n);
    printaChar(count_p);
    printf("\n");
  }
  return 0;
}
