#include <stdio.h>

void eliminaRepetidosEmSequencia(char dest[],char org[]) {
  for (; *org; org++) {
    if (*(org - 1) != *org) {
      *(dest++) = *org;
    }
  }
  *dest = '\0';
}

int main () {
  char sem_repeticao[51],entrada[51];
  int casos;
  for (scanf("%d%*c",&casos); casos > 0; casos--) {
    scanf("%[^\n]%*c",entrada);
    eliminaRepetidosEmSequencia(sem_repeticao,entrada);
    printf("[%s]\n",sem_repeticao);
  }
  return 0;
}