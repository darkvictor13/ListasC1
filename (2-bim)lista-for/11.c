#include <stdio.h>

void printaChar(int n) {
  for (char i = 1; i <= n; i++) {
    printf("%c", 'a');
  }
}

void printaEspaco (int n) {
  for (char i = 1; i <= n; i++) {
    printf("%c", ' ');
  }
}

int main () {
  int num_linhas, count_p,count_n, i;
  scanf("%d",&num_linhas);
  count_p = 1;
  count_n = num_linhas-1;
  for (i = 1; i <= num_linhas; i++){
    printaEspaco (count_n);
    count_n--;//pode ser colocado dentro do for
    printaChar (count_p);
    count_p++;//so coloquei aki para ficar mais facil de entender
    printf("\n");
  }
  return 0;
}
