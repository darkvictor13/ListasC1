#include <stdio.h>
#include <ctype.h>

#define maxt 201

void primeiraLetraMaiusc(char dest[],char org[]) {
  *(dest++) = toupper(*(org++));

  for(; *org; org++,dest++) {
    if (*(org - 1) == ' ') {
      *dest = toupper(*org);
    }else {
      *dest = *org;
    }
  }
  *dest = '\0';
}

int main () {
  char destino[maxt],origem[maxt];
  int casos;

  for (scanf("%d%*c",&casos); casos > 0; casos--) {
    scanf("%[^\n]%*c",origem);
    primeiraLetraMaiusc(destino,origem);
    printf("[%s]\n",destino);
  }
  return 0;
}