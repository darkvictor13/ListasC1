#include <stdio.h>

int printa_linha (int b) {
  int j = 0;
  for (int i = 1; i <= b; i++) {
    printf("%c", 'a' + j);
    j ++;
  }
  return 0;
}

int main () {
  int x,aux = 1;
  scanf ("%d",&x);
    for (int i = 1;i <= x;i++,aux++) {
      if (aux > 3) {
        aux -= 3;
      }
      printa_linha (aux);
      printf("\n");
    }
  return 0;
}
