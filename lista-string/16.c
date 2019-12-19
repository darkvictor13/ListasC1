#include <stdio.h>

#define maxt 51

void troca(int *a,int *b) {
  int aux = *a;
  *a = *b;
  *b = aux;
}

void permuta2a2(char dest[],char org[]) {
  for(; *org && *(org + 1); org += 2) {
    *(dest++) = *(org + 1);
    *(dest++) = *org;
  }
  if (*org) {
    *(dest++) = *org;
  }
  *dest = '\0';
}

int main () {
  int casos;
  char entrada[maxt],saida[maxt];

  for (scanf("%d%*c",&casos); casos > 0; casos--) {
    scanf("%[^\n]%*c",entrada);
    permuta2a2(saida,entrada);
    printf("[%s]\n",saida);
  }
  return 0;
}