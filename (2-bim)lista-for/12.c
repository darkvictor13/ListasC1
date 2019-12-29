#include <stdio.h>

void printa_linha (int n) {
  char i, j;
  for (i = j = 0; i < n; i++, j++) {
    printf("%c", 'a' + j);
  }
}

void printa_espaco (int n) {
  for (int i = 1; i <= n; i++) {
    printf("%c", ' ');
  }
}

int main () {
  int x,count_p,count_n;
  scanf("%d",&x);
  count_p = 1;
  count_n = x-1;
  for (int i = 1;i <= x;count_p++,count_n--,i++){
    printa_espaco (count_n);
    printa_linha (count_p);
    printf("\n");
  }
  return 0;
}
