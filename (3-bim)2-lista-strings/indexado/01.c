#include <stdio.h>

#define MAXT 100

void preencheStr (char str[], int t, char c) {
  int i;
  for (i = 0; i < t; i++) {
    str[i] = c;
  }
  str[i] = '\0';
}

int main () {
  int casos, num;
  char caracter;
  char str[MAXT];
  for(scanf("%d", &casos); casos > 0; casos--) {
    scanf("%d %c", &num, &caracter);
    preencheStr(str, num, caracter);
    printf("%s\n", str);
  }
  return 0;
}
