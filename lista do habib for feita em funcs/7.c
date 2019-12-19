#include <stdio.h>

void todas_consoantes (int n) {
  for (int i = 'b'; i < n + 'b'; i++) {
    if (i == 'e' || i == 'i' || i == 'o' || i == 'u') {
      i ++;
      printf("%c\n", i);
    }else
    printf("%c\n", i);
    }
}

int main () {
  int n;
  scanf ("%d",&n);
  todas_consoantes (n);
  return 0;
}
