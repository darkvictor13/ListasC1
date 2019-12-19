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

int procuraTodosNaRef (char str[],char ref[]) {
  int count_esta_na_ref;

  for (count_esta_na_ref = 0; *str; str++) {
    if (temNaReferencia(ref,*str)) {
      count_esta_na_ref++;
    }
  }
  return count_esta_na_ref;
}

int main () {
  int casos;
  char referencia[51],entrada[51];
  scanf("%d %[^\n]%*c",&casos,referencia);
  for (; casos > 0; casos--) {
    scanf("%[^\n]%*c",entrada);
    printf("%d\n",procuraTodosNaRef(entrada,referencia));
  }
  return 0;
}