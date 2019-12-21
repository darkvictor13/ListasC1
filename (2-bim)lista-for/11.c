#include <stdio.h>

void printa_linha (int b) {
  for (int i = 1; i <= b; i++) {
    printf("%c", 'a');
  }
}

void printa_espaco (int b) {
  for (int i = 1; i <= b; i++) {
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
