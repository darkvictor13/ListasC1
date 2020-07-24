#include <stdio.h>

#define MAXT 100

void shiftRight (char dest[], char org[]) {
  int i;
  for(i = 1; org[i]; i++) {
    dest[i] = org[i - 1];
  }
  dest[i] = '\0';
  dest[0] = org[i - 1];
}

int main () {
  int casos;
  char entrada[MAXT], saida[MAXT];
  for(scanf("%d%*c", &casos); casos > 0; casos--) {
    scanf("%[^\n]%*c", entrada);
    shiftRight(saida, entrada);
    printf("[%s]\n", saida);
  }
  return 0;
}
