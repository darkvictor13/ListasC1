#include <stdio.h>
#include <string.h>

#define maxt 51

int temNaReferencia (char ref[],char x) {
  int count;

  for (count = 0; *ref; ref++) {
    if (*ref == x) {
      count = 1;
    }
  }
  return count;
}

void separaEm2Str(char dest1[],char dest2[],char ref[],char org[]) {
  for (; *org; org++) {
    if (temNaReferencia(ref,*org)) {
      break;
    }else {
      *(dest1++) = *org;
    }
  }
  *dest1 = '\0';

  while(temNaReferencia(ref,*org)) {
    org++;
  }

  for (; *org; org++) {
    *(dest2++) = *org;
  }
  *dest2 = '\0';
}

int main () {
  char palavra1[maxt],restante[maxt],entrada[maxt],separadores[10];
  int casos;

  scanf("%d %[^\n]%*c",&casos,separadores);

  for (; casos > 0; casos--) {
    scanf("%[^\n]%*c",entrada);
    separaEm2Str(palavra1,restante,separadores,entrada);
    printf("%s\n%s\n",palavra1,restante);
  }
  return 0;
}