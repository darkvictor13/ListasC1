#include <stdio.h>

void preencheStr (char str[], char x, int t) {

  for (char *p = (str + t); str < p; str++) {
    *str = x;
  }
  *str = 0;
}

int main () {
  char str[51], x;
  int tam, casos;

  for (scanf("%d", &casos); casos > 0; casos--) {
    scanf ("%d %c", &tam, &x);
    preencheStr(str, x, tam);
    printf("[%s]\n",  str);
  }
  return 0;
}
