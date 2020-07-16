#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXT 100

void strAlternada (char dest[], char src[]) {
  int i, count;
  for(i = count = 0; src[i]; i++) {
    if (isalpha(src[i])) {
      if(count % 2) {
        dest[i] = tolower(src[i]);
      }else {
        dest[i] = toupper(src[i]);
      }
      count++;
    }else {
      dest[i] = src[i];
    }
  } 
  dest[i] = 0;
}

int main () {
  int casos;
  char entrada[MAXT], saida[MAXT];
  for(scanf("%d%*c", &casos); casos > 0; casos--) {
    scanf("%[^\n]%*c", entrada);
    strAlternada(saida, entrada);
    printf("%s\n", saida);
  }
  return 0;
}
