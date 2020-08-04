#include <stdio.h>
#include <string.h>

#define maxt 51

int temNaReferencia (char ref[], char x) {
  for (; *ref; ref++) {
    if (*ref == x) {
      return 1;
    }
  }
  return 0;
}

int contaPalavras(char str[], char ref[]) {
  int count = 1;

  for (str++; *str; str++) {
    if (!temNaReferencia(ref, *str) && temNaReferencia(ref, *(str - 1))) {
      count++;
    }
  }
  return count;
}

int main () {
  char str[maxt], referencia[maxt];
  int casos;

  scanf("%d %[^\n]%*c", &casos, referencia);

  for (; casos > 0; casos--) {
    scanf("%[^\n]%*c", str);
    printf("%d\n", contaPalavras(str, referencia));
  }
}
