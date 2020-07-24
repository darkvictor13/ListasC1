#include <stdio.h>

#define MAXT 100

void fazPadrao (char str[], char c, int t) {
  int i, casos, count;
  for(casos = i = 0; casos < t; casos++) {
    for(count = 0; count <= casos; count++, i++) {
      str[i] = c;
    }
    str[i++] = ' ';
  }
  str[i - 1] = '\0';
}

int main () {
  int casos, t;
  char str[MAXT], c;

  for (scanf("%d", &casos); casos > 0; casos--) {
    scanf("%d %c", &t, &c);
    fazPadrao(str, c, t);
    printf("[%s]\n", str);
  }
  return 0;
}
