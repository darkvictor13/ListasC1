#include <stdio.h>

int temNaReferencia (char ref[],char x) {
  int count;

  for (count = 0; *ref; ref++) {
    if (*ref == x) {
      count = 1;
    }
  }
  return count;
}

void seAharNaRefExclui(char dest[],char org[],char ref[]) {
  for (; *org; org++) {
    if (!temNaReferencia(ref,*org)) {
      *(dest++) = *org;
    }
  }
  *dest = 0;
}

int main () {
  int casos;
  char referencia[51],entrada[51],print[51];
  scanf("%d %[^\n]%*c",&casos,referencia);
  for (; casos > 0; casos--) {
    scanf("%[^\n]%*c",entrada);
    seAharNaRefExclui(print,entrada,referencia);
    printf("[%s]\n",print);
  }
  return 0;
}