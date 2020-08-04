#include <stdio.h>

int temNaReferencia (char ref[], char x) {
  for (; *ref; ref++) {
    if (*ref == x) {
      return 1;
    }
  }
  return 0;
}

int procuraTodosNaRef (char str[], char ref[]) {
  int count_esta_na_ref;

  for (count_esta_na_ref = 0; *str; str++) {
    if (temNaReferencia(ref, *str)) {
      count_esta_na_ref++;
    }
  }
  return count_esta_na_ref;
}

int main () {
  int casos;
  char referencia[51], entrada[51];
  scanf("%d %[^\n]%*c", &casos, referencia);
  for (; casos > 0; casos--) {
    scanf("%[^\n]%*c", entrada);
    printf("%d\n", procuraTodosNaRef(entrada, referencia));
  }
  return 0;
}
