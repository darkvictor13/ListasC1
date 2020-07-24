#include <stdio.h>
#include <string.h>

#define MAXT 100  

void inverteStr (char dest[], char src[]) {
  int i;
  int ultimo = (strlen(src) - 1);

  for(i = 0; i <= ultimo; i++) {
    dest[i] = src[ultimo - i];
  }
  dest[ultimo + 1] = '\0';
}

int main () {
  int casos;
  char src[MAXT], invertida[MAXT];
  for(scanf("%d%*c", &casos); casos > 0; casos--) {
    scanf("%[^\n]%*c", src);
    inverteStr(invertida, src);
    printf("[%s]\n", invertida);
  }
  return 0;
}
