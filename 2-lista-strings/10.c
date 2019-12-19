#include <stdio.h>
#include <string.h>
#include <ctype.h>

int segurancaDaSenha (char str[]) {
  int tam,maiusc,minusc,num,especial;
  tam = maiusc = minusc = num = especial = 0;

  if (strlen(str) > 7) {
    tam = 1;
  }

  for (; *str; str++) {
    if (isupper(*str)) {
      maiusc = 1;
    }
    if (islower(*str)) {
      minusc = 1;
    }
    if (isdigit(*str)) {
      num = 1;
    }
    if (ispunct(*str)) {
      especial = 1;
    }
  }
  return (tam + minusc + maiusc + num + especial) * 20;
}

int main () {
  char str[51];
  int casos;
  for (scanf("%d ",&casos); casos > 0; casos--) {
    scanf("%[^\n]%*c",str);
    printf("%d\n",segurancaDaSenha(str));
  }
  return 0;
}