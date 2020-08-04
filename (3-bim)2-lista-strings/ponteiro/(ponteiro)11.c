#include <stdio.h>

int temNaReferencia (char ref[], char x) {
  for (; *ref; ref++) {
    if (*ref == x) {
      return 1;
    }
  }
  return 0;
}

void seAcharNaRefExclui(char dest[], char org[], char ref[]) {
  for (; *org; org++) {
    if (!temNaReferencia(ref, *org)) {
      *(dest++) = *org;
    }
  }
  *dest = 0;
}

int main () {
  int casos;
  char referencia[51], entrada[51], print[51];
  scanf("%d %[^\n]%*c", &casos, referencia);
  for (; casos > 0; casos--) {
    scanf("%[^\n]%*c", entrada);
    seAcharNaRefExclui(print, entrada, referencia);
    printf("[%s]\n", print);
  }
  return 0;
}
