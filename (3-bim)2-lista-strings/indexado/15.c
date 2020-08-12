#include <stdio.h>
#include <ctype.h>

#define MAXT 100

void comecaMaiusc (char *dest, char *src) {
  int i;
  dest[0] = toupper(src[0]);
  dest[1] = src[1];
  for(i = 2; src[i]; i++) {
    if(src[i - 1] == ' ') {
      dest[i] = toupper(src[i]);
    }else {
      dest[i] = src[i];
    }
  }
  dest[i] = 0;
}

int main () {
  int casos;
  char src[MAXT];
  char sem_repetidos[MAXT];
  for(scanf("%d%*c", &casos); casos > 0; casos--) {
    scanf("%[^\n]%*c", src);
    comecaMaiusc(sem_repetidos, src);
    printf("[%s]\n", sem_repetidos);
  }
  return 0;
}
