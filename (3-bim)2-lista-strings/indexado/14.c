#include <stdio.h>

#define MAXT 100

void eliminaRepetidos (char *dest, char *src) {
  int i, j;
  dest[0] = src[0];
  for(i = j = 0; src[i]; i++) {
    if (src[i] != src[i - 1]) {
      dest[j++] = src[i];
    }
  }
  dest[j] = 0;
}

int main () {
  int casos;
  char src[MAXT];
  char sem_repetidos[MAXT];
  for(scanf("%d%*c", &casos); casos > 0; casos--) {
    scanf("%[^\n]%*c", src);
    eliminaRepetidos(sem_repetidos, src);
    printf("[%s]\n", sem_repetidos);
  }
  return 0;
}
