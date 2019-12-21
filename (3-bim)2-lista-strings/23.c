#include <stdio.h>
#include <string.h>
#include <ctype.h>

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

int expressaoAritimeticaValida(char str[]) {
  for (; *str; str++) {
    if (temNaReferencia("+-*/",*str)) {
      if (!(isdigit(*(str - 1)) && isdigit(*(str + 1)))) {
        return 0;
      }
    }
  }
  return 1;
}

int main () {
  char str[maxt];

  scanf("%[^\n]%*c",str);

  while (strcmp(str,"fim")) {
    if(expressaoAritimeticaValida(str)) {
      printf("sim\n");
    }else {
      printf("nao\n");
    }

    scanf("%[^\n]%*c",str);
  }
  return 0;
}