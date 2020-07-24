#include <stdio.h>

#define maxt 51

void intercalaEm2Str(char dest1[],char dest2[],char org[]) {
  for (org++; *(org - 1) && *org; org += 2) {
    *(dest1++) = *(org - 1);
    *(dest2++) = *org;
  }
  if (*(org - 1)) {
    *(dest1++) = *(org - 1);
  }
  *dest1 = '\0';
  *dest2 = '\0';
}

int main () {
  int casos;
  char entrada[maxt],print1[maxt],print2[maxt];

  for (scanf("%d%*c",&casos); casos > 0; casos--) {
    scanf("%[^\n]%*c",entrada);
    intercalaEm2Str(print1,print2,entrada);
    printf("[%s]\n[%s]\n",print1,print2);
  }
  return 0;
}