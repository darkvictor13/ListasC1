#include <stdio.h>

#define MAXT 51

void permuta2A2 (char *dest, char *src) {
  int i;
  for(i = 0; src[i] && src[i + 1]; i += 2) {
    dest[i] = src[i + 1];
    dest[i + 1] = src[i];
  }
  dest[i] = src[i];
  if (src[i] != '\0') {
    dest[i + 1] = '\0';
  }
}

int main () {
  char src[MAXT], permutada[MAXT];
  int casos;
  for(scanf("%d%*c", &casos); casos > 0; casos--) {
    scanf("%[^\n]%*c", src);
    permuta2A2(permutada, src);
    printf("[%s]\n", permutada);
  }
  return 0;
}
