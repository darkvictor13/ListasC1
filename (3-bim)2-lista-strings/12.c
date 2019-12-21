#include <stdio.h>
#include <string.h>

void retiraParametro (char dest[],char org[],char r[]) {
  int tam_r = strlen(r);

  for (; *org; org++) {
    if (*r == *org) {
      if (!strncmp(org,r,tam_r)) {
        org = (org + tam_r);
        org--;
      }else {
        *dest = *org;
        dest++;
      }
    }else {
      *dest = *org;
      dest++;
    }
  }
  *dest = '\0';
}

int main () {
  char origem[51],parametro[10],destino[51];

  scanf("%[^\n]%*c",parametro);
  scanf("%[^\n]%*c",origem);

  while (strcmp(origem,"fim")) {
    retiraParametro(destino,origem,parametro);
    printf("|%s|\n",destino);
    scanf("%[^\n]%*c",origem);
  }
  return 0;
}