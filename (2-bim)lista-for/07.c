#include <stdio.h>

void algumasConsoantes(int n) {
  for (char i = 'b'; i < n + 'b'; i++) {
    if (i == 'e' || i == 'i' || i == 'o' || i == 'u') {
      i++;
      printf("%c\n", i);
    }else
    printf("%c\n", i);
    }
}

int main () {
  int n;
  scanf("%d", &n);
  algumasConsoantes(n);
  return 0;
}
