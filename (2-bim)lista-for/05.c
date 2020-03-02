#include <stdio.h>

void maiuscMinusc(int n) {
  char i;
  for (i = 'a'; i < 'a' + n; i++) {
    if (i % 2) {//(i % 2 == 1) ou seja i eh impar
      printf("%c\n", i);
    }else {
      printf("%c\n", i + 'A' - 'a');
    }
  }
}

int main () {
  int x;
  scanf("%d", &x);
  maiuscMinusc(x);
  return 0;
}
