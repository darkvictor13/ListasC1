#include <stdio.h>

void printa_linha (int b) {
  int j = 0;
  for (int i = 1; i <= b; i++) {
    printf("%c", 'a' + j);
    j ++;
  }
}

int main () {
  int x;
  scanf ("%d",&x);
    for (int i = 1;i <= x;i++) {
      printa_linha (i);
      printf("\n");
    }
  return 0;
}
