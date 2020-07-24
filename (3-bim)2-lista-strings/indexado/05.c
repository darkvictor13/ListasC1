#include <stdio.h>
#include <string.h>

#define MAXT 100

void shiftRight (char dest[], char org[]) {
  int i;
  for(i = 1; org[i]; i++) {
    dest[i - 1] = org[i];
  }
  dest[i - 1] = org[0];
  dest[i] = '\0';
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
