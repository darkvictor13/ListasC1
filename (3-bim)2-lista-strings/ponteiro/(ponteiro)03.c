#include <stdio.h>

void fazPadrao (char *str, char x, int t) {
  int aux;

  for (int i = 0; i < t; i++) {
    for (aux = 0; aux <= i; aux++, str++) {
      *str = x;
    }
    *str = ' ';
    str++;
  }
  *(str - 1) = 0;
}

int main () {
  char str[50], c;
  int t, casos;

  for (scanf("%d", &casos); casos > 0; casos--) {
    scanf("%d %c", &t, &c);
    fazPadrao(str, c, t);
    printf("[%s]\n", str);
  }
  return 0;
}
