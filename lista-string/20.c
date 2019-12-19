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

int contaPalavras(char str[],char ref[]) {
  int count = 1;

  for (str++; *str; str++) {
    if (!temNaReferencia(ref,*str) && temNaReferencia(ref,*(str - 1))) {
      count++;
    }
  }
  return count;
}

int main () {
  char str[maxt],referencia[maxt];
  int casos;

  scanf("%d %[^\n]%*c",&casos,referencia);

  for (; casos > 0; casos--) {
    scanf("%[^\n]%*c",str);
    printf("%d\n",contaPalavras(str,referencia));
  }
}